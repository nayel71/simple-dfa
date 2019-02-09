CXX = g++
CXXFLAGS = -std=c++11

.PHONY:	all

all:	main mult-gen/mult-gen

main:	src/dfa.o
