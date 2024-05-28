SANFLAGS = -fsanitize=address
CXXFLAGS += -Wall -std=c++23 -g $(SANFLAGS)
LDFLAGS += $(SANFLAGS)

array-main:	array-main.o
	$(CXX) -o $@ $^ $(LDFLAGS)
