SRC=lm75.c
EXE=lm75

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
