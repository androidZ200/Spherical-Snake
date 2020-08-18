#include "SphericalDrawer.h"

SphericalDrawer::SphericalDrawer(bool isSimple) : SFMLDrawer(isSimple) {}

SphericalDrawer::SphericalDrawer(int sizeWindow, bool isSimple) : SFMLDrawer(sizeWindow, isSimple) {}

SphericalDrawer::SphericalDrawer(const SphericalDrawer& other) : SFMLDrawer(other) {}

SFMLDrawer* SphericalDrawer::Copy()
{
	return new SphericalDrawer(*this);
}

void SphericalDrawer::DrawCircle(const Vector& coord, sf::Color col)
{
	const double L = 5;
	const Matrix& mat = snake->GetMatrix();
	double z = 0;
	for (int i = 0; i < mat.size(); ++i)
		z += mat(i, 2) * coord[i];
	if (z > 1/L) {
		double x = 0, y = 0;
		for (int i = 0; i < mat.size(); ++i) {
			x += mat(i, 0) * coord[i];
			y += mat(i, 1) * coord[i];
		}
		x = x / (L - z) * L;
		y = y / (L - z) * L;

		double l = sqrt(L * L + 1 - 2 * L * z);
		double R = 2 * radius * (L - 1) / l;

		cir.setOrigin(sf::Vector2f(R, R));
		cir.setScale((z * L - 1) / (L - 1), 1);
		cir.setRotation(-atan2(y, x) / acos(-1) * 180);

		cir.setRadius(R);
		cir.setPosition((x + 1.0) * sizeWindow / 2, (-y + 1.0) * sizeWindow / 2);
		cir.setFillColor(col);
		texture.draw(cir);
	}
}