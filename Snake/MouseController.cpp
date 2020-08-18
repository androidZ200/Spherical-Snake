#include "MouseController.h"

double MouseController::GetMove()
{
    sf::Vector2i coord = sf::Mouse::getPosition() - window->getPosition();
    coord -= sf::Vector2i(window->getSize()) / 2;
    Vector y(2);
    y[0] = -coord.x;
    y[1] = coord.y;
    y.normalize();
    Vector x = snake->Front();
    double t = x[0] * y[1] - y[0] * x[1];
    return -t*2;
}

IController* MouseController::Copy()
{
    return new MouseController();
}

void MouseController::SetSnake(SnakeBody* snake)
{
    this->snake = snake;
}

void MouseController::SetWindow(sf::RenderWindow* window)
{
    this->window = window;
}
