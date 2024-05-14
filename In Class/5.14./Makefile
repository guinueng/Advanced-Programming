SANFLAGS = -fsanitize=address
CXXFLAGS = -Wall -std=c++23 -g  $(SANFLAGS)
LDFLAGS = $(SANFLAGS)

main :	main.o report.o
	$(CXX) -o $@ $^ $(SANFLAGS)

main.o:	main.cc report.h
report.o: report.cc report.h
