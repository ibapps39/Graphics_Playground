CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c99
LDFLAGS=-L/opt/homebrew/opt/sdl2/lib
LDLIBS=-lm -lpthread -lSDL2 -framework OpenGL
INCLUDE_PATHS = -I/opt/homebrew/opt/sdl2/include

CFLAGS += $(INCLUDE_PATHS)
LDFLAGS += $(LDLIBS)
SRC=$(wildcard *.c)
OBJ=$(patsubst %.c,%.o,$(SRC))
BIN=raycaster

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BIN)

.PHONY: all clean
