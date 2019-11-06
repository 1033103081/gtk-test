SRCS = $(wildcard *.c)
PROGS =$(patsubst %.c, %, $(SRCS))
CC= gcc
CFLAGS=-std=c99

all: $(PROGS)

%:%.c
	gcc $< `pkg-config --cflags --libs gtk+-3.0` -Wall -o $@

clean:
	rm $(PROGS)
