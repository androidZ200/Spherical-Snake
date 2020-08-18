#include "HyperDrawer.h"

HyperDrawer::HyperDrawer(bool isSimple) : SFMLDrawer(isSimple) {}

HyperDrawer::HyperDrawer(int sizeWindow, bool isSimple) : SFMLDrawer(sizeWindow, isSimple) {}

HyperDrawer::HyperDrawer(const HyperDrawer& other) : SFMLDrawer(other) {}

SFMLDrawer* HyperDrawer::Copy()
{
	return new HyperDrawer(*this);
}

void HyperDrawer::DrawCircle(const Vector& coord, sf::Color col)
{
	const Matrix& mat = snake->GetMatrix();
	double len = 0;
	for (int i = 0; i < mat.size(); ++i)
		len += mat(i, 2) * coord[i];
	len = acos(len);
	if (len < 1.82) {
		double x = 0, y = 0;
		for (int i = 0; i < mat.size(); ++i) {
			x += mat(i, 0) * coord[i];
			y += mat(i, 1) * coord[i];
		}
		if (len > 0.1) {
			double t = sqrt(x * x + y * y);
			x = x * len / t;
			y = y * len / t;
		}
		double R = 0;
		if (len < 0.1) R = radius;
		else R = radius * len / sin(len);

		cir.setRadius(R);
		cir.setPosition((x + 1.75) * sizeWindow / 3.5 - R, (-y + 1.75) * sizeWindow / 3.5 - R);
		cir.setFillColor(col);
		texture.draw(cir);
	}
}
