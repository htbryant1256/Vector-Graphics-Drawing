/**
Main.cpp
C++ Game

Author: Henry Bryant
PERFORMANCE:

Change movement to player and sfml views.

CURRENT BUGS:

Work on collision detection, should not be impacted by player movement
update.


COMPLETED : 
    Tile map works, sheers randomly. blocks sheer the same amount as movement variable
 --------->required a forloop for every movement. may be able to simplifiy this.
                    This can be simplified because during mulitple button inputs,
                    the program will run 2 or more for loops instead of one, this could
                    impact performace when the map is scaled very large



*/

#include "Game.h"
#include "Enemy.h"
#include <iostream>
#include <fstream>
#include <string.h>

int main()
{
     //init Game Engine
    Game game;
    //Game Loop
    while (game.running())
    {
        //Update 
        game.update();
        //Render
        game.render();
    }
    //End of Application
    return 0;
}