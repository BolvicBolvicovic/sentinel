#pragma once

#include <SFML/Graphics.hpp>
#include "Player/Player.hpp"
#include "Map/Map.hpp"

bool	intersect(
	sf::Vector2f &obj1_pos, 
	sf::Vector2f &obj1_size, 
	sf::Vector2f &obj2_pos, 
	sf::Vector2f &obj2_size
);
