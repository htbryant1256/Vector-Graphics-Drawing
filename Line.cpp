#include "line.h"
//Private Functions---------------------------------------------------------------------------------

void Line::initLine()
{
    xVel = 4;
    yVel = 2;
    angle = 0;
    autoMode = true;

    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "Error Loading Font\n";
    }

    text.setFont(font);
    text.setFillColor(sf::Color::White);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(5);
    text.setPosition(sf::Vector2f(-80, -170));
    text.setScale(sf::Vector2f(.8, .8));

    text.setString("X Velocity: " + std::to_string(this->xVel) +
                 "\nX Coordinate: " + std::to_string(this->cursor.getPosition().x));


    displayRect.setPosition(sf::Vector2f(-90, -180));
    displayRect.setSize(sf::Vector2f(300, 100));
    displayRect.setFillColor(sf::Color::Black);
    displayRect.setOutlineColor(sf::Color::White);
    displayRect.setOutlineThickness(3);

    vectorLine.setPosition(100, 100);
    vectorLine.setSize(sf::Vector2f(1, 90));
    vectorLine.setFillColor(sf::Color::White);
    cursor.setPosition(vectorLine.getPosition());
    cursor.setSize(sf::Vector2f(3, 3));
    cursor.setOutlineColor(sf::Color::Black);
    cursor.setOutlineThickness(1);
    
}
//Public Functions---------------------------------------------------------------------------------

void Line::updateLine()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        autoMode = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
        autoMode = true;
    }

    if (cursor.getPosition().x >= -100 && cursor.getPosition().x <= 900 && cursor.getPosition().y >= -200 && cursor.getPosition().y <= 800)
    {
        if (!autoMode)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                vectorLine.move(sf::Vector2f(2, 0));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                vectorLine.move(sf::Vector2f(-2, 0));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                vectorLine.move(sf::Vector2f(0, -2));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                vectorLine.move(sf::Vector2f(0, 2));
            }
        }
    }
    else if (autoMode && !cursor.getPosition().x >= -100 && cursor.getPosition().x <= 900 && cursor.getPosition().y >= -200 && cursor.getPosition().y <= 800)
    {
        // line1.move(sf::Vector2f(2, 0));
        this->yVel++;
        this->xVel *= -1;
        if (this->xVel <= 0)
        {
            xVel++;
        }
        vectorLine.setFillColor(sf::Color::Cyan);

    }
    else if (autoMode && cursor.getPosition().x >= -100 && !cursor.getPosition().x <= 900 && cursor.getPosition().y >= -200 && cursor.getPosition().y <= 800)
    {
        // line1.move(sf::Vector2f(-2, 0));
       //  this->x++;
        this->yVel--;
        this->xVel *= -1;
        if (this->xVel == 0)
        {
            xVel++;
        }
        vectorLine.setFillColor(sf::Color::Green);

    }
    else if (autoMode && cursor.getPosition().x >= -100 && cursor.getPosition().x <= 900 && !cursor.getPosition().y >= -200 && cursor.getPosition().y <= 800)
    {
        //line1.move(sf::Vector2f(0, 2));
        this->xVel--;

        this->yVel *= -1;
        if (this->yVel == 0)
        {
            yVel++;
        }
        vectorLine.setFillColor(sf::Color::Yellow);

    }
    else if (autoMode && cursor.getPosition().x >= -100 && cursor.getPosition().x <= 900 && cursor.getPosition().y >= -200 && !cursor.getPosition().y <= 800)
    {
        // line1.move(sf::Vector2f(0, -2));

        this->yVel *= -1;
        if (this->yVel == 0)
        {
            yVel--;
        }
        vectorLine.setFillColor(sf::Color::Magenta);



    }
    if (this->xVel >= 5)
    {
        this->xVel = 2;
    }
    if (this->yVel >= 5)
    {
        this->yVel = 2;
    }
    if (this->yVel <= -5)
    {
        this->yVel = -2;
    }
    if (this->xVel <= -5)
    {
        this->xVel = -2;
    }

    text.setString("X Velocity: " + std::to_string(this->xVel) + 
                 "\nY Veclocity: " + std::to_string(this->yVel) + 
                 "\nCoordinates: ( " + std::to_string(int(cursor.getPosition().x)) + 
                 " , " + std::to_string(int(cursor.getPosition().y)) + " )");

    if (autoMode)
    {
        vectorLine.move(sf::Vector2f(xVel, yVel));
    }
    cursor.setPosition(sf::Vector2f(vectorLine.getPosition().x - (cursor.getSize().x / 2), vectorLine.getPosition().y - (cursor.getSize().y / 2)));
    vectorLine.rotate(1);
}

Line::Line() 
{
    initLine();
}