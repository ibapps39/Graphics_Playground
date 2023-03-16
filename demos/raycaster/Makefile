CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c17 
LDFLAGS=-L/opt/homebrew/lib
LDLIBS=-lm -lpthread -lglfw -framework OpenGL

ifdef USE_GLU
LIBS += -lGLU
endif

INCLUDE_PATHS = -I/opt/homebrew/include

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
