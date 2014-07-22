
include ../../../../makefile.inc

SOURCES := CGridConfig.cpp CGridOptimizer.cpp CGridPoint.cpp

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

CGridConfig.o: ../CGridConfig.hpp
CGridOptimizer.o: ../CGridOptimizer.hpp ../../api/IGridOptimizer.hpp
CGridOptimizer.o: ../../api/IGridPoint.hpp ../../src/CGridConfig.hpp
CGridOptimizer.o: .././CGridPoint.hpp ../././CGridConfig.hpp
CGridOptimizer.o: .././../api/IGridPoint.hpp
CGridPoint.o: ../CGridPoint.hpp ../././CGridConfig.hpp
CGridPoint.o: .././../api/IGridPoint.hpp
