#include "Sprite.h"
#include <SFML/Graphics.hpp>



Sprite::Sprite(std::string filepath)
{
	//creates a new texture and load the file we pass
	m_Texture = new sf::Texture();
	m_Texture->loadFromFile(filepath);

	//dereference the pointer m_Texture, so that we can reference it
	sf::Texture& texture = *m_Texture;
	//generates a sprite from the texture reference
	m_Sprite = new sf::Sprite(texture);
}


Sprite::~Sprite()
{	
	//deletes sprite and textures when the sprite object is destroyed
	delete m_Sprite;
	delete m_Texture;
}

void Sprite::Move(float x, float y)
{
	//moves the sprite some pixels
	m_Sprite->move(x, y);
}
