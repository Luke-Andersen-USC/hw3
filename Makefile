CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes
#DEFS=-DDEBUG

all: llrec-test

llrec-test: llrec.o llrec-test.o
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ $(llrec.o llrec-test.o)


#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

llrec.o: llrec.h llrec.cpp
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c llrec.cpp

llrec-test.o: llrec.h llrec-test.cpp
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c llrec-test.cpp

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 