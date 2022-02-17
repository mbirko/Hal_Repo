SRC=blink_all_led.c 
EXE=blink_all_led 
 
all: $(EXE) 
 
run: clean all 
	clear 
	@echo "🚀 Executing..." 
	./$(EXE) 
 
$(EXE): $(SRC) 
	@echo "🚧 Building..." 
	arm-rpizw-gcc -o $(EXE) $(SRC) 
 
clean: 
	@echo "🧹 Clearing..." 
	-rm $(EXE) 

