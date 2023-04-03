# Makefile

RM = rm -f
CC = gcc
CFLAGS = -Wall -g
INCLUDE = -I../lib
LDFLAGS = -Wl,-rpath,'$$ORIGIN/../lib' -Wl,--enable-new-dtags -lmydynamiclib
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

