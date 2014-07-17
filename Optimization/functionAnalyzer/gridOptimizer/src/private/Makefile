
include ../../../../makefile.inc

OBJECTS := CGridConfig.o CGridOptimizer.o CGridPoint.o
SOURCES := $(OBJECTS:%.o=%.cpp)
LIBRARY := libgridOptimizer.a

all: $(LIBRARY)

$(OBJECTS): %.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

$(LIBRARY): $(OBJECTS)
	ar rvs $(LIBRARY) $(OBJECTS)

clean:
	rm -f $(LIBRARY)
	rm -f *.bak
	@for obj in $(OBJECTS); do \
		rm -f $$obj; \
	done

depend:
	makedepend $(SOURCES)
# DO NOT DELETE

CGridConfig.o: ../CGridConfig.hpp
CGridOptimizer.o: ../CGridOptimizer.hpp ../../api/IGridOptimizer.hpp
CGridOptimizer.o: ../../api/IGridPoint.hpp .././CGridPoint.hpp
CGridOptimizer.o: .././../src/CGridPoint.hpp .././../src/CGridConfig.hpp
CGridOptimizer.o: .././CGridConfig.hpp
CGridPoint.o: ../CGridPoint.hpp .././../src/CGridPoint.hpp
CGridPoint.o: .././../src/CGridConfig.hpp
