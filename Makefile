CC=gcc
CFLAGS=-Wall \
		-O2 \
		-pipe \
		-fpic \
		-flto \
		-march=native \
		-DNDEBUG \
		-Iincludes \
		-funroll-loops \
		-ftree-vectorize \
		-finline-functions

TARGET=Wolfenstein

SRC=src
SRCS=$(wildcard $(SRC)/*.c)
BUILD=build
INCLUDES=-lm -lSDL2

OUTPUT=$(BUILD)\$(TARGET)

ifeq ($(OS),Windows_NT)
    RM=DEL /Q /S /F
else
    RM=rm -f
endif


all: $(TARGET)

$(TARGET):
	$(CC) main.c $(SRCS) $(CFLAGS) -o $(OUTPUT) $(INCLUDES)

run:
	$(OUTPUT)
