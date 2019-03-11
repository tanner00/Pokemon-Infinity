#pragma once

#include "util.hpp"
#include <SFML/Graphics.hpp>

class Player {
private:
	float x, y;
	sf::RectangleShape rect;
	Direction move = Direction::None;

public:
	Player();
	void update(float dt);
	void draw(sf::RenderWindow &window);
};