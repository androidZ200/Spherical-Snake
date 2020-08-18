#pragma once
#include "SFML/Graphics.hpp"
#include <cmath>

class ISkin {
public:
	virtual sf::Color ColorSegment(int index) = 0;
	virtual int IndexSkin() = 0;
};

class SkinGenerate {
public:
	static ISkin* Generate();
	static ISkin* toIndex(int indexSkin);
};

class SkinLight : public ISkin {
public:
	sf::Color ColorSegment(int index) override;
	int IndexSkin() override;
};

class SkinGreenWave : public ISkin {
public:
	sf::Color ColorSegment(int index) override;
	int IndexSkin() override;
};

class SkinBlueWave : public ISkin {
public:
	sf::Color ColorSegment(int index) override;
	int IndexSkin() override;
};

class SkinLava : public ISkin {
public:
	sf::Color ColorSegment(int index) override;
	int IndexSkin() override;
};

class SkinRanbow : public ISkin {
public:
	sf::Color ColorSegment(int index) override;
	int IndexSkin() override;
};