
#include "Game.h"
#include <ctime>

int main()
{
    Game game;
    srand(static_cast<unsigned>(time(0)));
    game.run();
    Game *game2;
    game2= & game;
    game2->showGameOver();
    return 0;
}

