#include "ControlKeys.h"

ControlKeys::ControlKeys(sf::Keyboard::Key Right, sf::Keyboard::Key Left)
{
	right = Right;
	left = Left;
}

const sf::Keyboard::Key& ControlKeys::Right()
{
	return right;
}

const sf::Keyboard::Key& ControlKeys::Left()
{
	return left;
}
