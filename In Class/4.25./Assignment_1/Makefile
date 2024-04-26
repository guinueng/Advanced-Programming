SANFLAGS = -fsanitize=address
CXXFLAGS = -Wall -std=c++23 -g $(SANFLAGS)
LDFLAGS = $(SANFLAGS)

a01 :	a01.cc wav-file.cc
	g++ -o $@ $^

a01_test :	a01_test.cc wav-file.cc
	g++ -o $@ $^
