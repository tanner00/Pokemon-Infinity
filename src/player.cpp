#include "player.hpp"
#include <cmath>

Player::Player()
	: x(0), y(0),
	  rect(sf::RectangleShape(sf::Vector2f(tileSize, tileSize))) {
	rect.setFillColor(sf::Color::Blue);
	rect.setPosition(tileSize, tileSize);
}

void Player::update(float dt) {
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
	if ((move == Direction::Left || move == Direction::Right) &&
	    fabs(x - nextX) < 2.0) {
		x = nextX;
		move = Direction::None;
	}
	if ((move == Direction::Up || move == Direction::Down) &&
	    fabs(y - nextY) < 2.0) {
		y = nextY;
		move = Direction::None;
	}
}

void Player::draw(sf::RenderWindow &window) {
	rect.setPosition(x, y);

	window.draw(rect);
}