#include "Map.hpp"

Map::Map() {
	this->_map.push_back(Obstacle(sf::Vector2f(500, 100)));
	this->_map.push_back(Obstacle(sf::Vector2f(500, 500)));
	this->_map.push_back(Obstacle(sf::Vector2f(90 , 250)));
	this->_map.push_back(Obstacle(sf::Vector2f(300, 500)));
}

Map::~Map() {}
		
void	Map::render(sf::RenderWindow &window) {
	for (auto it = this->_map.begin(); it != this->_map.end(); it++) {
		window.draw(it->getBody());
	}
}
