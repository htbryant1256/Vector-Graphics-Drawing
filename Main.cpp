/**
Main.cpp
C++ Game

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
    //init Game Engine
    Game game;
    //game Loop
    while (game.running())
    {
        //update 
        game.update();
        //render
        game.render();
    }
    //end of Application
    return 0;
}