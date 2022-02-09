/**
Main.cpp
Vector Graphics 

Author: Henry Bryant

CURRENT BUGS:

COMPLETED BUGS: 

*/
#include "Game.h"
#include <fstream>
#include <string.h>
#include <iostream>

int main()
{
    //init game engine
    Game game;
    //game loop
    while (game.running())
    {
        //update 
        game.update();
        //render
        game.render();
    }
    //end of application
    return 0;
}