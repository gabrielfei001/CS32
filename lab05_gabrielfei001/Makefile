CXX = g++

#CXXFLAGS=-std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

CXXFLAGS = -std=c++11 -Wall -Wextra -Werror

BINARIES = lab05Test

all: ${BINARIES}

lab05Test: lab05Test.o WordCount.o tddFuncs.o
	${CXX} $^ -o $@

test: ${BINARIES}
	./lab05Test

clean:
	/bin/rm -f ${BINARIES} *.o