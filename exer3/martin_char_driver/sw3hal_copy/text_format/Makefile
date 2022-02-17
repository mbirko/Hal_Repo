CC = gcc

all: 
	gcc -o my_formatter my_formatter.c formatter.c txt_formatter.c html_formatter.c

rpizw:
	arm-rpizw-gcc -o my_formatter_rpizw my_formatter.c formatter.c txt_formatter.c html_formatter.c

run: 
	./my_formatter first second

clean:
	rm -f *.o ooc
