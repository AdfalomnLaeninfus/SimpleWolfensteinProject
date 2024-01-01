CC=gcc
CFLAGS=-Wall \
		-O2 \
		-DNDEBUG \
		-Iincludes \
		-pipe \
		-fpic \
		-flto \
		-funroll-loops \
		-ftree-vectorize \
		-finline-functions

TARGET=Wolfenstein

SRC=src
OBJ=obj
BUILD=build
INCLUDES=-lm -lSDL2

ifeq ($(OS),Windows_NT)
    RM=DEL /Q /S /F
else
    RM=rm -f
endif

SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c,$(SRC)\\%.o,$(SRCS))

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(TARGET): $(OBJS)
	$(CC) main.c $(OBJS) $(CFLAGS) -o $(BUILD)/$(TARGET) $(INCLUDES)

run:
	$(BUILD)\$(TARGET)

clean:
	$(RM) $(OBJS) $(BUILD)\$(TARGET)
