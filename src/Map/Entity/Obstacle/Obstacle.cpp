#include "Obstacle.hpp"

Obstacle::Obstacle(
	const sf::Vector2f	&pos,
	const sf::Vector2f	&size,
	const string		&name,
	const string		&texture_url
): Entity(pos, size, name, texture_url), crossable(false) {
	this->_sprite.setScale(size);
	this->_sprite.setTextureRect(sf::IntRect(15, 10, 140, 150));
	this->_sprite.setOrigin(75, 75);
}

Obstacle::~Obstacle() {}

bool Obstacle::isCrossable() {
	return this->crossable;
}
