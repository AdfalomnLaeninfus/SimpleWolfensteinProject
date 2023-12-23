PROJ_NAME:= Wolfstein

CC := gcc
CFLAGS := -Wall -O2 -Iinclude

SRC_DIR := src
BUILD_DIR := build

SOURCES := main.c $(wildcard $(SRC_DIR)/*.c)
OBJECTS := $(SOURCES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
OUTPUT := $(BUILD_DIR)/$(PROJ_NAME)
INCLUDES := -lSDL2

all: $(OUTPUT)

$(OUTPUT): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^  $(INCLUDES)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean