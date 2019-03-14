#pragma once

#include "common.hpp"
#include "map.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Player {
private:
	std::uniform_int_distribution<> battle_dis;

	sf::Texture texture;
	sf::Sprite sprite;
	Direction move = Direction::None;
	int frameNum = 1;
	int frameY = 3;
	sf::Clock animationTime;

public:
	float x, y;
	Player(int x, int y);
	void update(float dt, Map &map, GameState &currentState);
	void draw(sf::RenderWindow &window);
};