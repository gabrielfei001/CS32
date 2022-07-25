CXX=g++

#CXXFLAGS=-std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

CXXFLAGS = -std=c++11 -Wall -Wextra -Werror

BINARIES=lab04Test 

all: ${BINARIES}

lab04Test: lab04Test.o WordCount.o tddFuncs.o
	${CXX} $^ -o $@

test: ${BINARIES}
	./lab04Test

clean:
	/bin/rm -f ${BINARIES} *.o
