#include "Map.hpp"

Map::Map(): _player1(Champion(sf::Vector2f(100,100), sf::Vector2f(20,50), "Garen", "/home/bolvic/sentinel/Assets/characters/player.png")) {
	this->_map.push_back(new Obstacle(sf::Vector2f(500, 100), sf::Vector2f(20, 20), "walls", "/home/bolvic/sentinel/Assets/tilesets/walls/walls.png"));
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


bool		Map::intersect_with_walls(Entity *entity, const sf::Vector2f &direction) {
	sf::Sprite		player_copy = entity->getBody();
	sf::Vector2f	player_pos = player_copy.getPosition();
	player_copy.setPosition(player_pos - direction);
	for (auto it = this->_map.begin(); it != this->_map.end(); it++) {
		if ((*it)->intersect(player_copy.getGlobalBounds())) {
			return true;
		}
	}
	return false;
}
