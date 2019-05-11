.PHONY=addDir all clean

CC=g++
CFLAGS=-Wall -c -Iinclude/
EFLAGS=-Llib/ -lsfml-system -lsfml-window -lsfml-graphics

SRC=src/
BUILD=build/

SOURCE1=$(SRC)main.cpp
SOURCE2=$(SRC)mainmenu.cpp
SOURCE3=$(SRC)settings.cpp
SOURCE4=$(SRC)rules.cpp
SOURCE5=$(SRC)gamewindow.cpp
SOURCE6=$(SRC)textbox.cpp

OBJ1T=$(subst $(SRC),$(BUILD),$(SOURCE1))
OBJ1=$(OBJ1T:.cpp=.o)

OBJ2T=$(subst $(SRC),$(BUILD),$(SOURCE2))
OBJ2=$(OBJ2T:.cpp=.o)

OBJ3T=$(subst $(SRC),$(BUILD),$(SOURCE3))
OBJ3=$(OBJ3T:.cpp=.o)

OBJ4T=$(subst $(SRC),$(BUILD),$(SOURCE4))
OBJ4=$(OBJ4T:.cpp=.o)

OBJ5T=$(subst $(SRC),$(BUILD),$(SOURCE5))
OBJ5=$(OBJ5T:.cpp=.o)

OBJ6T=$(subst $(SRC),$(BUILD),$(SOURCE6))
OBJ6=$(OBJ6T:.cpp=.o)


EXECUTABLE=bin/main

all: addDir $(EXECUTABLE)

remake: clean all

addDir:
	mkdir -p build/ bin/

$(EXECUTABLE): $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) $(OBJ6)
	$(CC) $^ $(EFLAGS) -o $@

$(OBJ1): $(SOURCE1)
	$(CC) $< $(CFLAGS) -o $@

$(OBJ2): $(SOURCE2)
	$(CC) $^ $(CFLAGS) -o $@

$(OBJ3): $(SOURCE3)
	$(CC) $^ $(CFLAGS) -o $@

$(OBJ4): $(SOURCE4)
	$(CC) $^ $(CFLAGS) -o $@

$(OBJ5): $(SOURCE5)
	$(CC) $^ $(CFLAGS) -o $@

$(OBJ6): $(SOURCE6)
	$(CC) $^ $(CFLAGS) -o $@

clean:
	rm -rf */*.o
