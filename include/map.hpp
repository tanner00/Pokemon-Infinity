#pragma once

#include "common.hpp"
#include <SFML/Graphics.hpp>
#include <array>
#include <cstdint>

constexpr int mapWidth = screenWidthTiles * 4;
constexpr int mapHeight = screenHeightTiles * 4;

constexpr int grassTile = 0;
constexpr int bushTile = 1;
constexpr int treeTileStart = 2;
constexpr int treeTileEnd = 7;

class Map {
private:
	sf::Texture tilesetTexture;
	std::vector<std::array<int, mapWidth>> tiles;
	std::vector<sf::Sprite> tileSprites;
	void placeTree(size_t tx, size_t ty);

public:
	Map();
	void draw(sf::RenderWindow &window, int startX, int startY);
	int getTileId(size_t tx, size_t ty);
};