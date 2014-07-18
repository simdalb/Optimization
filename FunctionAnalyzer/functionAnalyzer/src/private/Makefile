
include ../../../makefile.inc

OBJECTS := CFunctionAnalyzer.o
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

CFunctionAnalyzer.o: ../CFunctionAnalyzer.hpp
CFunctionAnalyzer.o: ../../gridOptimizer/src/CGridOptimizer.hpp
CFunctionAnalyzer.o: ../../gridOptimizer/api/IGridOptimizer.hpp
CFunctionAnalyzer.o: ../../gridOptimizer/api/IGridPoint.hpp
CFunctionAnalyzer.o: ../../gridOptimizer/src/./CGridPoint.hpp
CFunctionAnalyzer.o: ../../gridOptimizer/src/./../src/CGridPoint.hpp
CFunctionAnalyzer.o: ../../gridOptimizer/src/./../src/CGridConfig.hpp
CFunctionAnalyzer.o: ../../gridOptimizer/src/./CGridConfig.hpp
