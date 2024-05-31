#pragma once

#include "../Entity.hpp"
#include <chrono>
class Map;

class Champion: public Entity {
	private:
		sf::Vector2f						_dest;
		float								_speed;
		int									_x_texture;
		int									_y_texture;
		chrono::system_clock::time_point	_last_frame_time;
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
