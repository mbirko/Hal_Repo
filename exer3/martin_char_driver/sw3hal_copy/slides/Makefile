# FILE: Makefile (WITH CAPITAL M!!)
obj-m := hello.o init_exit.o init_error_goto.o init_exit_cdev.o
ccflags-y := -std=gnu99 -Wno-declaration-after-statement -Werror

# If KERNELDIR is not set by an environment variable 
ifeq ($(KERNELDIR),)
        # Assume the source tree is where the running kernel was built
        KERNELDIR = ~/sources/rpi-5.4.83
endif

ifeq ($(CCPREFIX),)
	CCPREFIX = arm-poky-linux-gnueabi-
endif

ifeq ($(CCARCH),)
	CCARCH = arm
endif


all default: modules
install: modules_install

modules modules_install help clean:
	$(MAKE) ARCH=$(CCARCH) CROSS_COMPILE=$(CCPREFIX) -C $(KERNELDIR) M=$(shell pwd) $@
