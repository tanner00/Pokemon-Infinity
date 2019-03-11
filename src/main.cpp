#include "player.hpp"
#include <SFML/Graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(960, 640), "Pokemon Infinity",
				sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(60);

	sf::Clock clock;

	Player player;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		float dt = clock.restart().asSeconds();
		player.update(dt);

		window.clear();
		player.draw(window);
		window.display();
	}

	return 0;
}