#include "Entity.hpp"

Entity::Entity(
	const sf::Vector2f	&pos,
	const sf::Vector2f	&size,
	const string		&name,
	const string		&texture_url
):
	_name(name),
	_pos(pos)
{
	if (!_texture.loadFromFile(texture_url)) { cout << "Error loading file" << endl; } else {
		_texture.setSmooth(false);
		_sprite.setTexture(_texture);
		_sprite.setPosition(pos);
		(void)size;
	}
}

Entity::~Entity() {}

sf::Sprite		&Entity::getBody() {
	return this->_sprite;
}
string					&Entity::getName() {
	return this->_name;
}
sf::Vector2f			&Entity::getPos() {
	return this->_pos;
}

bool				Entity::intersect(const sf::Rect<float> &rect) {
	//TODO: rebuild the intersection to it looks more real
	//sf::FloatRect bounds(this->_pos.x, +);
	return this->_sprite.getGlobalBounds().intersects(rect);
}
