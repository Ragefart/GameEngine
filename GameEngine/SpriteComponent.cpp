#include "SpriteComponent.h"
#include "TextureManager.h"
#include <SFML/Graphics.hpp>

SpriteComponent::SpriteComponent()
{
}

SpriteComponent::~SpriteComponent()
{
}

void SpriteComponent::CreateSprite(std::string filePath)
{
	//get the texture based on the filepath from the TextureManager
	std::shared_ptr<sf::Texture>& texture = TextureManager::GetInstance().GetTexture(filePath);
	m_Sprite = std::make_shared<sf::Sprite>(*texture);
	//set the origin of the sprite to the center of the texture
	m_Sprite->setOrigin(texture->getSize().x / 2, texture->getSize().y / 2);
}

void SpriteComponent::SetPosition(const float X, const float Y)
{
	//move the sprite some pixels
	m_Sprite->setPosition(X, Y);
}

void SpriteComponent::GetPosition(float& X, float& Y)
{
	X = m_Sprite->getPosition().x;
	Y = m_Sprite->getPosition().y;
}

void SpriteComponent::SetRotation(const float rotationInDegree)
{
	m_Sprite->setRotation(rotationInDegree);
}

void SpriteComponent::GetRotation(float& rotationInDegree)
{
	rotationInDegree = m_Sprite->getRotation();
}

const bool SpriteComponent::IsCollidingWith(const std::shared_ptr<SpriteComponent>& otherSprite) const
{
	const std::shared_ptr<sf::Sprite>& otherSFMLSprite = otherSprite->GetSprite();
	//get the global positions of the sprites
	const sf::FloatRect otherRect = otherSFMLSprite->getGlobalBounds();
	const sf::FloatRect thisRect = m_Sprite->getGlobalBounds();
	//check if the global positions intersect
	return thisRect.intersects(otherRect);
}

const bool SpriteComponent::IsCollidingWith(const float top, const float left, const float width, const float height) const
{
	const sf::FloatRect otherRect(left, top, width, height);
	const sf::FloatRect thisRect = m_Sprite->getGlobalBounds();
	return thisRect.intersects(otherRect);
}