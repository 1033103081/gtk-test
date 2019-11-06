#SRCS = $(wildcard *.c)
#PROGS =$(patsubst %.c, %, $(SRCS))
CC ?= gcc


default:
	$(CC) *.c -I. `pkg-config --cflags --libs gtk+-3.0` -lsqlite3 -Wall -o main

clean:
	-rm main
