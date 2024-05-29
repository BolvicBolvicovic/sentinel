#include "Obstacle.hpp"

Obstacle::Obstacle(
	const sf::Vector2f	&pos,
	const sf::Vector2f	&size,
	const string		&name,
	const string		&texture_url
): Entity(pos, size, name, texture_url), crossable(false) { }

Obstacle::~Obstacle() {}

bool Obstacle::isCrossable() {
	return this->crossable;
}
