#include "map.hpp"
#include "FastNoise.h"
#include <cstdint>
#include <ctime>
#include <random>

Map::Map(sf::Texture &tileset) {
	FastNoise noise;
	noise.SetFrequency(0.04);

	std::uniform_int_distribution<> seed_dis(INT_MIN, INT_MAX);
	noise.SetSeed(seed_dis(ENG));

	for (int y = 0; y < mapHeight; ++y) {
		std::array<Tile, mapWidth> row;
		for (int x = 0; x < mapWidth; ++x) {
			Tile tile;
			tile.sprite.setTexture(tileset);
			tile.sprite.setPosition(x * tileSize, y * tileSize);

			int tid = grassTile;
			if (noise.GetNoise(x, y) < -0.35) {
				tid = bushTile;
			}
			tile.id = tid;

			tile.sprite.setTextureRect(
				sf::IntRect(tid * 16, 0, 16, 16));

			tile.sprite.setScale(
				sf::Vector2f(tileScale, tileScale));

			row[x] = tile;
		}
		tiles.push_back(row);
	}
}

void Map::draw(sf::RenderWindow &window) {
	for (auto &row : tiles) {
		for (auto &e : row) {
			window.draw(e.sprite);
		}
	}
}

int Map::getTileId(int tx, int ty) {
	return tiles[ty][tx].id;
}