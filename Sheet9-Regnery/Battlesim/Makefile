TARGET = GoT
LIBS = -lncurses
CC = g++
CFLAGS = -g -Wall -std=c++11

.PHONY: default all clean run $(TARGET)

default: $(TARGET)
all: default

SOURCES = Battle/main.cpp Battle/Terminal.cpp Battle/Dragon.cpp Battle/Weiswanderer.cpp Battle/Nachtwache.cpp Battle/Snake.cpp Battle/Wall.cpp Battle/Game.cpp Battle/Food.cpp
HEADERS = Battle/Terminal.h Battle/Wall.h Battle/Weiswanderer.h Battle/Nachtwache.h Battle/Snake.h Battle/Vec2D.h Battle/Dragon.h Battle/Game.h Battle/Food.h

$(TARGET):
	$(CC) $(SOURCES) $(CFLAGS) $(LIBS) -o $@

run:
	./$(TARGET)
	
clean:
	-rm -f $(TARGET)
	
