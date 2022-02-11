#include "line.h"
//Private Functions---------------------------------------------------------------------------------

void Line::initLine()
{
    xVel = 4;
    yVel = -2;
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
    text.setPosition(sf::Vector2f(20, 14));
    text.setScale(sf::Vector2f(.8, .8));

    text.setString("X Velocity: " + std::to_string(xVel) +
                 "\nX Coordinate: " + std::to_string(cursor.getPosition().x));


    displayRect.setPosition(sf::Vector2f(10, 10));
    displayRect.setSize(sf::Vector2f(300, 100));
    displayRect.setFillColor(sf::Color::Black);
    displayRect.setOutlineColor(sf::Color::White);
    displayRect.setOutlineThickness(3);

    vectorLine.setPosition(500, 500);
    vectorLine.setSize(sf::Vector2f(1, 90));
    vectorLine.setFillColor(sf::Color::White);
    cursor.setPosition(vectorLine.getPosition());
    cursor.setSize(sf::Vector2f(3, 3));
    cursor.setOutlineColor(sf::Color::Black);
    cursor.setOutlineThickness(1);
    
}
char Line::colliding()
{
 
    if (cursor.getPosition().x >= 0 && cursor.getPosition().x <= 1000 && cursor.getPosition().y >= 0 && cursor.getPosition().y <= 1000)
    {
        return '0';
    }
    else if (!cursor.getPosition().x >= 0 && cursor.getPosition().x <= 1000 && cursor.getPosition().y >= 0 && cursor.getPosition().y <= 1000)
    {
        return 'L';
    }
    else if (cursor.getPosition().x >= 0 && !cursor.getPosition().x <= 1000 && cursor.getPosition().y >= 0 && cursor.getPosition().y <= 1000)
    {
        return 'R';
    }
    else if (cursor.getPosition().x >= 0 && cursor.getPosition().x <= 1000 && !cursor.getPosition().y >= 0 && cursor.getPosition().y <= 1000)
    {
        return 'T';
    }
    else if (cursor.getPosition().x >= 0 && cursor.getPosition().x <= 1000 && cursor.getPosition().y >= 0 && !cursor.getPosition().y <= 1000)
    {
        return 'B';
    }
}
//Public Functions---------------------------------------------------------------------------------

void Line::updateLine()
{
    if (autoMode)
    {
        switch (colliding())
        {
        case 'L':
            yVel++;
            xVel *= -1;
            if (xVel <= 0)
            {
                xVel++;
            }
            vectorLine.setFillColor(sf::Color::Cyan);
            if (xVel <= -5)
            {
                xVel = -2;
            }
            break;
        case 'R':
            yVel--;
            xVel *= -1;
            if (xVel == 0)
            {
                xVel++;
            }
            vectorLine.setFillColor(sf::Color::Green);
            if (xVel >= 5)
            {
                xVel = 2;
            }
            break;
        case 'T':
            xVel--;
            yVel *= -1;
            if (yVel == 0)
            {
                yVel++;
            }
            vectorLine.setFillColor(sf::Color::Yellow);
            if (yVel >= 5)
            {
                yVel = 2;
            }
            break;
        case 'B':
            yVel *= -1;
            if (yVel == 0)
            {
                yVel--;
            }
            vectorLine.setFillColor(sf::Color::Magenta);
            if (yVel <= -5)
            {
                yVel = -2;
            }
            break;
        }
        vectorLine.move(sf::Vector2f(xVel, yVel));
    }

    text.setString("X Velocity: " + std::to_string(xVel) + 
                 "\nY Veclocity: " + std::to_string(yVel) + 
                 "\nCoordinates: ( " + std::to_string(int(cursor.getPosition().x)) + 
                 " , " + std::to_string(int(cursor.getPosition().y)) + " )");

    cursor.setPosition(sf::Vector2f(vectorLine.getPosition().x - (cursor.getSize().x / 2), vectorLine.getPosition().y - (cursor.getSize().y / 2)));
    vectorLine.rotate(2);
}

Line::Line() 
{
    initLine();
}