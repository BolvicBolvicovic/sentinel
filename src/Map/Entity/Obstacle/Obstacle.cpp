#include "Obstacle.hpp"

const float OBSTACLE_HEIGHT = 50;
const float OBSTACLE_LENGTH = 50;

Obstacle::Obstacle(const sf::Vector2f &pos):
	Entity(pos, sf::Vector2f(OBSTACLE_LENGTH, OBSTACLE_HEIGHT), "Obstacle"),
	crossable(false)
{
	this->_body.setFillColor(sf::Color::Green);
	this->_body.setPosition(this->_pos);
}
Obstacle::~Obstacle() {}

bool Obstacle::isCrossable() {
	return this->crossable;
}
