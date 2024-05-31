SANFLAGS = -fsanitize=address
CXXFLAGS += -Wall -std=c++23 -g $(SANFLAGS)
LDFLAGS += $(SANFLAGS)

pack:	pack.o
	$(CXX) -o $@ $^ $(LDFLAGS)
