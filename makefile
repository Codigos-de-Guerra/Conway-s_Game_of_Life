# Makefile conventions

#SHELL = ~/bin/bash

# Directories
srcdir = ./src
incdir = ./include
bindir = ./bin
datdir = ./data

# Macros
CC = g++
CFLAGS = -Wall -std=c++11 -lm -I$(incdir)
RM = rm -v
OBJS = $(addprefix $(bindir)/,cell.o)

#STILL GOING TO ADD MORE OBJECTS

# Phony targets (for more information, visit https://www.gnu.org/software/make/manual/make.html#Phony-Targets)

.PHONY: clean cleanbin cleandat
.PHONY: all main build

# Use "make" to compile everything
all: main build

# Use "make main" to compile only the main
main: game

# Use "make build" to build all modules
build: cell

# Use "make cell" to build only the alive module
cell: $(bindir)/cell.o

# Compiles the main
game: $(srcdir)/main.cpp $(OBJS)
	mkdir -p $(bindir)
	$(CC) $(CFLAGS) $^ -o $@

# Builds only the cell module
$(bindir)/cell.o: $(srcdir)/cell.cpp $(incdir)/cell.hpp
	mkdir -p $(bindir)
	$(CC) $(CFLAGS) -c $< -o $@

# Removes executable and objects
cleanbin:
	$(RM) $(bindir)/*
	$(RM) -r $(bindir)

# Removes data files
cleandat:
	$(RM) $(datdir)/*
	$(RM) -r $(datdir)

# Removes all objects, executables and data input and output files
clean: cleanbin cleandat
