
RM = rm -f
CREATE_SO = g++ -shared
CC = g++
CFLAGS = -fPIC -Wall -g -DNDEBUG 
INCLUDES = -I../exports
LDFLAGS = 
LDPATH =
VPATH = 

SOURCES = $(shell ls *.c)
OBJECTS = $(SOURCES:%.c=%.o)
DYNAMICLIB = libdefaultvisibility.so

all: $(DYNAMICLIB)
	@echo "DYNAMICLIB = $(DYNAMICLIB)" 

.PHONY: clean
clean:
	$(RM) $(DYNAMICLIB) $(OBJECTS)

$(OBJECTS): %.o: %.c
	$(CC) -o $@ -c $(CFLAGS) $(INCLUDES) $<

$(DYNAMICLIB): $(OBJECTS)
	$(CREATE_SO) -o $(DYNAMICLIB) $(OBJECTS) $(LDPATH) $(LDFLAGS)

