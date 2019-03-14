#include "states.hpp"
#include <SFML/Graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight),
				"Pokemon Infinity");
	window.setFramerateLimit(60);

	sf::Clock clock;

	OverworldState overworld;
	GameState currentState = GameState::Overworld;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		float dt = clock.restart().asSeconds();

		if (currentState == GameState::Overworld) {
			overworld.update(dt, currentState);
		} else if (currentState == GameState::Battle) {
		}

		window.clear();

		if (currentState == GameState::Overworld) {
			overworld.render(window);
		} else if (currentState == GameState::Battle) {
		}

		window.display();
	}

	return 0;
}