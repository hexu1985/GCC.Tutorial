# Makefile

CP = cp
RM = rm -f
CC = gcc
CFLAGS = -Wall -g
INCLUDE = 
LDFLAGS = -ldl
LDPATH = 

PROGS =	app

.PHONY: all
all: $(PROGS) cplib
	@echo "build OK!"

.PHONY: clean
clean:
	$(RM) $(PROGS) *.o *.so
	@echo "clean OK!"

.PHONY: cplib
cplib:
	$(CP) ../lib/libmydynamiclib.so .

%.o:%.c
	$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDE)

$(PROGS): main.o
	$(CC) -o $@ $^ $(LDFLAGS) $(LDPATH)

