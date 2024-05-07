SANFLAGS = -fsanitize=address
CXXFLAGS = -Wall -std=c++23 -g  $(SANFLAGS)
LDFLAGS = $(SANFLAGS)

main:	main.o array.o
	$(CXX) -o $@ $^ $(SANFLAGS)

main.o : main.cc array.h
array.o : array.cc array.h
