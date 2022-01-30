#include "Game.h"
#include <iostream>

//Private Functions---------------------------------------------------------------------------------
void Game::initVariables()
{
    this->x = 2;
    this->y = 1;

    if (!font.loadFromFile("arial.ttf"))
    {
        // error...
        std::cout << "Error Loading Font\n";
    }

    // select the font
    text.setFont(font);
    text.setFillColor(sf::Color::White);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(5);
    text2.setFont(font);
    text2.setFillColor(sf::Color::White);
    text2.setOutlineColor(sf::Color::Black);
    text2.setOutlineThickness(5);
    text.setPosition(sf::Vector2f(-80, -170));
    text.setScale(sf::Vector2f(.8,.8));
    text2.setScale(sf::Vector2f(.8, .8));

    text.setString("X Velocity: " + std::to_string(this->x) + "\nX Coordinate: " + std::to_string(this->cursor.getPosition().x));

    text2.setString("Y Velocity: " + std::to_string(this->y));
    text2.setPosition(sf::Vector2f(-80, -140));

    this->displayRect.setPosition(sf::Vector2f(-90, -180));
    this->displayRect.setSize(sf::Vector2f(300, 100));
    this->displayRect.setFillColor(sf::Color::Black);
    this->displayRect.setOutlineColor(sf::Color::White);
    this->displayRect.setOutlineThickness(3);

	this->window = nullptr;
    this->windowWidth = 1000;
    this->windowHeight = 1000;
    int angle = 0;
    line1.setPosition(100, 100);
    line1.setSize(sf::Vector2f(1, 90));
    cursor.setPosition(line1.getPosition());
    cursor.setSize(sf::Vector2f(3,3));
    cursor.setOutlineColor(sf::Color::Black);
    cursor.setOutlineThickness(1);
    line3.setPosition(190, 190);
    line3.setSize(sf::Vector2f(-90, 1));

}

void Game::initWindow()
{
    this->videoMode.width = windowWidth;
	this->videoMode.height = windowHeight;

	this->window = new sf::RenderWindow(this->videoMode, "Vector Drawing", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);

    this->view1.setCenter(sf::Vector2f(400.f, 300.f));
    this->view1.setSize(sf::Vector2f(windowWidth, windowHeight));
    this->window->setView(view1);

}

//Event polling
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
    this->player.playerInputUpdate(view1);

    //Includes Player Movement
  //  this->map.mapUpdate(this->map);
}

//essentially display
void Game::render()
{
    //clear window
    //Draw Map
  //  this->map.mapRender(this->window, this->map, this->player.playerRect);
    //this->window->draw(this->map.mapSprite);
    
    //Draw Enemies
    //this->window->draw(this->enemy.enemyRect);
    this->window->setView(view1);

    //Draw Player
  //  this->window->draw(this->player.playerRect);


 
    if (cursor.getPosition().x >= -100 && cursor.getPosition().x <= 900 && cursor.getPosition().y >= -200 && cursor.getPosition().y <= 800)
    {
       // std::cout << cursor.getPosition().y << "\n";

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {

            line1.move(sf::Vector2f(2, 0));

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {

            line1.move(sf::Vector2f(-2, 0));


        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {

            line1.move(sf::Vector2f(0, -2));


        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {

            line1.move(sf::Vector2f(0, 2));

        }

    }
    else if (!cursor.getPosition().x >= -100 && cursor.getPosition().x <= 900 && cursor.getPosition().y >= -200 && cursor.getPosition().y <= 800)
    {
       // line1.move(sf::Vector2f(2, 0));
        this->y++;
        this->x *= -1;
        if (this->x <= 0)
        {
            x++;
        }
    }
    else if (cursor.getPosition().x >= -100 && !cursor.getPosition().x <= 900 && cursor.getPosition().y >= -200 && cursor.getPosition().y <= 800)
    {
       // line1.move(sf::Vector2f(-2, 0));
      //  this->x++;
        this->y--;
        this->x *= -1;
        if (this->x == 0)
        {
            x++;
        }
    }
    else if (cursor.getPosition().x >= -100 && cursor.getPosition().x <= 900 && !cursor.getPosition().y >= -200 && cursor.getPosition().y <= 800)
    {
        //line1.move(sf::Vector2f(0, 2));
        this->x--;

        this->y *= -1;
        if (this->y == 0)
        {
            y++;
        }
    }
    else if (cursor.getPosition().x >= -100 && cursor.getPosition().x <= 900 && cursor.getPosition().y >= -200 && !cursor.getPosition().y <= 800)
    {
       // line1.move(sf::Vector2f(0, -2));
        this->y++;
        this->y *= -1;
        if (this->y == 0)
        {
            y--;
        }
        

    }
    if (this->x >= 5)
    {
        this->x = 2;
    }
    if (this->y >= 5)
    {
        this->y = 2;
    }
    if (this->y <= -5)
    {
        this->y = -2;
    }
    if (this->x <= -5)
    {
        this->x = -2;
    }
    text.setString("X Velocity: " + std::to_string(this->x) + "\nY Veclocity: " + std::to_string(this->y) + "\nCoordinates: ( " + std::to_string(int(cursor.getPosition().x)) + " , " + std::to_string(int(cursor.getPosition().y)) + " )");

    text2.setString("Y Velocity: " + std::to_string(this->y));

   

    line1.move(sf::Vector2f(x, y));
    cursor.setPosition(sf::Vector2f(line1.getPosition().x - (cursor.getSize().x / 2), line1.getPosition().y - (cursor.getSize().y / 2)));
    line1.rotate(2);
    this->window->draw(cursor);

    this->window->draw(line1);
   // this->window->draw(line2);
   // this->window->draw(line3);
    this->window->draw(displayRect);
    this->window->draw(text);
   // this->window->draw(text2);


    this->window->display();
}
//Constructors / Destructors
Game::Game()
{
	this->initVariables();
	this->initWindow();
 //   this->enemy.initEnemies();
 //   this->player.initPlayer(this->windowWidth, this->windowHeight);
  //  this->map.initMap();
   // this->map.mapLoad();
}

Game::~Game()
{
	delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen();
}
