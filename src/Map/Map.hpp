#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Obstacle/Obstacle.hpp"

using namespace std;

class Map {
	private:
		vector<Obstacle>	_map;
	public:
		Map();
		~Map();
		
		void	render(sf::RenderWindow &window);
};
