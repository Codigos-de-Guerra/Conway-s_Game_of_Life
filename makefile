# Makefile conventions

SHELL = ~/bin/zsh

# Directories

srcdir = ./src
incdir = ./include
bindir = ./bin
datdir = ./data

# Macros
CC = g++
CFLAGS = -Wall -std=c++11 -lm -I$(incdir)
RM = rm -v
OBJS = $(addprefix $(bindir)/,processos.o)

#STILL GOING TO ADD MORE OBJECTS

# Phony

.PHONY: clean cleanbin
.PHONY: all main build

# Use "make" to compile everything
all: build main

# Use "make main" to compile only the main
main: analise

# Use "make build" to build all modules
build: processos

# Use "make processos" to build only the processos module
processos: $()
