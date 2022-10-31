COMPILER = g++
COMPILER_FLAGS = -Wall -std=c++17
PROGRAM_NAME = main
CPP_FILES = main.cpp 

build:
	$(COMPILER) $(COMPILER_FLAGS) $(CPP_FILES) -o $(PROGRAM_NAME)

run: 
	./$(PROGRAM_NAME)

clean:
	rm -f $(PROGRAM_NAME) *.o