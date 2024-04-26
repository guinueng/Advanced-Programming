SANFLAGS = -fsanitize=address
CXXFLAGS = -Wall -std=c++23 -g $(SANFLAGS)
LDFLAGS = $(SANFLAGS)

main:	main.o account.o
	$(CXX) -o $@ $^ $(SANFLAGS)
