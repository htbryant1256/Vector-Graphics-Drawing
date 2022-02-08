#include "line.h"

void Line::initLine()
{

    this->x = 4;
    this->y = 2;

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
    text.setScale(sf::Vector2f(.8, .8));
    text2.setScale(sf::Vector2f(.8, .8));

    text.setString("X Velocity: " + std::to_string(this->x) + "\nX Coordinate: " + std::to_string(this->cursor.getPosition().x));

    text2.setString("Y Velocity: " + std::to_string(this->y));
    text2.setPosition(sf::Vector2f(-80, -140));

    this->displayRect.setPosition(sf::Vector2f(-90, -180));
    this->displayRect.setSize(sf::Vector2f(300, 100));
    this->displayRect.setFillColor(sf::Color::Black);
    this->displayRect.setOutlineColor(sf::Color::White);
    this->displayRect.setOutlineThickness(3);

    int angle = 0;
    vectorLine.setPosition(100, 100);
    vectorLine.setSize(sf::Vector2f(1, 90));
    vectorLine.setFillColor(sf::Color::White);
    cursor.setPosition(vectorLine.getPosition());
    cursor.setSize(sf::Vector2f(3, 3));
    cursor.setOutlineColor(sf::Color::Black);
    cursor.setOutlineThickness(1);
    this->autoMode = true;

}

void Line::updateLine()
{
    if (cursor.getPosition().x >= -100 && cursor.getPosition().x <= 900 && cursor.getPosition().y >= -200 && cursor.getPosition().y <= 800)
    {
        // std::cout << cursor.getPosition().y << "\n";
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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {

            autoMode = false;

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        {

            autoMode = true;
        }

    }
    else if (autoMode && !cursor.getPosition().x >= -100 && cursor.getPosition().x <= 900 && cursor.getPosition().y >= -200 && cursor.getPosition().y <= 800)
    {
        // line1.move(sf::Vector2f(2, 0));
        this->y++;
        this->x *= -1;
        if (this->x <= 0)
        {
            x++;
        }
        vectorLine.setFillColor(sf::Color::Cyan);

    }
    else if (autoMode && cursor.getPosition().x >= -100 && !cursor.getPosition().x <= 900 && cursor.getPosition().y >= -200 && cursor.getPosition().y <= 800)
    {
        // line1.move(sf::Vector2f(-2, 0));
       //  this->x++;
        this->y--;
        this->x *= -1;
        if (this->x == 0)
        {
            x++;
        }
        vectorLine.setFillColor(sf::Color::Green);

    }
    else if (autoMode && cursor.getPosition().x >= -100 && cursor.getPosition().x <= 900 && !cursor.getPosition().y >= -200 && cursor.getPosition().y <= 800)
    {
        //line1.move(sf::Vector2f(0, 2));
        this->x--;

        this->y *= -1;
        if (this->y == 0)
        {
            y++;
        }
        vectorLine.setFillColor(sf::Color::Yellow);

    }
    else if (autoMode && cursor.getPosition().x >= -100 && cursor.getPosition().x <= 900 && cursor.getPosition().y >= -200 && !cursor.getPosition().y <= 800)
    {
        // line1.move(sf::Vector2f(0, -2));

        this->y *= -1;
        if (this->y == 0)
        {
            y--;
        }
        vectorLine.setFillColor(sf::Color::Magenta);



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


    if (autoMode)
    {
        vectorLine.move(sf::Vector2f(x, y));

    }
    cursor.setPosition(sf::Vector2f(vectorLine.getPosition().x - (cursor.getSize().x / 2), vectorLine.getPosition().y - (cursor.getSize().y / 2)));
    vectorLine.rotate(1);
}

