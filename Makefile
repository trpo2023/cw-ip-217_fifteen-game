CC = g++
CPPFLAGS = -Wall -Wextra -Werror -I src/include -I src
SFMLFLAGS = -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system
GAME_CPP = src/game/fifteen.cpp
GAME_EXE = bin/game.exe
OBJ_GAME = obj/src/game
LIB_GAME = obj/src/libgame
TEST_OBJ = obj/test

all: $(GAME_EXE)

$(GAME_EXE): $(OBJ_GAME)/fifteen.o $(LIB_GAME)/libgame.a
	$(CC) $(CPPFLAGS) -o $@ $^ $(SFMLFLAGS) -lm -mwindows

$(OBJ_GAME)/fifteen.o: $(GAME_CPP)
	$(CC) -MMD $(CPPFLAGS) -c $< -o $@ -lm

$(LIB_GAME)/libgame.a: $(LIB_GAME)/game.o $(LIB_GAME)/graphics.o
	ar rcs $@ $^

$(LIB_GAME)/game.o: src/libgame/game.cpp
	$(CC) $(CPPFLAGS) -MMD -c $< -o $@ -lm

$(LIB_GAME)/graphics.o: src/libgame/graphics.cpp
	$(CC) $(CPPFLAGS) -MMD -c $< -o $@ -lm

run:
	./$(GAME_EXE)

clean:
	rm -f bin/*.exe $(OBJ_GAME)/*.d $(OBJ_GAME)/*.o $(TEST_OBJ)/*.*

test: bin/game-test.exe
	bin/game-test.exe

bin/game-test.exe: $(TEST_OBJ)/main.o $(TEST_OBJ)/ctest.o $(LIB_GAME)/libgame.a
	$(CC) -I src -I thirdparty $^ -o bin/game-test.exe -lm

$(TEST_OBJ)/main.o: test/main.c
	gcc $(CPPFLAGS) -MMD -I thirdparty -c $< -o $@

$(TEST_OBJ)/ctest.o: test/ctest.cpp
	$(CC) $(CPPFLAGS) -MMD -I thirdparty -c $< -o $@

.PHONY: all clean test

-include fifteen.d game.d graphics.d test.d main.d