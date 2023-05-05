#include <SFML/Graphics.hpp>
#include "libgame/game.hpp"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    create();
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Left) move(75);
                if(event.key.code == sf::Keyboard::Right) move(77);
                if(event.key.code == sf::Keyboard::Up) move(72);
                if(event.key.code == sf::Keyboard::Down) move(80);
                Print();
            }
        }

        window.clear();
        window.display();
    }
    

    return 0;
}