# Makefile

RM = rm -f
CXX = g++
CXXFLAGS = -Wall -g
INCLUDE = -I../lib
LDFLAGS = -lmydynamiclib
LDPATH = -L../lib

PROGS =	app

.PHONY: all
all: $(PROGS)
	@echo "build OK!"

clean:
	$(RM) $(PROGS) *.o
	@echo "clean OK!"

%.o:%.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS) $(INCLUDE)

$(PROGS): main.o
	$(CXX) -o $@ $^ $(LDFLAGS) $(LDPATH)

