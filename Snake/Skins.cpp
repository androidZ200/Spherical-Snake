#include "Skins.h"

sf::Color SkinLight::ColorSegment(int index)
{
    if (index % 10 == 3)return sf::Color::Color(80, 80, 80);
    else return sf::Color::Color(180, 180, 180);
}

sf::Color SkinGreenWave::ColorSegment(int index)
{
    int s = 30 * std::sin(index / 3.0);
    return sf::Color::Color(60 + s, 170 + s, 60 + s);
}

sf::Color SkinBlueWave::ColorSegment(int index)
{
    int s = 70 * std::cos(index / 3.0);
    return sf::Color::Color(125 + s, 155 + s, 235);
}

ISkin* SkinGenerate::Generate()
{
    int i = rand() % 4;
    switch (i)
    {
    case 0: return new SkinLight();
    case 1: return new SkinGreenWave();
    case 2: return new SkinBlueWave();
    case 3: return new SkinLava();
    }
    return nullptr;
}

sf::Color SkinLava::ColorSegment(int index)
{
    double s = std::cos(index / 3.0);
    return sf::Color::Color(235 + s*20, 121 + s*111, 35 + s*35);
}
