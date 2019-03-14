#pragma once

#include <SFML/System.hpp>
#include <cmath>
#include <ctime>
#include <random>

enum class Direction {
	None,
	Left,
	Right,
	Up,
	Down,
};

enum class GameState {
	Overworld,
	Battle,
};

static std::mt19937 ENG(time(NULL));

constexpr int tileSize = 64;
constexpr int tileScale = 4;
constexpr int tileSizeImage = tileSize / tileScale;

constexpr int screenWidth = 1344;
constexpr int screenWidthTiles = screenWidth / tileSize;

constexpr int screenHeight = 768;
constexpr int screenHeightTiles = screenHeight / tileSize;

sf::Vector2i directionToUnitVector(Direction d);
int toMultiple(int round, int multiple);