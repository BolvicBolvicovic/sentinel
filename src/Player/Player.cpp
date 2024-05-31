#include "Player.hpp"

Player::Player(const string &name, Champion &champion): _name(name), _champion(champion) {
}

Player::~Player() {
}

void		Player::setChampionDest(const sf::Vector2f &vec) {
	this->_champion.setDest(vec);
}

sf::Sprite	&Player::getChampBody() {
	return this->_champion.getBody();
}

void		Player::updateChamp(Map *map) {
	this->_champion.updatePos(map);
}

void		Player::championAttack() {
	this->_champion.attack();
}

void		Player::championDies() {
	this->_champion.dies();
}
