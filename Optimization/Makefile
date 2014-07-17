
include ./makefile.inc

SUBDIRS := functionAnalyzer/gridOptimizer/src/private functionAnalyzer/src/private functions/src/private
LIBRARY := gridOptimizer 
OBJS    := functionAnalyzer/src/private/CFunctionAnalyzer.o functions/src/private/CMyFunction1.o
SOURCES := main.cpp
OBJECTS := main.o

$(OBJECTS): $(SOURCES)
	$(CC) -c $(SOURCES) $(CFLAGS)

all: $(OBJECTS) $(LIBRARY) $(OBJS)
	@for subdir in $(SUBDIRS); do \
		cd $$subdir && $(MAKE) all; \
	done
	$(CC) -o funcAn.exe $(OBJECTS) $(OBJS) -LfunctionAnalyzer/gridOptimizer/src/private -l$(LIBRARY) $(CFLAGS)

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
main.o: functionAnalyzer/gridOptimizer/src/./../src/CGridPoint.hpp
main.o: functionAnalyzer/gridOptimizer/src/./../src/CGridConfig.hpp
main.o: functionAnalyzer/gridOptimizer/src/./CGridConfig.hpp
main.o: functionAnalyzer/gridOptimizer/api/IGridOptimizer.hpp
main.o: functionAnalyzer/gridOptimizer/api/IGridPoint.hpp
main.o: functions/src/CMyFunction1.hpp
