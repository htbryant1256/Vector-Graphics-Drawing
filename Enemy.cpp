#include "Enemy.h"

void Enemy::initEnemies()
{
	this->enemyRect.setSize(sf::Vector2f(100.f,100.f));
	this->enemyRect.setFillColor(sf::Color::Green);
	this->enemyRect.setPosition(sf::Vector2f(100.f, 100.f));
}

/*
void Enemy::spawnEnemies()
{
	this->enemy.setPosition(100, 100);
}
*/