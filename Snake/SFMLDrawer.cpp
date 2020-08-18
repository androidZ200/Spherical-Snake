#include "SFMLDrawer.h"

SFMLDrawer::SFMLDrawer(bool isSimple)
{
	this->isSimple = isSimple;
	Init();
}

SFMLDrawer::SFMLDrawer(int sizeWindow, bool isSimple)
{
	this->sizeWindow = sizeWindow;
	this->isSimple = isSimple;
	Init();
}

SFMLDrawer::SFMLDrawer(const SFMLDrawer& other)
{
	sizeWindow = other.sizeWindow;
	isSimple = other.isSimple;
	Init();
	SetGame(other.game);
	SetSnake(other.snake);
}

SFMLDrawer::~SFMLDrawer()
{
	Dispose();
}

void SFMLDrawer::SetGame(IConstGame* game)
{
	this->game = game;
}

void SFMLDrawer::SetSnake(SnakeBody* snake)
{
	this->snake = snake;
}

sf::RenderWindow* SFMLDrawer::GetWindow()
{
	return window;
}

int SFMLDrawer::GetSizeWindow()
{
	return sizeWindow;
}

void SFMLDrawer::DrawFrame()
{
	texture.clear(sf::Color::Color(28, 28, 28));
	for (int j = 0; j < game->CountSnake(); j++) {
		int i = 0;
		for (auto x = game->GetSnake(j)->begin(); x != game->GetSnake(j)->end(); ++x, ++i)
			if (i % 2 == 1 || !isSimple)
				DrawCircle(*x, game->GetSnake(j)->GetColor(i));
	}
	for (int j = 0; j < game->CountEat(); j++)
		DrawCircle(*game->GetEatPosition(j), sf::Color::Red);
	texture.display();
	sf::Sprite sp;
	sp.setTexture(texture.getTexture());
	shader.setUniform("Radius", (float)window->getSize().x / 2);
	window->draw(sp, &shader);
	window->display();
	window->setTitle(std::to_string(snake->size()));
}

void SFMLDrawer::Init()
{
	shader.setUniform("texture", sf::Shader::CurrentTexture);
	shader.loadFromMemory("#version 330 core\n uniform sampler2D texture;\n uniform float Radius;\n" \
		"void main() {\n if ((gl_FragCoord.x - Radius) * (gl_FragCoord.x - Radius) + (gl_FragCoord.y - Radius) *" \
		"(gl_FragCoord.y - Radius) > Radius * Radius)\n	gl_FragColor = vec4(0.16, 0.16, 0.16, 1);\n else "\
		"gl_FragColor = texture2D(texture, gl_FragCoord.xy / (2*Radius));\n }", sf::Shader::Fragment);

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	settings.depthBits = 24;
	texture.create(sizeWindow, sizeWindow, settings);

	window = new sf::RenderWindow(sf::VideoMode(sizeWindow, sizeWindow), "");
	cir.setRadius(radius);
}

void SFMLDrawer::Dispose()
{
	window->close();
	delete window;
}