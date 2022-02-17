#include <stdio.h>
#include <stdlib.h>
#include "formatter.h"
#include <string.h>
/*
 * my_formatter.c
 *
 *  Created on: 12/09/2016
 *      Author: phm
 */

extern void txt_init(formatter *cthis, char *pathname);
extern void html_init(formatter *cthis, char *pathname);

int main(int narg, char *argp[]) {
	char default_header[]="This is my default Header";
	char default_body[]="This is my default Body";
	char default_format[]="txt";
	char *header, *body, *format;

 	/* Decoding of user parameters */
  	if (narg == 2){         // text_formatter <body text>
    	header = default_header;
    	body = argp[1];
		format = default_format;
  	}
  	else if (narg == 3){    // my_formatter <header text> <body text>
    	header = argp[1];
    	body = argp[2];
		format = default_format;
  	}
	else if (narg == 4){
		header = argp[1];
    	body = argp[2];
		format = argp[3];	
	}	
    else {                  // text_formatter
    	puts("my_formatter <header text> <body text> <format style>");
    	return 0;
  	}

	puts("Running my formatting tool!");

	formatter text; // Allocation of objects
	
	if(!(strcmp(format, "html"))){
		formatter_init(&text, html_init, "/www/pages/index.html"); // Current TTY device
	} 
	else if(!(strcmp(format, "txt"))){
		formatter_init(&text, txt_init , "/dev/tty"); // Current TTY device
	}

	/* Use of formatters methods */
  	text.preamble(&text, "Start of formatted text");
 	text.header(&text, header);
	text.body(&text, body);
  	text.postamble(&text, "thanks folks");
	
  	formatter_release(&text);

  	puts("Formatting completed!");
  	return 0;
}

