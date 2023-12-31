PROJ_NAME:= Wolfenstein

CC := gcc
CFLAGS := -Iinclude

SRC_DIR := src
BUILD_DIR := build

SOURCES := main.c src/*.c
OUTPUT := $(BUILD_DIR)/$(PROJ_NAME)
LIBS := -lSDL2 -lm

$(OUTPUT):
	$(CC) $(SOURCES) $(CFLAGS) -o $@ $^ $(LIBS)

BUILD_DIR := build
BUILD_DIR := $(subst /,$(SEPARETOR),$(BUILD_DIR))

clean:
	DEL /Q build\*.o

all: $(OUTPUT)

run:
	$(BUILD_DIR)\$(PROJ_NAME)

.PHONY: all clean
