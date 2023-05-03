CC = g++
CPPFLAGS = -Wall -Wextra -Werror -I src/include
SFMLFLAGS = -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system
GAME_CPP = src/Game/Game.cpp
GAME_EXE = bin/Game.exe
OBJ_GAME = obj/src/Game

all: $(GAME_EXE)

$(GAME_EXE): $(OBJ_GAME)/Game.o
	$(CC) $(CPPFLAGS) -o $@ $^ $(SFMLFLAGS)

$(OBJ_GAME)/Game.o: $(GAME_CPP)
	$(CC) $(CPPFLAGS) -MMD -c $< -o $@

run: $(GAME_EXE)
	./$(GAME_EXE)

clean:
	rm -f bin/*.exe $(OBJ_GAME)/*.d $(OBJ_GAME)/*.o

-include Game.d