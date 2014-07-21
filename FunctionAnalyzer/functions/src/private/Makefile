
include ../../../makefile.inc

SOURCES := CMyFunction1.cpp

OBJECTS := $(SOURCES:.cpp=.o)

$(OBJECTS): $(SOURCES)
	$(CC) -c $(CFLAGS) $< -o $@

all: $(OBJECTS)

clean:
	rm -f *.bak
	rm -f $(OBJECTS)

depend:
	makedepend $(SOURCES)
# DO NOT DELETE

CMyFunction1.o: ../CMyFunction1.hpp
