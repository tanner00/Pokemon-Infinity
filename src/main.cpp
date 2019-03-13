#include "map.hpp"
#include "player.hpp"
#include "util.hpp"
#include <SFML/Graphics.hpp>
#include <algorithm>

int main() {
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight),
				"Pokemon Infinity",
				sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(60);

	sf::Clock clock;

	sf::View view(sf::FloatRect(0.0, 0.0, screenWidth, screenHeight));

	sf::Texture tileset;
	tileset.loadFromFile("res/tiles.png");
	sf::Texture playerTexture;
	playerTexture.loadFromFile("res/player.png");

	Map map(tileset);
	Player player(4, 4, playerTexture);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		float dt = clock.restart().asSeconds();
		player.update(dt, map);

		int cx = player.x + 32;
		int cy = player.y + 32;
		cx = std::clamp(cx, screenWidth / 2,
				mapWidth * tileSize - screenWidth / 2);
		cy = std::clamp(cy, screenHeight / 2,
				mapHeight * tileSize - screenHeight / 2);
		view.setCenter(cx, cy);

		window.clear();

		window.setView(view);

		map.draw(window);
		player.draw(window);

		window.display();
	}

	return 0;
}