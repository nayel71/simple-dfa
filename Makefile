CXX = g++
CXXFLAGS = -std=c++11

.PHONY:	all

all:	main multigen/multigen

main:	src/dfa.o
