#define I2C_SLAVE 0x0703
#include <errno.h>
#include <stdio.h>
#include <stdint.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <linux/i2c-dev.h>

// Export a gpio pin
void gpio_enable(char* gpio_no){
	// open export file to enable gpio OBS readonly	for export
	int fd; 
    fd = open("/sys/class/gpio/export", O_WRONLY);
		
	// check if file open correct
	if (fd == -1){
		printf("Failed to open file: export with err: %s \n\r", strerror(errno));
	}
	//enable gpio by writing to export, this genereates a folder for the selected gpio 
	write(fd, gpio_no, strlen(gpio_no));
    close(fd);
}
// Change direction of GPIO (has to include path to /direction)
void gpio_direction(char* path_gpio, char* dir){
	// open direction file to set pin direction	
	int fd; 
    fd = open(path_gpio, O_WRONLY);
	
    // check if file open correct
	if (fd == -1){
		printf("Failed to open file: direction with err: %s \n\r", strerror(errno));
	}
    // write direction and close file
	write(fd, dir, strlen(dir));
	close(fd);
}
// Change value of GPIO (has to include path to /value)
void gpio_value(char* path_gpio, char* value){
	// open direction file to set pin as output	
	int fd; 
    fd = open(path_gpio, O_WRONLY);
	
    // check if file open correct
	if (fd == -1){
		printf("Failed to open file: value with err: %s \n\r", strerror(errno));
	}
    // write value and close file
    write(fd, value, strlen(value));
	close(fd);
}
// convert reading frin LM75 to temperature in decimal
float convertToTemp(char firstByte, char  secondByte)
{
    // First byte assigned to unsign 16 bit int
    uint16_t out = firstByte; 
    // Moving eigth zeros in from the right side
    out = out << 8; 
    // Secondbyte ored with 0090h gets zeroes on 7 LSB's
    out = out + (secondByte & 0x0080); 
    // Moving 7 zeros in from the left to push the 9 bits to the LSB
    out = out >> 7; 
    // Checking if the ninth bit is 1 cuz then its negative number
    if ((out & (0x0100))) 
    {
        // Converting 2nd Comp, with mask on the 9 bits
        out = (((~out) & 0b0000000111111111))+1; 
        // Returning the temp divided by two since it increments with half a degr
        return ((float)out/2.0) * -1; 
    }     
    return (float)out/2.0;
}
// read temperature from lm75
float readTemp(unsigned long addr, unsigned long adapter_no){
	int file;
	int output;
  	char filename[20];
	char buf[2];
  	
	// Open file with adaptor number	
	snprintf(filename, 19, "/dev/i2c-%d", adapter_no);
  	file = open(filename, O_RDONLY);
  	if (file < 0) {
		printf("Failed with err: %s \n\r", strerror(errno));
    	return 1;
  	}
	
  	if (ioctl(file, I2C_SLAVE, addr) < 0) {
		printf("Failed with err: %s \n\r", strerror(errno));
    	return 2;
  	}
  	
	read(file, buf, 2);
	close(file);		
	return convertToTemp(buf[0],buf[1]);
}

int main()
{
    // export the gpio numbers for the LED's
    gpio_enable("26");
    
    // set direction to out for LED's
    gpio_direction("/sys/class/gpio/gpio26/direction", "out");
    double temperature;

	while(1)
	{
		// read and save temperature
		temperature = readTemp(0x48, 2);
	   	// print temperature to stdout	
		printf("Temp is = %d \n\r", temperature);
			
		// evaluate on temperature reading
		if(temperature >= 25){
			// turn on LED0 if temperature is over 25	
			gpio_value("/sys/class/gpio/gpio26/value", "1");
		}
		else if(temperature < 25){
			// turn off LED0 if temperature is under 25	
			gpio_value("/sys/class/gpio/gpio26/value", "0");
		}
		// wait for 1 sec	
		sleep(1);
	}	
	return 1;
}



