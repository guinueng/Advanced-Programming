SANFLAGS = -fsanitize=address
CXXFLAGS = -Wall -std=c++23 -g  $(SANFLAGS)
LDFLAGS = $(SANFLAGS)

main:	main.o audio-file.o wav-file.o
	$(CXX) -o $@ $^ $(SANFLAGS)
