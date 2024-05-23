#include "Obstacle.hpp"

const float OBSTACLE_HEIGHT = 50;
const float OBSTACLE_LENGTH = 50;

Obstacle::Obstacle(const sf::Vector2f &pos): _body(sf::RectangleShape(sf::Vector2f(OBSTACLE_LENGTH, OBSTACLE_HEIGHT))), _pos(pos) {
	this->_body.setOrigin(OBSTACLE_LENGTH/2., OBSTACLE_HEIGHT/2.);
	this->_body.setFillColor(sf::Color::Green);
	this->_body.setPosition(this->_pos);
}

Obstacle::~Obstacle() {}
		
sf::RectangleShape		&Obstacle::getBody() {
	return this->_body;
}

bool					Obstacle::intersect(sf::Vector2f &pos_player) {
	(void)pos_player;
	return false;
}
