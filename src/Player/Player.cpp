#include "Player.hpp"

Player::Player(const string &name, Champion &champion): _name(name), _champion(champion) {
	cout << "A player has been summoned!" << endl;
}

Player::~Player() {
	cout << "A player has been deleted!" << endl;
}

void	Player::setChampionDest(const sf::Vector2f &vec) {
	this->_champion.setDest(vec);
}

sf::RectangleShape	&Player::getChampBody() {
	return this->_champion.getBody();
}

void	Player::updateChamp(Map *map) {
	this->_champion.updatePos(map);
}
