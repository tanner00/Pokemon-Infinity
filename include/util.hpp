#pragma once

#include <SFML/System.hpp>
#include <cmath>

enum class Direction {
	None,
	Left,
	Right,
	Up,
	Down,
};

constexpr int tileSize = 64;

constexpr int screenWidth = 960;
constexpr int screenWidthTiles = screenWidth / tileSize;

constexpr int screenHeight = 640;
constexpr int screenHeightTiles = screenHeight / tileSize;

sf::Vector2f directionToUnitVector(Direction d);
int toMultiple(int round, int multiple);