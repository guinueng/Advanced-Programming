SANFLAGS = -fsanitize=address
CXXFLAGS += -Wall -std=c++23 -g $(SANFLAGS)
LDFLAGS += $(SANFLAGS)
midterm:	main.o rpg.o
	$(CXX) -o $@ $^ $(LDFLAGS)
main.o:	rpg.h main.cc
rpg.o:	rpg.h rpg.cc
