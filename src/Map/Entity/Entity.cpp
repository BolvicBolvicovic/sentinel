#include "Entity.hpp"

Entity::Entity(
	const sf::Vector2f &pos,
	const sf::Vector2f &size,
	const string &name
):
	_name(name),
	_pos(pos),
	_body(sf::RectangleShape(size))
{
	_body.setOrigin(size.x / 2., size.y / 2.);
	_body.setPosition(pos);
}

Entity::~Entity() {}

sf::RectangleShape		&Entity::getBody() {
	return this->_body;
}
string					&Entity::getName() {
	return this->_name;
}
sf::Vector2f			&Entity::getPos() {
	return this->_pos;
}
bool				Entity::intersect(const sf::Vector2f &obj_pos, const sf::Vector2f &obj_size) {
	sf::Vector2f self_pos(this->_pos);
	sf::Vector2f self_size(this->_body.getSize());
	self_pos.y += self_size.y / 2.;
	return	self_pos.x <= (obj_pos.x + obj_size.x) && (self_pos.x + self_size.x) > obj_pos.x &&
			self_pos.y <= (obj_pos.y + obj_size.y) && (self_pos.y + self_size.y) > obj_pos.y ;
}
