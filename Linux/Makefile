LDFLAGS= -lncurses
CC = g++
CFLAGS = -O2

all: AdbNcurses

AdbNcurses:
	$(CC) adb-ncurses.cpp -o adb-ncurses $(LDFLAGS)
	echo start sudo make install :3

install:
	cp adb-ncurses /bin
	echo start adb-ncurses :3

termuxinstall:
	cp adb-ncurses ~/../usr/bin

run:
	./adb-ncurses

cpp:
	nano adb-ncurses.cpp

clear:
	rm /bin/adb-ncurses

.PHONY: clear all install run cpp termuxinstall
