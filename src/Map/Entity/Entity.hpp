#pragma once

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Entity {
	protected:
		string				_name;
		sf::Vector2f		_pos;
		sf::Texture			_texture;
		sf::Sprite			_sprite;
	public:
		Entity(
			const sf::Vector2f	&pos,
			const sf::Vector2f	&size,
			const string		&name,
			const string		&texture_url
		);
		virtual ~Entity();

		sf::Sprite				&getBody();
		sf::Vector2f			&getPos();
		string					&getName();
		bool					intersect(const sf::Rect<float> &rect);
		virtual void			updatePos() = 0;
};
