/*
 ============================================================================
 Name        : hw_api_tester.c
 Author      : PHM
 Version     :
 Description :
 Usage       : hw_api <path_to_device_or_sample_file>
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "temp_sensor.h"
#include <string.h>

int main(int narg, char *argp[]) {

  temp_sensor *sensor1 = NULL;

  /* Extract call parameters and instantiate accodringly */

  if (narg >= 2){
    if (strcmp(argp[1], "virt")==0)
      {
      puts("Using the virtual sensor");
      sensor1 = temp_sensor_new(VIRT, NULL);
      }
    else if (strcmp(argp[1], "sample")==0) {
      if (narg == 3 )
        {
        puts("Using the sampling sensor");
	sensor1 = temp_sensor_new(SAMPLE, argp[2]);
        }
      else {
        puts("Missing sample file, usage: hw_api sample <file>\n");
        return 0;
      }
    }
    else if (strcmp(argp[1], "lm75")==0)
      {
      puts("Using the LM75 sensor");
      sensor1 = temp_sensor_new(LM75, NULL);
      }
    else
      exit;
  }
  else {
    puts("Missing parameters, usage: hw_api <virt/sample/lm75> \n");
    return 0;
  }

	printf("Temperature: %f\n", sensor1->getTempC(sensor1));
	printf("Temperature: %f\n", sensor1->getTempC(sensor1));
	printf("Temperature: %f\n", sensor1->getTempC(sensor1));
	printf("Temperature: %f\n", sensor1->getTempC(sensor1));
	printf("Temperature: %f\n", sensor1->getTempC(sensor1));

	printf("Status: %x\n", sensor1->getTempStatus(sensor1));
	printf("Status: %x\n", sensor1->getTempStatus(sensor1));
	printf("Status: %x\n", sensor1->getTempStatus(sensor1));
	printf("Status: %x\n", sensor1->getTempStatus(sensor1));

	sensor1->disable(sensor1);

	temp_sensor_delete(sensor1);

	puts("Testing Completed!");

	return EXIT_SUCCESS;
}
