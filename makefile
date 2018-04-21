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
OBJS = $(addprefix $(bindir)/,alive.o future.o print.o)

#STILL GOING TO ADD MORE OBJECTS

# Phony targets (for more information, visit https://www.gnu.org/software/make/manual/make.html#Phony-Targets)

.PHONY: clean cleanbin cleandat
.PHONY: all main build

# Use "make" to compile everything
all: main build

# Use "make main" to compile only the main
main: game

# Use "make build" to build all modules
build: alive future print

# Use "make alive" to build only the alive module
alive: $(bindir)/alive.o


#/-------THERE MAY BE NO CELL MODULE-----------------------/
# Use "make cell" to build only the cell module
#cell: $(bindir)/cell.o
#/------------------------------------------------/


# Use "make future" to build only the future module
future: $(bindir)/future.o

# Use "make print" to build only the print module
print: $(bindir)/print.o

# Compiles the main
game: $(srcdir)/main.cpp $(OBJS)
	mkdir -p $(bindir)
	$(CC) $(CFLAGS) $^ -o $@

# Builds only the alive module
$(bindir)/alive.o: $(srcdir)/alive.cpp $(incdir)/alive.hpp
	mkdir -p $(bindir)
	$(CC) $(CFLAGS) -c $< -o $@


#/--------------THERE MAY BE NO CELL MODULE------------------/
# Builds only the cell module
#$(bindir)/cell.o: $(srcdir)/cell.cpp $(incdir)/cell.hpp
#	mkdir -p $(bindir)
#	$(CC) $(CFLAGS) -c $< -o $@
#/-------------------------------------------/


# Builds only the future module
$(bindir)/future.o: $(srcdir)/future.cpp $(incdir)/future.hpp $(incdir)/alive.hpp
	mkdir -p $(bindir)
	$(CC) $(CFLAGS) -c $< -o $@

# Builds only the print module
$(bindir)/print.o: $(srcdir)/print.cpp $(incdir)/print.hpp
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


