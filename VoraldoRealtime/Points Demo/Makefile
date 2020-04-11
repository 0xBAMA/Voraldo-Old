CC = g++

MAKE_EXE= -O2 -o exe -time

GL_FLAGS = -lglut -lGLEW -lGL -lGLU

CIMG_FLAGS = -L/usr/X11R6/lib -lm -lpthread -lX11 -std=c++11

all: main.cc
	$(CC) main.cc  $(MAKE_EXE) $(GL_FLAGS) $(CIMG_FLAGS)
