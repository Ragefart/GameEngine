#include "Input.h"
#include <SFML/Window.hpp>



Input::Input()
{
}


Input::~Input()
{
}

bool Input::IsKeyPressed(Key key)
{
	sf::Keyboard::Key sfmlkey = (sf::Keyboard::Key)key;

	return sf::Keyboard::isKeyPressed(sfmlkey);
}