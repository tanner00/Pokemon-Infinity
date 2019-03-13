#pragma once

#include "util.hpp"
#include <SFML/Graphics.hpp>
#include <array>

constexpr int mapWidth = screenWidthTiles * 2;
constexpr int mapHeight = screenHeightTiles * 2;

constexpr int grassTile = 0;
constexpr int bushTile = 1;
struct Tile {
	int id;
	sf::Sprite sprite;
};

class Map {
private:
	std::vector<std::array<Tile, mapWidth>> tiles;

public:
	Map(sf::Texture &tileset);
	void draw(sf::RenderWindow &window);
	int getTileId(int tx, int ty);
};