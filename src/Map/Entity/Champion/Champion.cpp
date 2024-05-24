#include "Champion.hpp"
#include "../../Map.hpp"


Champion::Champion():
	Entity(sf::Vector2f(100, 100), sf::Vector2f(CHAMP_LENGTH, CHAMP_HEIGHT), "Garen"),
	_dest(sf::Vector2f(100, 100))
{
	this->_body.setFillColor(sf::Color::Magenta);
	cout << "A Champion has been created!" << endl;
}

Champion::~Champion() {
	cout << "A Champion has been deleted!" << endl;
}
	
void				Champion::setDest(const sf::Vector2f &dest) {
	this->_dest = dest;
}

void				Champion::updatePos(Map *map) {
	if (this->_pos.x < this->_dest.x && this->_pos.x < this->_dest.x - SPEED - 1) {
		if (!map->intersect_with_walls(this, 0)) {
			this->_pos.x += SPEED;
		}
	} else {
		if (!map->intersect_with_walls(this, 1)) {
			this->_pos.x -= SPEED;
		}
	}
	if (this->_pos.y < this->_dest.y && this->_pos.y < this->_dest.y - SPEED - 1) {
		if (!map->intersect_with_walls(this, 2)) {
			this->_pos.y += SPEED;
		}
	} else {
		if (!map->intersect_with_walls(this, 3)) {
			this->_pos.y -= SPEED;
		}
	}
	this->_body.setPosition(this->_pos);
}
