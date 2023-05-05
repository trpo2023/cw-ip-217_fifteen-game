#include <SFML/Graphics.hpp>
#include "libgame/game.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    create();
    int random_moves = 1000;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Left) move(sf::Keyboard::Left);
                if(event.key.code == sf::Keyboard::Right) move(sf::Keyboard::Right);
                if(event.key.code == sf::Keyboard::Up) move(sf::Keyboard::Up);
                if(event.key.code == sf::Keyboard::Down) move(sf::Keyboard::Down);
                system("cls");
                Print();
            }
        }
        while(random_moves > 0)
        {
            move(71 + rand() % 4);
            random_moves--;
        }

        window.clear();
        window.display();
    }
    

    return 0;
}