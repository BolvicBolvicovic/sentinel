#include "Champion.hpp"
#include "../../Map.hpp"
#include <math.h>

Champion::Champion(
			const sf::Vector2f	&pos,
			const sf::Vector2f	&size,
			const string		&name,
			const string		&texture_url
): Entity(pos, size, name, texture_url), _dest(pos), _speed(0.1), _x_texture(0), _y_texture(0) {
	this->_last_frame_time = chrono::system_clock::now();
	this->_sprite.setTextureRect(sf::IntRect(_x_texture, _y_texture, 48, 48));
	this->_sprite.setOrigin(24, 24);
}

Champion::~Champion() {
}
	
void	Champion::setDest(const sf::Vector2f &dest) {
	this->_dest = dest;
}

inline void normalizeVector(sf::Vector2f &vector) {
	float magnetude = sqrt(vector.x * vector.x + vector.y * vector.y);
	vector.x = vector.x / magnetude;
	vector.y = vector.y / magnetude;
}

void	Champion::updatePos(Map *map) {
	auto now = chrono::system_clock::now();
	chrono::duration<double> elapsed_time = now - this->_last_frame_time;
	if (this->_pos != this->_dest) {
		sf::Vector2f direction = this->_pos - this->_dest;
		normalizeVector(direction);
		if (!map->intersect_with_walls(this, direction)) {
			this->_pos -= direction * this->_speed;
			this->_sprite.setPosition(this->_pos);
		} else {
			cout << "Stoped" << endl;
			this->_dest = this->_pos;
			this->_x_texture = 0;
			this->_y_texture = 0;
		}
	} else if (elapsed_time.count() > 0.4) {
		this->_last_frame_time = now;
		this->_x_texture += 48;
		if (_x_texture >= 288)
			this->_x_texture = 0;
	}
	this->_sprite.setTextureRect(sf::IntRect(_x_texture, _y_texture, 48, 48));
}
