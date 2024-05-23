#include "Champion.hpp"

const float SPEED = 0.05;
const float CHAMP_LENGTH = 20;
const float CHAMP_HEIGHT = 50;
const float CHAMP_ORIGIN_X = CHAMP_LENGTH / 2.;
const float CHAMP_ORIGIN_Y = CHAMP_HEIGHT / 2.;

Champion::Champion():
	_name("Garen"),
	_pos(sf::Vector2f(100, 100)),
	_dest(sf::Vector2f(100, 100)),
	_body(sf::RectangleShape(sf::Vector2f(CHAMP_LENGTH, CHAMP_HEIGHT)))
{
	this->_body.setOrigin(CHAMP_ORIGIN_X, CHAMP_ORIGIN_Y);
	this->_body.setFillColor(sf::Color::Magenta);
	this->_body.setPosition(this->_pos);
	cout << "A Champion has been created!" << endl;
}

Champion::~Champion() {
	cout << "A Champion has been deleted!" << endl;
}
	
void				Champion::setDest(const sf::Vector2f &dest) {
	this->_dest = dest;
}

void				Champion::updatePos() {
	if (this->_pos.x < this->_dest.x && this->_pos.x < this->_dest.x - SPEED - 1) {
		this->_pos.x += SPEED;
	} else {
		this->_pos.x -= SPEED;
	}
	if (this->_pos.y < this->_dest.y && this->_pos.y < this->_dest.y - SPEED - 1) {
		this->_pos.y += SPEED;
	} else {
		this->_pos.y -= SPEED;
	}
	this->_body.setPosition(this->_pos);
}


sf::RectangleShape	&Champion::getBody() {
	return this->_body;
}
