#include "map.hpp"
#include "FastNoise.h"
#include <algorithm>
#include <cassert>
#include <random>

void Map::placeTree(size_t tx, size_t ty) {
	assert(tx <= mapWidth - 2);
	assert(ty <= mapHeight - 3);
	for (int i = 0; i < 6; ++i) {
		tiles[i / 2 + ty][i % 2 + tx] = treeTileStart + i;
	}
}

Map::Map() {
	sf::Image tileset;
	tileset.loadFromFile("res/tiles.png");

	tilesetTexture.loadFromImage(tileset);
	for (unsigned int i = 0; i < tileset.getSize().x / tileSizeImage; ++i) {
		sf::Sprite tile;
		tile.setTexture(tilesetTexture);
		tile.setScale(sf::Vector2f(4.0, 4.0));
		tile.setTextureRect(sf::IntRect(i * tileSizeImage, 0,
						tileSizeImage, tileSizeImage));
		tileSprites.push_back(tile);
	}

	FastNoise noise;
	noise.SetFrequency(0.04);
	std::uniform_int_distribution<> seed_dis(INT_MIN, INT_MAX);
	noise.SetSeed(seed_dis(ENG));
	for (int y = 0; y < mapHeight; ++y) {
		std::array<int, mapWidth> row;
		for (int x = 0; x < mapWidth; ++x) {
			int tid = grassTile;
			if (noise.GetNoise(x, y) < -0.35) {
				tid = bushTile;
			}
			row[x] = tid;
		}
		tiles.push_back(row);
	}

	for (int x = 0; x < mapWidth; x += 2) {
		placeTree(x, 0);
		placeTree(x, mapHeight - 3);
	}
	for (int y = 0; y < mapHeight; y += 3) {
		placeTree(0, y);
		placeTree(mapWidth - 2, y);
	}
}

void Map::draw(sf::RenderWindow &window, int startX, int startY) {
	int startTileX = std::clamp(startX / tileSize, 0, mapWidth);
	int startTileY = std::clamp(startY / tileSize, 0, mapHeight);

	int endTileX =
		std::clamp(startTileX + screenWidthTiles + 1, 0, mapWidth);
	int endTileY =
		std::clamp(startTileY + screenHeightTiles + 1, 0, mapHeight);

	for (int x = startTileX; x < endTileX; ++x) {
		for (int y = startTileY; y < endTileY; ++y) {
			int t = tiles[y][x];
			tileSprites[t].setPosition(x * tileSize, y * tileSize);

			// under tree tiles
			if (t >= treeTileStart && t <= treeTileEnd) {
				tileSprites[grassTile].setPosition(
					x * tileSize, y * tileSize);
				window.draw(tileSprites[grassTile]);
			}

			window.draw(tileSprites[t]);
		}
	}
}

int Map::getTileId(size_t tx, size_t ty) {
	return tiles[ty][tx];
}
