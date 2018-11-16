#pragma once

#include <string>

//forward declare
namespace sf
{
	class Sprite;
}

class Sprite
{
public:
	//constructor with filepath to the sprite file
	Sprite(std::string filePath);
	~Sprite();

public:
	//return the sprite for the window
	const std::shared_ptr<sf::Sprite> GetSprite() const { return m_Sprite; }
	//SetPosition the Sprite
	void SetPosition(const float X, const float Y);
	void GetPosition(float& X, float& Y);
	void SetRotation(const float rotationInDegree);
	void GetRotation(float& rotationInDegree);
	//check if this sprite is colliding with another Sprite
	const bool IsCollidingWith(const std::shared_ptr<Sprite>& otherSprite) const;
	const bool IsCollidingWith(const float top, const float left, const float width, const float height) const;

private:
	std::shared_ptr<sf::Sprite> m_Sprite = nullptr;
};