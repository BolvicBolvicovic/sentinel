#pragma once

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Obstacle {
	private:
		sf::RectangleShape		_body;
		sf::Vector2f			_pos;
	public:
		Obstacle(const sf::Vector2f &pos);
		~Obstacle();
		
		sf::RectangleShape		&getBody();
		bool	intersect(sf::Vector2f &pos_player);
};
