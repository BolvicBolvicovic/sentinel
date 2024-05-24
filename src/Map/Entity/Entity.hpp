#pragma once

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Entity {
	protected:
		string				_name;
		sf::Vector2f		_pos;
		sf::RectangleShape	_body;
	public:
		Entity(
			const sf::Vector2f &pos,
			const sf::Vector2f &size,
			const string &name
		);
		virtual ~Entity();

		sf::RectangleShape		&getBody();
		sf::Vector2f			&getPos();
		string					&getName();
		bool					intersect(const sf::Vector2f &obj_pos, const sf::Vector2f &obj_size);
		virtual void			updatePos() = 0;
};
