PROJ_NAME:= Wolfstein

CC := gcc
CFLAGS := -Wall -O2 -Iinclude

SRC_DIR := src
BUILD_DIR := build

SOURCES := main.c $(wildcard $(SRC_DIR)/*.c)
OBJECTS := $(SOURCES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
OUTPUT := $(BUILD_DIR)/$(PROJ_NAME)
INCLUDES := -lSDL2

$(OUTPUT): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(INCLUDES)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

BUILD_DIR := build
BUILD_DIR := $(subst /,$(SEPARETOR),$(BUILD_DIR))

clean:
	DEL /Q build\*.o

all: $(OUTPUT)

.PHONY: all clean
