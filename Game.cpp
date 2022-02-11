#include "Game.h"
#include "line.h"
#include <iostream>

//private Functions---------------------------------------------------------------------------------
void Game::initVariables()
{
	window = nullptr;
    windowWidth = 1000;
    windowHeight = 1000;
}

void Game::initWindow()
{
    videoMode.width = windowWidth;
	videoMode.height = windowHeight;
    window = new sf::RenderWindow(videoMode, "Vector Drawing", sf::Style::Titlebar | sf::Style::Close);
    window->setFramerateLimit(60);

}
//event polling 
void Game::pollEvents()
{    
    while (window->pollEvent(ev))
    {
        switch (ev.type)
        {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::KeyPressed:
            if (ev.key.code == sf::Keyboard::Escape)
            {
                window->close();
                break;
            }
        }
    }
}

//public Functions---------------------------------------------------------------------------------
//updates game logic
void Game::update()
{
    pollEvents();
    line.updateLine();
}

//essentially display
void Game::render()
{
    window->draw(line.cursor);
    window->draw(line.vectorLine);
    window->draw(line.displayRect);
    window->draw(line.text);
    window->display();
}

//constructors / destructors
Game::Game()
{
	initVariables();
	initWindow();
}

Game::~Game()
{
	delete window;
}

const bool Game::running() const
{
	return window->isOpen();
}
