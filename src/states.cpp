#include "states.hpp"
#include <algorithm>

OverworldState::OverworldState()
	: player(4, 4),
	  view(sf::FloatRect(0.0, 0.0, screenWidth, screenHeight)) {
}

void OverworldState::update(float dt, GameState &currentState) {
	player.update(dt, map, currentState);
}

void OverworldState::render(sf::RenderWindow &window) {
	int cx = player.x + tileSize / 2;
	int cy = player.y + tileSize;

	cx = std::clamp(cx, screenWidth / 2,
			mapWidth * tileSize - screenWidth / 2);
	cy = std::clamp(cy, screenHeight / 2,
			mapHeight * tileSize - screenHeight / 2);

	view.setCenter(cx, cy);

	window.setView(view);

	map.draw(window, cx - screenWidth / 2, cy - screenHeight / 2);
	player.draw(window);
}

BattleState::BattleState() {
}

void BattleState::update(float dt) {
	(void)dt;
}

void BattleState::render(sf::RenderWindow &window) {
	(void)window;
}