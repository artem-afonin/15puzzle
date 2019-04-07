.PHONY=addDir all clean

CC=g++
CFLAGS=-Wall -c -Iinclude/
EFLAGS=-Llib/ -lsfml-system -lsfml-window -lsfml-graphics
SOURCE=src/main.cpp
OBJ_TEMP=$(subst src/,build/,$(SOURCE)) ### Change src/ => build/ ###
OBJ=$(OBJ_TEMP:.cpp=.o) ### Change .cpp => .o ###
EXECUTABLE=bin/main

all: addDir $(EXECUTABLE) clean

addDir:
	mkdir -p build/ bin/

$(EXECUTABLE): $(OBJ)
	$(CC) $^ $(EFLAGS) -o $@

$(OBJ): $(SOURCE)
	$(CC) $^ $(CFLAGS) -o $@

clean:
	rm -rf *.*.o