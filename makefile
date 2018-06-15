#link exemplo do makefile 
#https://stackoverflow.com/questions/30573481/path-include-and-src-directory-makefile/30602701

EXE = teste

SRC_DIR = src
OBJ_DIR = obj
CC = g++
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CPPFLAGS += -Iinclude
CFLAGS += -ansi -Wall -pedantic -O0 -g -ansi -Wpedantic -pg -std=c++14  
LDFLAGS += -Llib
LDLIBS += -lm

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(EXE) *.gch
