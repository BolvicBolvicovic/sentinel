#include "Champion.hpp"
#include "../../Map.hpp"


Champion::Champion(
			const sf::Vector2f	&pos,
			const sf::Vector2f	&size,
			const string		&name,
			const string		&texture_url
): Entity(pos, size, name, texture_url), _dest(pos) {}

Champion::~Champion() {
}
	
void				Champion::setDest(const sf::Vector2f &dest) {
	this->_dest = dest;
	cout << "Dest has been reset" << endl;
}

void				Champion::updatePos(Map *map) {
	(void)map;
	if (this->_pos != this->_dest) {
		sf::Vector2f direction = this->_pos - this->_dest;
		this->_pos -= direction * 0.001f;
		this->_sprite.setPosition(this->_pos);
	}
}
