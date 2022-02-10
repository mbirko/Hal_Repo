#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
/*	LED0, LED1, LED2 -> GPIO26, GPIO20, GPIO21
 *	BTN0, BTN1		 -> GPIO12, GPIO16
 *	Write GPIO <number> to /sys/class/gpio/export   
 *
 *	Do stuff with GPIO in path
 *	/sys/class/gpio/gpio<number>/direction
 *	/sys/class/gpio/gpio<number>/value
 */

#ifndef	BUF_SIZE
#define BUF_SIZE 10	/*Allows for 'cc -D' to override definition */
#endif

int main()
{
	int fd; /* file descriptor 
	(value is 0=std-input, 1=std-output, 2=std-error) */
	
	int num_read, num_write;
	char buf[BUF_SIZE];

	fd = open("/sys/class/gpio/export", O_WRONLY);
	for	(int i = 0; i < 3; i++)
	{
		// open export file to enable gpio OBS readonly	
		fd = open("/sys/class/gpio/export", O_WRONLY);
		
		// check if file open correct
		if (fd == -1){
		printf("Failed to open file: export with err: %s \n\r", strerror(errno));
		return -1;
		}
		
	}	
	// check if file open correct
	if (fd == -1){
		printf("Failed to open file: export with err: %s \n\r", strerror(errno));
		return -1;
	}
	//enable gpio26 by writing 26 to export 
	buf[0] = '2';
	buf[1] = '6';
	num_write = write(fd, buf, 2);
	close(fd);

	// open direction file to set pin as output	
	fd = open("/sys/class/gpio/gpio26/direction", O_RDWR);
	// check if file open correct
	if (fd == -1){
		printf("Failed to open file: direction with err: %s \n\r", strerror(errno));
		return -1;
	}
	//set gpio26 to output 
	buf[0] = 'o';
	buf[1] = 'u';
	buf[2] = 't';
	num_write = write(fd, buf, 3);
	close(fd);
	
	// open value file to set pin as output	
	fd = open("/sys/class/gpio/gpio26/value", O_RDWR);
	// check if file open correct
	if (fd == -1){
		printf("Failed to open file: value with err: %s \n\r", strerror(errno));
		return -1;
	}
	
	while(1)
	{
		//turn on gpio26 by writing 1 to value 
		buf[0] = '1';
		num_write = write(fd, buf, 1);
		sleep(1);
		// turn off gpio26 by writing 0 to value
		buf[0] = '0';
		num_write = write(fd, buf, 1);
		sleep(1);
	}	
	close(fd);
	return 1;
}


