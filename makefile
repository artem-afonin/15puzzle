.PHONY=addDir all clean remake test testlib

CC=g++
CFLAGS=-Wall -c -Iinclude/ -std=c++11
EFLAGS=-Llib/ -lsfml-system -lsfml-window -lsfml-graphics

SRC=src/
BUILD=build/
TESTSRC=test/
TESTBUILD=$(BUILD)test/
GTEST_DIR = thirdparty/googletest

SOURCE1=$(SRC)main.cpp
SOURCE2=$(SRC)mainmenu.cpp
SOURCE3=$(SRC)settings.cpp
SOURCE4=$(SRC)rules.cpp
SOURCE5=$(SRC)gamewindow.cpp
SOURCE6=$(SRC)textbox.cpp
SOURCE7=$(SRC)leaderboard.cpp
TESTSOURCE=$(TESTSRC)test.cpp

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

OBJ7T=$(subst $(SRC),$(BUILD),$(SOURCE7))
OBJ7=$(OBJ7T:.cpp=.o)

TESTOBJT=$(subst $(TESTSRC),$(TESTBUILD),$(TESTSOURCE))
TESTOBJ=$(TESTOBJT:.cpp=.o)

EXECUTABLE=bin/main
TESTEXE=bin/test

TESTLIBO=build/test/gtest-all.o
TESTLIBA=build/test/libgtest.a

all: addDir $(EXECUTABLE)

remake: clean all

addDir:
	mkdir -p build/ bin/ build/test/

$(EXECUTABLE): $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) $(OBJ6) $(OBJ7)
	$(CC) $^ $(EFLAGS) -o $@

$(OBJ1): $(SOURCE1)
	$(CC) $^ $(CFLAGS) -o $@

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

$(OBJ7): $(SOURCE7)
	$(CC) $^ $(CFLAGS) -o $@

clean:
	rm -rf build/*.o build/test/* data/playerRecords.txt

test: addDir testlib bin/test

testlib: $(TESTLIBO)
	ar -rv $(TESTLIBA) $(TESTLIBO)

$(TESTLIBO):
	$(CC) -std=c++11 -isystem ${GTEST_DIR}/include -I${GTEST_DIR} \
    -pthread -c ${GTEST_DIR}/src/gtest-all.cc -o $@

$(TESTEXE): $(TESTOBJ) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) $(OBJ6) $(OBJ7)
	$(CC) -std=c++11 -isystem ${GTEST_DIR}/include -pthread \
	$^ build/test/libgtest.a \
	$(EFLAGS) -o $@

$(TESTOBJ): $(TESTSOURCE)
	$(CC) $(CFLAGS) $^ -I $(GTEST_DIR)/include -o $@
