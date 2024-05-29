#include "Map.hpp"

Map::Map(): _player1(Champion(sf::Vector2f(100,100), sf::Vector2f(20,50), "Garen", "/home/bolvic/sentinel/Assets/playable character/warrior/warrior_armed_idle/S/warrior_armed_idle_S_270.0_0.png")) {
	this->_map.push_back(new Obstacle(sf::Vector2f(500, 100), sf::Vector2f(20, 20), "Mushrooms", "/home/bolvic/sentinel/Assets/prop/mushrooms/S/mushrooms_S_270.0_0.png"));
	this->_map.push_back(new Obstacle(sf::Vector2f(500, 500), sf::Vector2f(20, 20), "Mushrooms", "/home/bolvic/sentinel/Assets/prop/mushrooms/S/mushrooms_S_270.0_0.png"));
	this->_map.push_back(new Obstacle(sf::Vector2f(1000, 250), sf::Vector2f(20, 20), "Mushrooms", "/home/bolvic/sentinel/Assets/prop/mushrooms/S/mushrooms_S_270.0_0.png"));
	this->_map.push_back(new Obstacle(sf::Vector2f(300, 500), sf::Vector2f(20, 20), "Mushrooms", "/home/bolvic/sentinel/Assets/prop/mushrooms/S/mushrooms_S_270.0_0.png"));
	this->_map.push_back(new Obstacle(sf::Vector2f(500, 100), sf::Vector2f(20, 20), "Mushrooms", "/home/bolvic/sentinel/Assets/prop/mushrooms/S/mushrooms_S_270.0_0.png"));
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
	sf::Sprite		player_copy = entity->getBody();
	sf::Vector2f	player_pos = player_copy.getPosition();
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
	player_copy.setPosition(player_pos);
	for (auto it = this->_map.begin(); it != this->_map.end(); it++) {
		if ((*it)->intersect(player_copy.getGlobalBounds())) {
			return true;
		}
	}
	return false;
}
