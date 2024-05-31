#pragma once

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

struct Tile {
	int id = -1;
	sf::Vector2f	pos;
	sf::Texture 	*texture;
	sf::Sprite		sprite;
};
