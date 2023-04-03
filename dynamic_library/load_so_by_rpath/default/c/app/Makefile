# Makefile

RM = rm -f
CC = gcc
CFLAGS = -Wall -g
INCLUDE = -I../lib
#LDFLAGS = -Wl,-R../lib -lmydynamiclib
LDFLAGS = -Wl,-rpath,../lib -lmydynamiclib
LDPATH = -L../lib

PROGS =	app

.PHONY: all
all: $(PROGS)
	@echo "build OK!"

clean:
	$(RM) $(PROGS) *.o
	@echo "clean OK!"

%.o:%.c
	$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDE)

$(PROGS): main.o
	$(CC) -o $@ $^ $(LDFLAGS) $(LDPATH)

