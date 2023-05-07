#include <ctest.h>
#include "libgame/game.hpp"
#include "libgame/graphics.hpp"

CTEST(game, check_function)
{
    create();
    bool expected = check();
    ASSERT_TRUE(expected);
}