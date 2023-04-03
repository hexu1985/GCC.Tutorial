
RM = rm -f
AR = ar rcs
CC = gcc
CFLAGS = -fPIC -Wall -g -DNDEBUG 
INCLUDES = 
VPATH = 

SOURCES = $(shell ls *.c)
OBJECTS = $(SOURCES:%.c=%.o)
STATICLIB = libmystaticlib.a

all: $(STATICLIB)
	@echo "STATICLIB = $(STATICLIB)" 

.PHONY: clean
clean:
	$(RM) $(STATICLIB) $(OBJECTS)

$(OBJECTS): %.o: %.c
	$(CC) -o $@ -c $(CFLAGS) $(INCLUDES) $<

$(STATICLIB): $(OBJECTS)
	$(AR) $(STATICLIB) $(OBJECTS)

