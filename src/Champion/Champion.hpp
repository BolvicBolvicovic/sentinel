#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
using namespace std;

class Champion {
	private:
		string				_name;
		sf::Vector2f		_pos;
		sf::Vector2f		_dest;
		sf::RectangleShape	_body;
	public:
				Champion();
				~Champion();
	
		void				setDest(const sf::Vector2f &dest);
		void				updatePos();
		sf::RectangleShape	&getBody();
};
