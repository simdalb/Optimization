
include ../../../makefile.inc

OBJECTS := CMyFunction1.o
SOURCES := $(OBJECTS:%.o=%.cpp)

all: $(OBJECTS)

$(OBJECTS): %.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f *.bak
	@for obj in $(OBJECTS); do \
		rm -f $$obj; \
	done

depend:
	makedepend $(SOURCES)
# DO NOT DELETE

CMyFunction1.o: ../CMyFunction1.hpp
