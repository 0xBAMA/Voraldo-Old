CC=g++

MAKE_EXE=-o exe

CFLAGS=-O2 -L/usr/X11R6/lib -lm -lpthread -lX11 -std=c++11

output:	./includes/voraldo/V3.cc ./includes/voraldo/V3.h main.cc
	clear
	$(CC) $(MAKE_EXE) main.cc ./includes/voraldo/V3.cc $(CFLAGS)

go:
	./exe