#include <SFML/Graphics.hpp>

bool	intersect(
	sf::Vector2f &obj1_pos, 
	sf::Vector2f &obj1_size, 
	sf::Vector2f &obj2_pos, 
	sf::Vector2f &obj2_size)
{
	return	obj1_pos.x <= (obj2_pos.x + obj2_size.x) && (obj1_pos.x + obj1_size.x) > obj2_pos.x &&
			obj1_pos.y <= (obj2_pos.y + obj2_size.y) && (obj1_pos.y + obj1_size.y) > obj2_pos.y ;
}
