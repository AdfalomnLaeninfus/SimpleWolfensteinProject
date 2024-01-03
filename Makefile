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


ifeq ($(OS),Windows_NT)
    RM=DEL /Q /S /F
    OUTPUT=$(BUILD)\$(TARGET).exe
else
    RM=rm -f
    OUTPUT=$(BUILD)/$(TARGET)
endif


all: $(TARGET)

$(TARGET):
	$(CC) main.c $(SRCS) $(CFLAGS) -o $(OUTPUT) $(INCLUDES)

run:
	$(OUTPUT)

clean:
	$(RM) $(OUTPUT)
