#include "lib.hpp"


inline void eventLoop(sf::RenderWindow &window, Player &player) {
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
						)
					);
				}
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Key::Escape) {
					window.close();
				}
				break;
			default:
				break;
		}
	}
}

int main() {
	sf::RenderWindow	window(sf::VideoMode(1920, 1080), "sentinel");
	
	Map		map;
	Player	player("Victor", map.getChamp());

	while (window.isOpen()) {

		eventLoop(window, player);
		player.updateChamp(&map);

		window.clear(sf::Color::Black);

		map.render(window);
		window.draw(player.getChampBody());
		window.display();
	}

	return 0;
}
