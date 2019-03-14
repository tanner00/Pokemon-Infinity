#include "player.hpp"
#include <cmath>
#include <random>

constexpr int frameWidth = 15;
constexpr int frameHeight = 19;

constexpr float speed = 200.0;

Player::Player(int x, int y)
	: battle_dis(0, 10), x(x * tileSize), y(y * tileSize) {
	texture.loadFromFile("res/player.png");

	sprite.setTexture(texture);
	sprite.setScale(sf::Vector2f(tileScale, tileScale));
	sprite.setTextureRect(sf::IntRect(frameNum * frameWidth,
					  frameY * frameHeight, frameWidth,
					  frameHeight));
}

void Player::update(float dt, Map &map, GameState &currentState) {
	if (move == Direction::None) {
		// very repetitive but I think any half readable attempts to
		// reduce this section will just bloat other sections.

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			// maps always surrounded with trees so no need to
			// bounds check these getTileId's
			int nextTile =
				map.getTileId(x / tileSize - 1, y / tileSize);
			if (nextTile == bushTile || nextTile == grassTile) {
				move = Direction::Left;
			}
			frameY = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			int nextTile =
				map.getTileId(x / tileSize + 1, y / tileSize);
			if (nextTile == bushTile || nextTile == grassTile) {
				move = Direction::Right;
			}
			frameY = 1;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			int nextTile =
				map.getTileId(x / tileSize, y / tileSize - 1);
			if (nextTile == bushTile || nextTile == grassTile) {
				move = Direction::Up;
			}
			frameY = 2;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			int nextTile =
				map.getTileId(x / tileSize, y / tileSize + 1);
			if (nextTile == bushTile || nextTile == grassTile) {
				move = Direction::Down;
			}
			frameY = 3;
		}

		if (move == Direction::None) {
			frameNum = 1;
			sprite.setTextureRect(sf::IntRect(
				frameNum * frameWidth, frameY * frameHeight,
				frameWidth, frameHeight));
		}
	}

	sf::Vector2i duv = directionToUnitVector(move);
	x += duv.x * speed * dt;
	y += duv.y * speed * dt;

	int nextX = toMultiple((int)x, tileSize);
	int nextY = toMultiple((int)y, tileSize);
	bool newTile = false;
	// @TODO: if you slow the game down enough you can mess this up.
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
		currentState = GameState::Battle;
	}

	// center the character (it's too big for 64x64 tiles)
	sprite.setPosition(x + 5, y - 12);
}

void Player::draw(sf::RenderWindow &window) {
	if (move != Direction::None) {
		auto time = animationTime.getElapsedTime().asMilliseconds();

		if (time >= 200) {
			frameNum = (frameNum + 1) % 3;
			animationTime.restart();
		}

		sprite.setTextureRect(sf::IntRect(frameNum * frameWidth,
						  frameY * frameHeight,
						  frameWidth, frameHeight));
	}

	window.draw(sprite);
}