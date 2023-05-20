#include "libgame/graphics.hpp"
#include "libgame/game.hpp"

void menu()
{
    sf::Text text;
    sf::Font font;
    font.loadFromFile("C:/WINDOWS/Fonts/arial.ttf");
    text.setFont(font);
    text.setCharacterSize(52);
    text.setString("You Win!");
    text.setPosition(50.f, 100.f);
    sf::RenderWindow window(sf::VideoMode(MENU_SIZE, MENU_SIZE), "Win");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Escape) window.close();
            }
        }
        window.clear();
        window.draw(text);
        window.display();
    }
}

void window()
{
    sf::Color color = sf::Color::Green;
    sf::RectangleShape shape(sf::Vector2f(CELL_SIZE - 2, CELL_SIZE - 2));
	shape.setOutlineThickness(2.f);
	shape.setOutlineColor(color);
	shape.setFillColor(sf::Color::Transparent);
    shape.setPosition(1, 2);
    sf::Text text;
    sf::Text text1;
    sf::Font font;
    font.loadFromFile("C:/WINDOWS/Fonts/arial.ttf");
    text.setFont(font);
    text1.setFont(font);
    text.setCharacterSize(52);
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE+50), "Fifteen");
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
                if(event.key.code == sf::Keyboard::Escape) window.close();
            }
        }
        window.clear();
        for(int i = 0; i < FIELD_SIZE; i++)
        {
            text.setString(std::to_string(field[i]));
            if (field[i] > 0)
            {
                sf::Vector2f position(i % 4 * CELL_SIZE + 10.f, i / 4 * CELL_SIZE + 10.f);
                shape.setPosition(position);
                if(field[i] >= 10)
                {
                    text.setPosition(position.x + 30.f, position.y + 25.f);
                }
                else
                {
                    text.setPosition(position.x + 45.f, position.y + 25.f);
                }
                window.draw(shape);
                window.draw(text);
            }
        }
        text1.setString("Up, Down, Left, Right - move                   Esc - exit");
        text1.setPosition(10, WINDOW_SIZE+10);
        text1.setCharacterSize(20);
        window.draw(text1);
        window.display();
        if(check() == true)
        {
            menu();
            mix();
        }
    }
}