# Kernel Interface Notes 

## from exersice1 


### SSH into the Pi, by shell scripts
```sh
#!/bin/bash
echo shh into root@10.9.8.2
shh root@10.9.8.2

```

### scp into the pi, by shell scripts
```sh
#!/bin/bash
echo send $1 to $2 on RsPi0
scp $1 root@10.9.8.2:$2
```
## Interfaceing with GPIO from the terminal

### CMDs to interface with GPIO
CMD 
''' 
echo <gpio nummer> > /sys/class/gpio/export  
'''
Readning direction and values from GPIO 
''' 
cat /sys/class/gpio/gpio<gpio nummer>/direction  
cat /sys/class/gpio/gpio<gpio nummer>/value 
'''

### Script to setup btns and leds

### Noteble GPIOs on HAT
LED0 - GPIO26
LED1 - GPIO20
LED2 - GPIO21

BTN0 - GPIO12
BTN1 - GPIO16

## Using files! 
### open
```c
    int fd = open("path", falgs)
```
Genneral tip, dont have the file open in another program. 
####  flags 
| flag | meaing | 
|------|--------|
| O_RDONLY | read only | 
| O_WRONLY | write only |
| O_RDWR   | read wrigt |

### read
```c
    char buffer[buffer_size];
    int bytes_read;
    bytes_read = read(fd, buffer, read_size_request);
```
The reading will be saved in the buffer. 
the read_size_request states how many bytes there is to be read
the bytes_read tells how many bytes where read.
#### key values
- -1 = failed to read
- 0 = end of file reached

### write 
```
    char buffer[buffer_size] = {"message"};
    int bytes_read;
    bytes_written = read(fd, buffer, write_size_request);
```

