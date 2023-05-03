all: bin/Game.exe

bin/Game.exe:
	g++ Game.cpp -o bin/Game.exe -Isrc/include -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

run: bin/Game.exe
	./bin/Game.exe

clean:
	rm bin/*.exe