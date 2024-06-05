#include "lib.hpp"

inline void eventLoop(sf::RenderWindow& window, Player& player, Map* map) {
	sf::Event	event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
		switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Button::Left) {
					player.setChampionDest(
						sf::Vector2f(
							event.mouseButton.x,
							event.mouseButton.y
						),
						map
					);
				}
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Key::Escape) {
					window.close();
				}
				if (event.key.code == sf::Keyboard::Key::A) {
					player.championAttack();
				}
				if (event.key.code == sf::Keyboard::Key::K) {
					player.championDies();
				}
				break;
			default:
				break;
		}
	}
}

int main() {
	sf::RenderWindow	window(sf::VideoMode(800, 800), "sentinel");
	
	Map		map;
	Player	player("Victor", map.getChamp());
	while (window.isOpen()) {

		eventLoop(window, player, &map);
		player.updateChamp(&map);

		window.clear(sf::Color::Black);

		map.render(window);
		window.draw(player.getChampBody());
		window.display();
	}

	return 0;
}
