SANFLAGS = -fsanitize=address
CXXFLAGS += -Wall -std=c++23 -g $(SANFLAGS)
LDFLAGS += $(SANFLAGS)

main: main-vector.o file.o
	$(CXX) -o $@ $^ $(LDFLAGS)
main-vector.o: main-vector.cc file.h

file.o: file.cc file.h
