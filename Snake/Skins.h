#pragma once
#include "SFML/Graphics.hpp"
#include <cmath>

class ISkin {
public:
	virtual sf::Color ColorSegment(int index) = 0;
};

class SkinGenerate {
public:
	static ISkin* Generate();
};

class SkinLight : public ISkin {
public:
	sf::Color ColorSegment(int index) override;
};

class SkinGreenWave : public ISkin {
public:
	sf::Color ColorSegment(int index) override;
};

class SkinBlueWave : public ISkin {
public:
	sf::Color ColorSegment(int index) override;
};

class SkinLava : public ISkin {
public:
	sf::Color ColorSegment(int index) override;
};

class SkinRanbow : public ISkin {
public:
	sf::Color ColorSegment(int index) override;
};