#pragma once

#include "map.hpp"
#include "util.hpp"
#include <SFML/Graphics.hpp>

class Player {
private:
	sf::Sprite sprite;
	Direction move = Direction::None;
	std::uniform_int_distribution<> battle_dis;

public:
	float x, y;
	Player(int x, int y, sf::Texture &playerTexture);
	void update(float dt, Map &map);
	void draw(sf::RenderWindow &window);
};