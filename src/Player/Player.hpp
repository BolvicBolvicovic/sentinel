#pragma once

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Map/Map.hpp"

using namespace std;

class Player {
	private:
		string		_name;
		Champion	&_champion;
	public:
		Player(const string &name, Champion &champion);
		~Player();
		
		void		setChampionDest(const sf::Vector2f& vec, Map* map);
		sf::Sprite	&getChampBody();
		void		updateChamp(Map *map);
		void		championAttack();
		void		championDies();
};
