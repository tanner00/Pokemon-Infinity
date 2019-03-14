#pragma once

#include "map.hpp"
#include "player.hpp"
#include <SFML/Graphics.hpp>
#include <memory>

class OverworldState {
private:
	Map map;
	Player player;
	sf::View view;

public:
	OverworldState();
	void update(float dt, GameState &currentState);
	void render(sf::RenderWindow &window);
};

class BattleState {
public:
	BattleState();
	void update(float dt);
	void render(sf::RenderWindow &window);
};