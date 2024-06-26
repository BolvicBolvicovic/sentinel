#include "Champion.hpp"
#include "../../Map.hpp"
#include <math.h>
#include "../Pathfinding.cpp"

Champion::Champion(
			const sf::Vector2f	&pos,
			const sf::Vector2f	&size,
			const string		&name,
			const string		&texture_url
): Entity(pos, size, name, texture_url),
	_speed(0.01),
	_x_texture(0),
	_y_texture(0),
	_attack(4),
	_is_alive(-1)
{
	this->_last_frame_time = chrono::system_clock::now();
	this->_sprite.setTextureRect(sf::IntRect(_x_texture, _y_texture, 48, 48));
	this->_sprite.setOrigin(24, 24);
}

Champion::~Champion() {
}
	
void	Champion::setDest(const sf::Vector2f &dest, Map *map) {
	this->_dest.clear();
	this->_dest = findPath(this->_pos, dest, map, this);
	cout << this->_dest.empty() << endl;
}

inline void normalizeVector(sf::Vector2f &vector) {
	float magnetude = sqrt(vector.x * vector.x + vector.y * vector.y);
	vector.x = vector.x / magnetude;
	vector.y = vector.y / magnetude;
}

inline void Champion::move(Map *map, const int offset) {
	(void) map;
	if (this->_dest.empty()) {
		this->_x_texture = 0;
		this->_y_texture -= offset * 3;
		if (this->_y_texture < 0) {
			this->_y_texture = 0;
		}
		return;
	}
	sf::Vector2f direction;
	sf::Vector2f distance_left;
	while (!this->_dest.empty()) {
		direction = this->_pos - this->_dest[0];
		distance_left = this->_pos - this->_dest[0];
		normalizeVector(direction);
		if (abs(distance_left.x) < 0.1 && abs(distance_left.y) < 0.1) {
			this->_dest.pop_front();
			if (this->_dest.empty()) {
				this->_x_texture = 0;
				this->_y_texture -= offset * 3;
				if (this->_y_texture < 0) {
					this->_y_texture = 0;
				}
				return;
			}
		} else {
			break;
		}
	}
	this->_pos -= direction * this->_speed;
	this->_sprite.setPosition(this->_pos);
	if (abs(direction.y) >= abs(direction.x)) {
		if (direction.y <= 0)
			this->_y_texture = offset * 3;
		else
			this->_y_texture = offset * 5;
	} else {
		this->_y_texture = offset * 4;
		if (direction.x > 0) {
			this->_sprite.setScale(-1, 1);
		} else {
			this->_sprite.setScale(1, 1);
		}
	}
}

void	Champion::updatePos(Map *map) {
	const int offset = 48;
	auto now = chrono::system_clock::now();
	chrono::duration<double> elapsed_time = now - this->_last_frame_time;
	if (this->_is_alive == 0) {
		this-> _y_texture = offset * 9;
		this-> _x_texture = 0;
	} else if (this->_attack == 0 && this->_is_alive == -1) {
		switch (this->_y_texture) {
			case 0:
				this->_y_texture = offset * 6;
				break;
			case 48:
				this->_y_texture = offset * 7;
				break;
			case 96:
				this->_y_texture = offset * 8;
				break;
			case 144:
				this->_y_texture = offset * 6;
				break;
			case 192:
				this->_y_texture = offset * 7;
				break;
			case 240:
				this->_y_texture = offset * 8;
				break;
		}
		this->_x_texture = 0;
	} else if (!this->_dest.empty() && this->_attack == 4 && this->_is_alive == -1) {
		this->move(map, offset);
	}
	if (elapsed_time.count() > 0.3) {
		this->_last_frame_time = now;
		this->_x_texture += 48;
		if (this->_is_alive != -1) {
			this->_attack = 4;
			this->_is_alive += 1;
				if (this->_is_alive == 5) {
					this->_is_alive = -1;
					this->_y_texture = 0;
				this->_x_texture = 0;
				this->_pos = sf::Vector2f(40, 770);
				this->_dest.clear();
				this->_sprite.setPosition(this->_pos);
			}
		}
		if (this->_attack != 4) {
			this->_attack += 1;
			if (this->_attack == 4) {
				this->_x_texture = 0;
				this->_y_texture -= offset * 6;
			}
		}
		if (this->_x_texture >= 288)
			this->_x_texture = 0;
	}
	this->_sprite.setTextureRect(sf::IntRect(_x_texture, _y_texture, 48, 48));
}

void				Champion::attack() {
	if (this->_attack == 4)
		this->_attack = 0;
}

void				Champion::dies() {
	this->_is_alive = 0;
}
