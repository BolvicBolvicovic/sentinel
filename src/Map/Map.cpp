#include "Map.hpp"



Map::Map():
	_player1(Champion(
		sf::Vector2f(400,400),
		sf::Vector2f(20,50),
		"Garen",
		"/home/bolvic/sentinel/Assets/characters/player.png")
) {
	const char map[100][100] = {
		"ggggggggggggggggggggggggggggggggggggggggggggggggggggggppppppppppppppppppppppppppppppppppppppppppppp",
		"ggggggggggggggggggggggggggggggggggggggggggggggggggggggppppppppppppppppppppppppppppppppppppppppppppp",
		"gggggggggggggggggggggggggggggggggggggggggggggggggggggggpppppppppppppppppppppppppppppppppppppppppppp",
		"ggggggggggggggggggggggggggggggggggggggggggggggggggggggggppppppppppppppppppppppppppppppppppppppppppp",
		"gggggggpppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp",
		"gggggpppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp",
		"ggggppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp",
		"ggggppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp",
		"ggggppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp",
		"ggggppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp",
		"ggggppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp",
		"ggggppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp",
		"ggggppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp",
		"ggggpppppppppppggggggggggggggggggggggggggggggggggggggggggggggggggggggpppppppppppppppppppppppppppppp",
		"ggggppppppppppgggggggggggggggggggggggggggggggggggggggggggggggggggggggggpppppppppppppppppppppppppppp",
		"ggggppppppppppggggggggggggggggggggggggggggggggggggggggggggggggggggggggggppppppppppppppppppppppppppp",
		"ggggppppppppppggggggggggggggggggggggggggggggggggggggggggggggggggggggggggppppppppppppppppppppppppppp",
		"ggggppppppppppggggggggggggggggggggggggggggggggggggggggggggggggggggggggggppppppppppppppppppppppppppp",
		"ggggppppppppppggggggggggggggggggggggggggggggggggggggggggggggggggggggggggppppppppppppppppppppppppppp",
		"ggggppppppppppggggggggggggggggggggggggggggggggggggggggggggggggggggggggggppppppppppppppppppppppppppp",
		"ggggppppppppppgggggggggggggggggggggggggggggggggggggggggggggggggggggggggpppppppppppppppppppppppppppp",
		"ggggppppppppppggggggggggggggggggggggggggggggggggggggggggggggggggggggggppppppppppppgggggpppppppppppp",
		"ggggppppppppppggggggggggggggggggggggggggggggggggggggggggggggggggggggggpppppppppppggggggpppppppppppp",
		"ggggppppppppppggggggggggggggggggggggggggggggggggggggggggggggggggggggggpppppppppppggggggpppppppppppp",
		"ggggppppppppppgggggggggggggggggggggggggggggggggggggggggggggggggggggggpppppppppppggggggppppppppppppp",
		"ggggppppppppppgggggggggggggggggggggggggggggggggggggggggggggggggggggggppppppppppggggggpppppppppppggg",
		"ggggppppppppppggggggggggggggggggggggggggggggggggggggggggggggggggggggppppppppppgggggggpppppppppppggg",
		"ggggppppppppppgggggggggggggggggggggggggggggggggggggggggggggggggggggpppppppppppgggggggpppppppppppggg",
		"ggggppppppppppggggggggggggggggggggggggggggggggggggggggggggggggggggpppppppppppggggggggpppppppppppggg",
		"ggggppppppppppgggggggggggggggggggggggggggggggggggggggggggggggggggpppppppppppgggggggggpppppppppppggg",
		"ggggppppppppppggggggggggggggggggggggggggggggggggggggggggggggggggpppppppppppggggggggggpppppppppppggg",
		"ggggppppppppppgggggggggggggggggggggggggggggggggggggggggggggggggppppppppppppggggggggggpppppppppppggg",
		"ggggppppppppppggggggggggggggggggggggggggggggggggggggggggggggggppppppppppppgggggggggggpppppppppppggg",
		"ggggppppppppppgggggggggggggggggggggggggggggggggggggggggggggggpppppppppppppgggggggggggpppppppppppggg",
		"ggggppppppppppggggggggggggggggggggggggggggggggggggggggggggggpppppppppppppggggggggggggpppppppppppggg",
		"ggggppppppppppgggggggggggggggggggggggggggggggggggggggggggggpppppppppppppgggggggggggggpppppppppppggg",
		"ggggppppppppppggggggggggggggggggggggggggggggggggggggggggggpppppppppppppggggggggggggggpppppppppppggg",
		"ggggppppppppppgggggggggggggggggggggggggggggggggggggggggggpppppppppppppgggggggggggggggpppppppppppggg",
		"ggggppppppppppggggggggggggggggggggggggggggggggggggggggggpppppppppppppggggggggggggggggpppppppppppggg",
		"ggggppppppppppgggggggggggggggggggggggggggggggggggggggggpppppppppppppgggggggggggggggggpppppppppppggg",
		"ggggppppppppppggggggggggggggggggggggggggggggggggggggggpppppppppppppggggggggggggggggggpppppppppppggg",
		"ggggppppppppppgggggggggggggggggggggggggggggggggggggggpppppppppppppgggggggggggggggggggpppppppppppggg",
		"ggggppppppppppggggggggggggggggggggggggggggggggggggggpppppppppppppggggggggggggggggggggpppppppppppggg",
		"ggggppppppppppgggggggggggggggggggggggggggggggggggggpppppppppppppgggggggggggggggggggggpppppppppppggg",
		"ggggppppppppppggggggggggggggggggggggggggggggggggggpppppppppppppggggggggggggggggggggggpppppppppppggg",
		"ggggppppppppppgggggggggggggggggggggggggggggggggggpppppppppppppgggggggggggggggggggggggpppppppppppggg",
		"ggggppppppppppggggggggggggggggggggggggggggggggggpppppppppppppggggggggggggggggggggggggpppppppppppggg",
		"ggggppppppppppgggggggggggggggggggggggggggggggggpppppppppppppgggggggggggggggggggggggggpppppppppppggg",
		"ggggppppppppppggggggggggggggggggggggggggggggggpppppppppppppggggggggggggggggggggggggggpppppppppppggg",
		"ggggppppppppppgggggggggggggggggggggggggggggggpppppppppppppgggggggggggggggggggggggggggpppppppppppggg",
		"ggggppppppppppggggggggggggggggggggggggggggggpppppppppppppggggggggggggggggggggggggggggpppppppppppggg",
		"ggggppppppppppgggggggggggggggggggggggggggggpppppppppppppgggggggggggggggggggggggggggggpppppppppppggg",
		"ggggppppppppppggggggggggggggggggggggggggggpppppppppppppggggggggggggggggggggggggggggggpppppppppppggg",
		"ggggppppppppppgggggggggggggggggggggggggggpppppppppppppgggggggggggggggggggggggggggggggpppppppppppggg",
		"ggggppppppppppggggggggggggggggggggggggggpppppppppppppggggggggggggggggggggggggggggggggpppppppppppggg",
		"ggggppppppppppgggggggggggggggggggggggggpppppppppppppgggggggggggggggggggggggggggggggggpppppppppppggg",
		"ggggppppppppppggggggggggggggggggggggggpppppppppppppggggggggggggggggggggggggggggggggggpppppppppppggg",
		"ggggppppppppppgggggggggggggggggggggggpppppppppppppgggggggggggggggggggggggggggggggggggpppppppppppggg",
		"ggggppppppppppggggggggggggggggggggggpppppppppppppggggggggggggggggggggggggggggggggggggpppppppppppggg",
		"ggggppppppppppgggggggggggggggggggggpppppppppppppgggggggggggggggggggggggggggggggggggggpppppppppppggg",
		"ggggppppppppppggggggggggggggggggggpppppppppppppggggggggggggggggggggggggggggggggggggggpppppppppppggg",
		"ggggppppppppppgggggggggggggggggggpppppppppppppgggggggggggggggggggggggggggggggggggggggpppppppppppggg",
		"ggggppppppppppggggggggggggggggggpppppppppppppggggggggggggggggggggggggggggggggggggggggpppppppppppggg",
		"ggggppppppppppgggggggggggggggggpppppppppppppgggggggggggggggggggggggggggggggggggggggggpppppppppppggg",
		"ggggppppppppppggggggggggggggggpppppppppppppggggggggggggggggggggggggggggggggggggggggggpppppppppppggg",
		"ggggppppppppppgggggggggggggggpppppppppppppgggggggggggggggggggggggggggggggggggggggggggpppppppppppggg",
		"ggggppppppppppggggggggggggggpppppppppppppggggggggggggggggggggggggggggggggggggggggggggpppppppppppggg",
		"ggggppppppppppgggggggggggggpppppppppppppgggggggggggggggggggggggggggggggggggggggggggggpppppppppppggg",
		"ggggppppppppppggggggggggggpppppppppppppggggggggggggggggggggggggggggggggggggggggggggggpppppppppppggg",
		"ggggppppppppppgggggggggggpppppppppppppgggggggggggggggggggggggggggggggggggggggggggggggpppppppppppggg",
		"ggggppppppppppggggggggggpppppppppppppggggggggggggggggggggggggggggggggggggggggggggggggpppppppppppggg",
		"ggggppppppppppgggggggggpppppppppppppgggggggggggggggggggggggggggggggggggggggggggggggggpppppppppppggg",
		"ggggppppppppppggggggggpppppppppppppggggggggggggggggggggggggggggggggggggggggggggggggggpppppppppppggg",
		"ggggppppppppppgggggggpppppppppppppgggggggggggggggggggggggggggggggggggggggggggggggggggpppppppppppggg",
		"ggggppppppppppggggggpppppppppppppggggggggggggggggggggggggggggggggggggggggggggggggggggpppppppppppggg",
		"ggggppppppppppgggggpppppppppppppgggggggggggggggggggggggggggggggggggggggggggggggggggggpppppppppppggg",
		"ggggppppppppppggggpppppppppppppggggggggggggggggggggggggggggggggggggggggggggggggggggggpppppppppppggg",
		"ppppppppppppppgggpppppppppppppgggggggggggggggggggggggggggggggggggggggggggggggggggggggpppppppppppggg",
		"ppppppppppppppggpppppppppppppggggggggggggggggggggggggggggggggggggggggggggggggggggggggpppppppppppggg",
		"ppppppppppppppppppppppppppppgggggggggggggggggggggggggggggggggggggggggggggggggggggggggpppppppppppggg",
		"pppppppppppppppppppppppppppggggggggggggggggggggggggggggggggggggggggggggggggggggggggggpppppppppppggg",
		"pppppppppppppppppppppppppppggggggggggggggggggggggggggggggggggggggggggggggggggggggggggpppppppppppggg",
		"ppppppppppppppppppppppppppgggggggggggggggggggggggggggggggggggggggggggggggggggggggggggpppppppppppggg",
		"ppppppppppppppppppppppppppgggggggggggggggggggggggggggggggggggggggggggggggggggggggggggpppppppppppggg",
		"pppppppppppppppppppppppppppggggggggggggggggggggggggggggggggggggggggggggggggggggggggggpppppppppppggg",
		"pppppppppppppppppppppppppppggggggggggggggggggggggggggggggggggggggggggggggggggggggggggpppppppppppggg",
		"ppppppppppppppppppppppppppppgggggggggggggggggggggggggggggggggggggggggggggggggggggggggpppppppppppggg",
		"ppppppppppppppppppppppppppppgggggggggggggggggggggggggggggggggggggggggggggggggggggggggpppppppppppggg",
		"ppppppppppppppppppppppppppppgggggggggggggggggggggggggggggggggggggggggggggggggggggggggpppppppppppggg",
		"ppppppppppppppppppppppppppppgggggggggggggggggggggggggggggggggggggggggggggggggggggggggpppppppppppggg",
		"ppppppppppppppppppppppppppppgggggggggggggggggggggggggggggggggggggggggggggggggggggggggpppppppppppggg",
		"pppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppgggg",
		"pppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppgggg",
		"pppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppgggg",
		"pppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppgggg",
		"pppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppgggg",
		"ppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppggggg",
		"ppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppggggggg",
		"ppppppppppppppppppppppppppppppggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg",
		"ppppppppppppppppppppppppppppppggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg",
	};
	this->_map.push_back(new Obstacle(sf::Vector2f(80, 700), sf::Vector2f(0.4, 0.4), "BlueBase", "/home/bolvic/sentinel/Assets/tower_defense/12.png"));
	this->_map.push_back(new Obstacle(sf::Vector2f(670, 70), sf::Vector2f(0.4, 0.4), "RedBase", "/home/bolvic/sentinel/Assets/tower_defense/12.png"));
	if (!this->_tilemap_texture.loadFromFile("/home/bolvic/sentinel/Assets/tilesets/decor_8x8.png")) { cerr << "Error loading tilemap" << endl; }
	else {
		this->_tilemap_texture.setSmooth(false);
		this->_render_texture.create(800, 800);
		this->_render_texture.clear();
		for (int y = 0; y < 100; y++) {
			for (int x = 0; x < 100; x++) {
				Tile it;
				int x_texture = 0;
				int y_texture = 8;
				
				if (map[y][x] == 'p')
					y_texture = 24;
				it.texture = &this->_tilemap_texture;
				it.pos = sf::Vector2f(x * 8, y * 8);
				it.sprite.setTexture(*it.texture);
				it.sprite.setTextureRect(sf::IntRect(x_texture, y_texture, 8, 8));
				it.sprite.setPosition(it.pos);
				this->_render_texture.draw(it.sprite);
			}
		}
		for (auto it = this->_map.begin(); it != this->_map.end(); it++) {
			_render_texture.draw((*it)->getBody());
		}
		this->_render_texture.display();
		this->_render_sprite.setTexture(this->_render_texture.getTexture());
	} 
}

Map::~Map() {
	for (auto it = this->_map.begin(); it != this->_map.end(); it++) {
		delete *it;
	}
}
		
void	Map::render(sf::RenderWindow &window) {
	window.draw(this->_render_sprite);
}

Champion	&Map::getChamp() {
	return this->_player1;
}


bool		Map::intersect_with_walls(Entity *entity, const sf::Vector2f &direction) {
	sf::Sprite		player_copy = entity->getBody();
	sf::Vector2f	player_pos = player_copy.getPosition();
	player_copy.setPosition(player_pos - direction);
	for (auto it = this->_map.begin(); it != this->_map.end(); it++) {
		if ((*it)->intersect(player_copy.getGlobalBounds())) {
			return true;
		}
	}
	return false;
}
