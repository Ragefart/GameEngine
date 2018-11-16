#include "Input.h"
#include <SFML/Window.hpp>


bool Input::IsKeyPressed(Key key)
{
	//cast the key to a key which can be understand by sfml
	sf::Keyboard::Key sfmlKey = (sf::Keyboard::Key)key;
	//ask sfml directly if the specific key has been pressed, return true if yes
	return sf::Keyboard::isKeyPressed(sfmlKey);
}