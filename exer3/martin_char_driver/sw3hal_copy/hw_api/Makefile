# Generic GNUMakefile

# Just a snippet to stop executing under other make(1) commands
# that won't understand these lines
ifneq (,)
This makefile requires GNU Make.
endif
#$(addprefix obj/,$(SOURCES:.cpp=.o))
PROGRAM = hw_api
C_FILES := $(wildcard src/*.c)
OBJS := $(patsubst %.c, %.o, $(C_FILES))
#CC = cc
#CFLAGS = -Wall -pedantic
#LDFLAGS =
#LDLIBS = -lm

#host: config_host $(PROGRAM)

#target: config_target $(PROGRAM)

ifeq (${ARCH},host)
CC = cc
CFLAGS = 
LDFLAGS =
LDLIBS = -lm
endif

ifeq (${ARCH},target)
CC = arm-poky-linux-gnueabi-gcc
SYSROOT = $(shell echo $(SDKTARGETSYSROOT))
CFLAGS = -march=armv7-a -marm  -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a8 --sysroot=$(SYSROOT)
LDFLAGS =
LDLIBS = -lm
endif

help:
	@echo "Build to host:       make ARCH=host all"
	@echo "Build to devkit8000: make ARCH=target all"
	@echo "Clean binaries:      make clean"
	@echo "REMEMBER TO CLEAN WHEN SWITCHING ARCH"

all: $(PROGRAM)

$(PROGRAM): .depend $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(PROGRAM) $(LDLIBS)

depend: .depend

.depend: cmd = gcc -MM -MF depend $(var); cat depend >> .depend;
.depend:
	@echo "Generating dependencies..."
	@$(foreach var, $(C_FILES), $(cmd))
	@rm -f depend

-include .depend

# These are the pattern matching rules. In addition to the automatic
# variables used here, the variable $* that matches whatever % stands for
# can be useful in special cases.
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f .depend $(OBJS)

.PHONY: clean depend
