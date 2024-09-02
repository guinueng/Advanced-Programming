SANFLAGS = -fsanitize=address
CXXFLAGS += -Wall -std=c++23 -g $(SANFLAGS)
LDFLAGS += $(SANFLAGS)

main:	main.o music.o
	$(CXX) -o $@ $^ $(LDFLAGS)

.PHONY:	clean
clean:
	$(RM) main main.o music.o

main.o:	main.cc music.h
music.o:	music.cc music.h
