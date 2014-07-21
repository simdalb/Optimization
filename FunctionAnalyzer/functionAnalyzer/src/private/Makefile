
include ../../../makefile.inc

SOURCES := CFunctionAnalyzer.cpp

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

CFunctionAnalyzer.o: ../CFunctionAnalyzer.hpp
CFunctionAnalyzer.o: ../../gridOptimizer/src/CGridOptimizer.hpp
CFunctionAnalyzer.o: ../../gridOptimizer/api/IGridOptimizer.hpp
CFunctionAnalyzer.o: ../../gridOptimizer/api/IGridPoint.hpp
CFunctionAnalyzer.o: ../../gridOptimizer/src/./CGridPoint.hpp
CFunctionAnalyzer.o: ../../gridOptimizer/src/././CGridConfig.hpp
CFunctionAnalyzer.o: ../../gridOptimizer/src/./../api/IGridPoint.hpp
