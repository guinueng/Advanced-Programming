SANFLAGS = -fsanitize=address
CXXFLAGS = -Wall -std=c++23 -g  $(SANFLAGS)
LDFLAGS = $(SANFLAGS)

#main:	main.o array.o
main :	main.o shape.o
	$(CXX) -o $@ $^ $(SANFLAGS)

main.o:	main.cc shape.h
shape.o: shape.cc shape.h
#main.o : main.cc array.h
#array.o : array.cc array.h
