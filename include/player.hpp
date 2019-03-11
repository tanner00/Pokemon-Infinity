#pragma once

#include <SFML/Graphics.hpp>

enum class Direction {
	None,
	Left,
	Right,
	Up,
	Down,
};

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