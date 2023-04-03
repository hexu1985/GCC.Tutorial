
RM = rm -f
AR = ar rcs
CREATE_SO = gcc -shared
CC = gcc
CFLAGS = -fPIC -Wall -g -DNDEBUG 
INCLUDES = 
VPATH = 

SOURCES = $(shell ls *.c)
OBJECTS = $(SOURCES:%.c=%.o)
STATICLIB = libmystaticlib.a
DYNAMICLIB = libmydynamiclib.so

all: $(DYNAMICLIB) $(STATICLIB)
	@echo "DYNAMICLIB = $(DYNAMICLIB)" 
	@echo "STATICLIB = $(STATICLIB)" 

.PHONY: clean
clean:
	$(RM) $(DYNAMICLIB) $(STATICLIB) $(OBJECTS)

$(OBJECTS): %.o: %.c
	$(CC) -o $@ -c $(CFLAGS) $(INCLUDES) $<

$(STATICLIB): first.o second.o third.o fourth.o
	$(AR) $(STATICLIB) $^

$(DYNAMICLIB): $(STATICLIB) mydynamiclibshell.o
	$(CREATE_SO) -o $(DYNAMICLIB) $^ $(LDPATH) $(LDFLAGS)
