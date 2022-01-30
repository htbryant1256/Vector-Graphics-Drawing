#include "Map.h"
#include <iostream>
void Map::initMap()
{
	

	this->mapScale = 3.f;
	this->playerSpeed = 5.f;

    this->grass.loadFromFile("Images/grassTile.png");
    this->grassTile.setTexture(grass);
    this->grassTile.setPosition(sf::Vector2f(0.f, 0.f));
	this->grassTile.setScale(sf::Vector2f(this->mapScale , this->mapScale));

	this->grassTree.loadFromFile("Images/grassTree.png");
	this->grassTreeTile.setTexture(grassTree);
	this->grassTreeTile.setPosition(sf::Vector2f(0.f, 0.f));
	this->grassTreeTile.setScale(sf::Vector2f(this->mapScale, this->mapScale));

	this->wallTile.setFillColor(sf::Color::White);
	this->wallTile.setSize(sf::Vector2f(160.f, 80.f));
	this->wallTile.setPosition(sf::Vector2f(0.f, 0.f));
	this->wallTile.setOutlineColor(sf::Color::Black);
	this->wallTile.setOutlineThickness(3);

	this->file.open("Map/map.txt");
	for (int row = 0; row < 50; row++) {
		for (int column = 0; column < 50; column++) {
			file >> this->mapArray[row][column];
		}
	}
	file.close();
}

void Map::mapUpdate(sf::RenderWindow* window, Map &map)
{
	for (auto& e : map.tileVector)
	{
		//e.setRotation(45.f);
		//e.setScale(sf::Vector2f(1.f, 1.f));
		if ((260 > e.getGlobalBounds().top) & (160 < e.getGlobalBounds().top) & (420 > e.getGlobalBounds().left) & (220 < e.getGlobalBounds().left))
		{

			//std::cout << e.getGlobalBounds();
			e.setColor(sf::Color::Red);
			window->draw(e);
		}
	}
}

void Map::mapLoad()
{
	for (int row = 0; row < 50; row++) {
		this->grassTile.setPosition(sf::Vector2f(row*-90.f, row * 45.f));
		this->grassTreeTile.setPosition(sf::Vector2f(row * -90.f, row * 45.f));

		for (int column = 0; column < 50; column++) {
			//std::cout << map.mapArray[row][column] << "";
			if (mapArray[row][column] == '1')
			{
				this->tileVector.push_back(this->grassTile);
				
				this->grassTile.move(sf::Vector2f(90.f, 45.f));
				this->grassTreeTile.move(sf::Vector2f(90.f, 45.f));
				//this->window->draw(this->map.wallTile);

			}
			else if (mapArray[row][column] == '2')
			{
				//this->tileVector.push_back(this->map.wallTile);
				this->tileVector.push_back(this->grassTreeTile);
				this->grassTile.move(sf::Vector2f(90.f, 45.f));
				this->grassTreeTile.move(sf::Vector2f(90.f, 45.f));

				//this->window->draw(this->map.wallTile);

			}
			else if (mapArray[row][column] == '0')
			{
				//this->tileVector.push_back(this->grassTile);

				//this->tileVector.push_back(this->map.wallTile);
				this->grassTile.move(sf::Vector2f(90.f, 45.f));
				this->grassTreeTile.move(sf::Vector2f(90.f, 45.f));

				//this->window->draw(this->map.wallTile);

			}
		}
		//  std::cout << std::endl;
	}
}

void Map::mapRender(sf::RenderWindow *window, Map &map, sf::RectangleShape &player)
{



	for (auto& e : map.tileVector)
	{
		//e.setRotation(45.f);
		//e.setScale(sf::Vector2f(1.f, 1.f));
		if (e.getGlobalBounds().intersects(player.getGlobalBounds()))
		{

			//std::cout << e.getGlobalBounds();
			e.setColor(sf::Color::Red);
			window->draw(e);
		}
		else
		{
			e.setColor(sf::Color::Blue);

			window->draw(e);
		}

	
		//sf::RectangleShape origin;
		//origin.setPosition(sf::Vector2f(400.f, 300.f));
	//	origin.setSize(sf::Vector2f(100.f, 100.f));
		//origin.setFillColor(sf::Color::Red);
//		if (e.getGlobalBounds().contains(sf::Vector2f(400.f, 300.f)))
	//	{
//			e.setColor(sf::Color::Blue);
	//		window->draw(e);
	//	}
		//window->draw(origin);

	//	if ((240 > e.getGlobalBounds().top) &! (400 > e.getGlobalBounds().left))
	//	{
	//		e.setColor(sf::Color::Green);
	//		window->draw(e);
	//	}
		

		
		//std::cout << this->playerData.playerRect.getGlobalBounds().top << "\n";
	}

}
