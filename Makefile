PROJ_NAME:= Wolfstein

CC := gcc
CFLAGS := -Wall -O2 -Iinclude

SRC_DIR := src
BUILD_DIR := build

SOURCES := main.c $(wildcard $(SRC_DIR)/*.c)
OBJECTS := $(SOURCES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
OUTPUT := $(BUILD_DIR)/$(PROJ_NAME)

all: $(OUTPUT)

$(OUTPUT): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean