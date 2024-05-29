#pragma once

#include "../Entity.hpp"
class Map;

const float SPEED = 0.1;

class Champion: public Entity {
	private:
		sf::Vector2f		_dest;
	public:
		Champion(
			const sf::Vector2f	&pos,
			const sf::Vector2f	&size,
			const string		&name,
			const string		&texture_url
		);
		~Champion();
	
		void				updatePos(Map *map);
		void				updatePos() override {}
		void				setDest(const sf::Vector2f &dest);
};
