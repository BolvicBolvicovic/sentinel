#pragma once

#include "../Entity.hpp"

class Obstacle: public Entity {
	protected:
		bool crossable;
	public:
		Obstacle(
			const sf::Vector2f	&pos,
			const sf::Vector2f	&size,
			const string		&name,
			const string		&texture_url
		);
		~Obstacle();

		bool isCrossable();
		void updatePos() override {}
};
