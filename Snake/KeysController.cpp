#include "KeysController.h"

KeysController::KeysController()
{
	AddKeys(ControlKeys(sf::Keyboard::Key::Right, sf::Keyboard::Key::Left));
}

KeysController::KeysController(ControlKeys keys)
{
	AddKeys(keys);
}

KeysController::KeysController(const KeysController& other)
{
	keys = other.keys;
	t = other.t;
}

double KeysController::GetMove()
{
	for (auto x = keys.begin(); x != keys.end(); ++x) {
		if(sf::Keyboard::isKeyPressed(x->Right())) return -(t += 0.2);
		if(sf::Keyboard::isKeyPressed(x->Left())) return (t += 0.2);
	}
	t = 0;
	return 0;
}

IController* KeysController::Copy()
{
	return new KeysController(*this);
}

void KeysController::SetSnake(SnakeBody* snake)
{
}

void KeysController::SetWindow(sf::RenderWindow* window)
{
}

void KeysController::AddKeys(ControlKeys keys)
{
	this->keys.push_back(keys);
}

void KeysController::Clear()
{
	keys.clear();
}
