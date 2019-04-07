.PHONY=addDir all clean

CC=g++
CFLAGS=-Wall -c -Iinclude/
EFLAGS=-Llib/ -lsfml-system -lsfml-window -lsfml-graphics

SRC=src/
BUILD=build/

SOURCE1=$(SRC)main.cpp
SOURCE2=$(SRC)mainmenu.cpp

OBJ1T=$(subst $(SRC),$(BUILD),$(SOURCE1))
OBJ1=$(OBJ1T:.cpp=.o)

OBJ2T=$(subst $(SRC),$(BUILD),$(SOURCE2))
OBJ2=$(OBJ2T:.cpp=.o)

EXECUTABLE=bin/main

all: addDir $(EXECUTABLE) clean

addDir:
	mkdir -p build/ bin/

$(EXECUTABLE): $(OBJ1) $(OBJ2)
	$(CC) $^ $(EFLAGS) -o $@

$(OBJ1): $(SOURCE1)
	$(CC) $< $(CFLAGS) -o $@

$(OBJ2): $(SOURCE2)
	$(CC) $^ $(CFLAGS) -o $@

clean:
	rm -rf */*.o