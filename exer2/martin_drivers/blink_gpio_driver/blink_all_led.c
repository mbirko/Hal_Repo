/* This driver can control the three LED's on RPI ASE fHAT */
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

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
		printf("Failed to open file: direction with err: %s \n\r", strerror(errno));
	}
    // write value and close file
    write(fd, value, strlen(value));
	close(fd);
}

int main()
{
    // export the gpio numbers for the LED's
    gpio_enable("26");
    gpio_enable("20");
    gpio_enable("21");
    
    // set direction to out for LED's
    gpio_direction("/sys/class/gpio/gpio26/direction", "out");
    gpio_direction("/sys/class/gpio/gpio20/direction", "out");
    gpio_direction("/sys/class/gpio/gpio21/direction", "out");
    
	while(1)
	{
        // turn on LED's
        gpio_value("/sys/class/gpio/gpio26/value", "1");
        gpio_value("/sys/class/gpio/gpio20/value", "1");
        gpio_value("/sys/class/gpio/gpio21/value", "1");
		sleep(1);
        // turn off LED's
	    gpio_value("/sys/class/gpio/gpio26/value", "0");
        gpio_value("/sys/class/gpio/gpio20/value", "0");
        gpio_value("/sys/class/gpio/gpio21/value", "0");
		sleep(1);
	}	
	return 1;
}


