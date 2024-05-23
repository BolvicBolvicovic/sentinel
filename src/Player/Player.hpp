#pragma once

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Champion/Champion.hpp"

using namespace std;

class Player {
	private:
		string		_name;
		Champion	_champion;
	public:
		Player(const string &name);
		~Player();
		
		void				setChampionDest(const sf::Vector2f &vec);
		sf::RectangleShape	&getChampBody();
		void				updateChamp();
};
