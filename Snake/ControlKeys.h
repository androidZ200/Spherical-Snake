#pragma once
#include "SFML/Graphics.hpp"

class ControlKeys
{
	sf::Keyboard::Key right;
	sf::Keyboard::Key left;

public:
	ControlKeys(sf::Keyboard::Key Right, sf::Keyboard::Key Left);

	const sf::Keyboard::Key& Right();
	const sf::Keyboard::Key& Left();
};