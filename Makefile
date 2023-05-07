CC = g++
CPPFLAGS = -Wall -Wextra -Werror -I src/include -I src
SFMLFLAGS = -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system
GAME_CPP = src/Game/fifteen.cpp
GAME_EXE = bin/Game.exe
OBJ_GAME = obj/src/Game
LIB_GAME = obj/src/libgame

all: $(GAME_EXE)

$(GAME_EXE): $(OBJ_GAME)/fifteen.o $(LIB_GAME)/libgame.a
	$(CC) $(CPPFLAGS) -o $@ $^ $(SFMLFLAGS) -lm -mwindows

$(OBJ_GAME)/fifteen.o: $(GAME_CPP)
	$(CC) $(CPPFLAGS) -MMD -c $< -o $@ -lm

$(LIB_GAME)/libgame.a: $(LIB_GAME)/game.o $(LIB_GAME)/graphics.o
	ar rcs $@ $^

$(LIB_GAME)/game.o: src/libgame/game.cpp
	$(CC) $(CPPFLAGS) -MMD -c $< -o $@ -lm

$(LIB_GAME)/graphics.o: src/libgame/graphics.cpp
	$(CC) $(CPPFLAGS) -MMD -c $< -o $@ -lm

run: $(GAME_EXE)
	./$(GAME_EXE)

clean:
	rm -f bin/*.exe $(OBJ_GAME)/*.d $(OBJ_GAME)/*.o

-include fifteen.d game.d