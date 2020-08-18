#pragma once
#include "SFMLDrawer.h"

class HyperDrawer : public SFMLDrawer
{
public:
	HyperDrawer(bool isSimple = false);
	HyperDrawer(int sizeWindow, bool isSimple = false);
	HyperDrawer(const HyperDrawer& other);

	SFMLDrawer* Copy() override;
private:
	void DrawCircle(const Vector& coord, sf::Color col) override;
};

