#pragma once

#include <string>

namespace sf
{
	class Texture;
	class Sprite;
}

class Sprite
{
public:
	Sprite(std::string filepath);
	virtual ~Sprite();

	const sf::Sprite* Getsprite() { return m_Sprite; }
	void Move(float x, float y);
private:
	sf::Texture* m_Texture = nullptr;
	sf::Sprite* m_Sprite = nullptr;
};

