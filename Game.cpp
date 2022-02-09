#include "Game.h"
#include "line.h"
#include <iostream>

//Private Functions---------------------------------------------------------------------------------
void Game::initVariables()
{
	this->window = nullptr;
    this->windowWidth = 1000;
    this->windowHeight = 1000;
}

void Game::initWindow()
{
    this->videoMode.width = windowWidth;
	this->videoMode.height = windowHeight;
	this->window = new sf::RenderWindow(this->videoMode, "Vector Drawing", sf::Style::Titlebar | sf::Style::Close );
    this->window->setFramerateLimit(60);

    this->view1.setCenter(sf::Vector2f(400.f, 300.f));
    this->view1.setSize(sf::Vector2f(windowWidth, windowHeight));
    this->window->setView(view1);
}
//event polling 
void Game::pollEvents()
{    
    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (this->ev.key.code == sf::Keyboard::Escape)
            {
                this->window->close();
                break;
            }
        }
    }
}

//Public Functions---------------------------------------------------------------------------------
//updates game logic
void Game::update()
{
    this->pollEvents();
    this->line.updateLine();
}

//essentially display
void Game::render()
{
    this->window->draw(line.cursor);
    this->window->draw(line.vectorLine);
    this->window->draw(line.displayRect);
    this->window->draw(line.text);
    this->window->display();
}

//Constructors / Destructors
Game::Game()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen();
}
