#include <ctest.h>
#include "libgame/game.hpp"
#include "libgame/graphics.hpp"

CTEST(game_logic, create_function)
{
    create();
    ASSERT_EQUAL(1, field[0]);
    ASSERT_EQUAL(4, field[3]);
    ASSERT_EQUAL(7, field[6]);
    ASSERT_EQUAL(11, field[10]);
    ASSERT_EQUAL(0, field[15]);
}

CTEST(game_logic, check_function)
{
    bool result = check();
    ASSERT_TRUE(result);
}

CTEST(game_logic, move_function)
{
    move(sf::Keyboard::Right);
    int expected = 0;
    int result1 = field[14];
    ASSERT_EQUAL(expected, result1);
    move(sf::Keyboard::Down);
    int result2 = field[10];
    ASSERT_EQUAL(expected, result2);
    move(sf::Keyboard::Left);
    int result3 = field[11];
    ASSERT_EQUAL(expected, result3);
    move(sf::Keyboard::Up);
    int result4 = field[15];
    ASSERT_EQUAL(expected, result4);
}

CTEST(game_logic, mix_function)
{
    mix();
    bool result = check();
    ASSERT_FALSE(result);

}