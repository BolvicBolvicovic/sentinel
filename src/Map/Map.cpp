#include "Map.hpp"

Map::Map(): _player1(Champion()) {
	this->_map.push_back(new Obstacle(sf::Vector2f(500, 100)));
	this->_map.push_back(new Obstacle(sf::Vector2f(500, 500)));
	this->_map.push_back(new Obstacle(sf::Vector2f(90 , 250)));
	this->_map.push_back(new Obstacle(sf::Vector2f(300, 500)));
}

Map::~Map() {
	for (auto it = this->_map.begin(); it != this->_map.end(); it++) {
		delete *it;
	}
}
		
void	Map::render(sf::RenderWindow &window) {
	for (auto it = this->_map.begin(); it != this->_map.end(); it++) {
		window.draw((*it)->getBody());
	}
}

Champion	&Map::getChamp() {
	return this->_player1;
}


bool		Map::intersect_with_walls(Entity *entity, int flag) {
	sf::Vector2f player_size = entity->getBody().getSize();
	sf::Vector2f player_pos = entity->getPos();
	player_pos.x += player_size.x;
	player_pos.y += player_size.y / 2.;
	switch (flag) {
		case 0:
			player_pos.x += SPEED;
			break;
		case 1:
			player_pos.x -= SPEED;
			break;
		case 2:
			player_pos.y += SPEED;
			break;
		case 3:
			player_pos.y -= SPEED;
			break;
		default:
			break;
	}
	for (auto it = this->_map.begin(); it != this->_map.end(); it++) {
		if ((*it)->intersect(player_pos, player_size)) {
			return true;
		}
	}
	return false;
}
