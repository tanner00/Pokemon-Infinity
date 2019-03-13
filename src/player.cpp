#include "player.hpp"
#include <cmath>
#include <random>

Player::Player(int x, int y, sf::Texture &playerTexture)
	: battle_dis(0, 8), x(x * tileSize), y(y * tileSize) {
	sprite.setTexture(playerTexture);
	sprite.setPosition(x, y);
	sprite.setScale(sf::Vector2f(tileScale, tileScale));
}

#include <iostream>

void Player::update(float dt, Map &map) {
	if (move == Direction::None) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			move = Direction::Left;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			move = Direction::Right;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			move = Direction::Up;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			move = Direction::Down;
		}
	}

	x += directionToUnitVector(move).x * 150.0 * dt;
	y += directionToUnitVector(move).y * 150.0 * dt;

	int nextX = toMultiple((int)x, tileSize);
	int nextY = toMultiple((int)y, tileSize);
	bool newTile = false;
	if ((move == Direction::Left || move == Direction::Right) &&
	    fabs(x - nextX) < 2.0) {
		x = nextX;
		move = Direction::None;

		newTile = true;
	}
	if ((move == Direction::Up || move == Direction::Down) &&
	    fabs(y - nextY) < 2.0) {
		y = nextY;
		move = Direction::None;

		newTile = true;
	}

	if (newTile && map.getTileId(x / tileSize, y / tileSize) == bushTile &&
	    battle_dis(ENG) == 0) {
		std::cout << "BATTLE" << std::endl;
	}

	// center the character (it's too big for 64x64 tiles)
	sprite.setPosition(x + 5, y - 12);
}

void Player::draw(sf::RenderWindow &window) {
	window.draw(sprite);
}