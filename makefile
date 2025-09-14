# All are currently debug builds

CC = gcc
CFLAGS = -g

SRC = $(wildcard src/*.c)
BIN = $(patsubst src/%.c,build/%, $(SRC))

all: $(BIN)

build/%: src/%.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f build/*