
include ./makefile.inc

SUBDIRS := \
functionAnalyzer/gridOptimizer/src/private \
functionAnalyzer/src/private \
functions/src/private \

SOURCES := main.cpp

OBJECTS := $(SOURCES:.cpp=.o)

SUBDIRSOBJS := 

$(OBJECTS): $(SOURCES)
	$(CC) -c $(SOURCES) $(CFLAGS)

all: $(OBJECTS)
	@for subdir in $(SUBDIRS); do \
		cd $$subdir && $(MAKE) all; \
		cd -; \
	done
	$(CC) -o funcAn.exe $(OBJECTS) $(addsuffix /*.o,$(SUBDIRS)) $(CFLAGS)

clean:
	rm -f $(OBJECTS)
	rm -f *.bak
	rm -f *.stackdump
	rm -f main.o
	@for subdir in $(SUBDIRS); do \
		cd $$subdir && $(MAKE) clean; \
		cd -; \
	done

depend:
	makedepend $(SOURCES)
	@for subdir in $(SUBDIRS); do \
		cd $$subdir && $(MAKE) depend; \
		cd -; \
	done
# DO NOT DELETE

main.o: functionAnalyzer/src/CFunctionAnalyzer.hpp
main.o: functionAnalyzer/gridOptimizer/src/CGridOptimizer.hpp
main.o: functionAnalyzer/gridOptimizer/api/IGridOptimizer.hpp
main.o: functionAnalyzer/gridOptimizer/api/IGridPoint.hpp
main.o: functionAnalyzer/gridOptimizer/src/./CGridPoint.hpp
main.o: functionAnalyzer/gridOptimizer/src/././CGridConfig.hpp
main.o: functionAnalyzer/gridOptimizer/src/./../api/IGridPoint.hpp
main.o: functionAnalyzer/gridOptimizer/api/IGridOptimizer.hpp
main.o: functionAnalyzer/gridOptimizer/api/IGridPoint.hpp
main.o: functions/src/CMyFunction1.hpp
