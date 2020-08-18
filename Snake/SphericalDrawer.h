#pragma once
#include "SFMLDrawer.h"

class SphericalDrawer : public SFMLDrawer
{
public:
	SphericalDrawer(bool isSimple = false);
	SphericalDrawer(int sizeWindow, bool isSimple = false);
	SphericalDrawer(const SphericalDrawer& other);

	SFMLDrawer* Copy() override;
private:
	void DrawCircle(const Vector& coord, sf::Color col) override;
};