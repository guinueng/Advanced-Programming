CXXFLAGS = -Wall -std=c++23 -g
a:	a.o b.o
	g++ -o $& $^
points: points.o linear_root.cc
	g++ -o $@ $^
points.o:	points.cc linear_root.h
linear_root.o:	linear_root.cc linear_root.h
