#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Entity/Obstacle/Obstacle.hpp"
#include "Entity/Champion/Champion.hpp"

using namespace std;

class Map {
	private:
		vector<Entity*>	_map;
		Champion 		_player1;
	public:
		Map();
		~Map();
		
		void		render(sf::RenderWindow &window);
		bool		intersect_with_walls(Entity *entity, const sf::Vector2f &direction);
		Champion	&getChamp();
};
