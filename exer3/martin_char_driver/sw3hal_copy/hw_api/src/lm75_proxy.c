/** @file lm75_proxy.c
 *  @brief A temperature proxy for the LM75 sensor
 *
 *  This version of the lm75 proxy is INCOMPLETE. I2cdev
 *  file must to be opened and used to retrieve the
 *  temperature from the lm75 device. The temperature must
 *  be converted to degC with 1 or 0.5 degC resolution
 *
 *  Note that this module uses doxygen-style comments
 *
 *  @author phm@ase.au.dk
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include "temp_sensor.h"

/* Excerpt from i2c-dev.h */
#define I2C_SLAVE       0x0703  /* Set slave addr IOCTL cmd ID */

/* Local Definitions */
#define LM75_I2C_ADDR	0x48    /* Devkit8000 Add-On Board LM75 Address */
#define LM75_I2C_BUS	3

/* -- Private Data and Methods -- */








/* -- Public Methods -- */

/** @brief Get temperature from LM75 sensor
 *  @param cthis Pointer to context
 *  @return Temperature in degC (float) in 0.5 degC resolution
 */
static float lm75_getTempC(temp_sensor *cthis){
  return (float)(56.4);
}

/** @brief Destructor
 *  @param cthis Pointer to context
 */
static void lm75_proxy_release(temp_sensor *cthis){
  /* Release ressources */
}

/** @brief Desctuctor
 *  @param cthis Pointer to context
 *  @param device Pointer to device (may be NULL)
 */
int lm75_proxy_init(temp_sensor *cthis, void *device){
  int fp = 0;
  int err = 0;
	
  /* 
   * Assign Public Methods
   */

  
  /* 
   * Open Linux i2c-dev device 
   */


  /* 
   * Set I2C Device address
   * Uses ioctl system call to configure
   * i2cdev driver to use a specific i2c
   * address. This is the old way used
   * before sysfs and attributes 
   */
  err = ioctl(fp, I2C_SLAVE, LM75_I2C_ADDR);
  if (err < 0) {
    printf("LM75 device not found at addr:%x\n", LM75_I2C_ADDR);
    //close(fp);
    return err;
  }

  /* 
   * Create and init LM75 data struct
   */


  /* 
   * Return
   */
  return err;
}
