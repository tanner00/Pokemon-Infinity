#include "util.hpp"

sf::Vector2f directionToUnitVector(Direction d) {
	switch (d) {
	case Direction::Left:
		return sf::Vector2f(-1.0, 0.0);
	case Direction::Right:
		return sf::Vector2f(1.0, 0.0);
	case Direction::Up:
		return sf::Vector2f(0.0, -1.0);
	case Direction::Down:
		return sf::Vector2f(0.0, 1.0);
	case Direction::None:;
	}
	return sf::Vector2f(0.0, 0.0);
}

int toMultiple(int round, int multiple) {
	return std::lround((double)round / multiple) * multiple;
}