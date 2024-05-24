#pragma once

#include "../Entity.hpp"
class Map;

const float SPEED = 0.05;
const float CHAMP_LENGTH = 20;
const float CHAMP_HEIGHT = 50;

class Champion: public Entity {
	private:
		sf::Vector2f		_dest;
	public:
		Champion(
			const sf::Vector2f	&pos,
			const sf::Vector2f	&size,
			const string		&name
		);
		Champion();
		~Champion();
	
		void				updatePos(Map *map);
		void				updatePos() override {}
		void				setDest(const sf::Vector2f &dest);
};
