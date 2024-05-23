SANFLAGS = -fsanitize=address
CXXFLAGS += -Wall -std=c++17 -g $(SANFLAGS)
LDFLAGS += $(SANFLAGS)

.phony:	all
all:	main00-bin main01-bin main02-bin main03-bin main04-bin main05-bin main06-bin main07-bin main08-bin main09-bin main10-bin

%-bin:	%.o widget.o
	$(CXX) -o $@ $^ $(LDFLAGS)
