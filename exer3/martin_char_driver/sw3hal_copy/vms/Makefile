ifeq ($(KERNELRELEASE),)
 KERNELDIR_HOST = /lib/modules/$(shell uname -r)/build
 PWD := $(shell pwd)

help:
	@echo "Build to host:       make host"
	@echo "Build to target:     make target"
	@echo "Clean binaries:      make clean"
host:
	$(MAKE) ARCH=x86_64 CROSS_COMPILE= -C $(KERNELDIR_HOST) M=$(PWD) modules

target:
	$(MAKE) ARCH=arm CROSS_COMPILE=$(CCPREFIX) -C $(KERNELDIR) M=$(PWD) modules

clean:
		rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions modules.order Module.symvers

else
  obj-m := vms.o
endif
