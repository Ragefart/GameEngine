#pragma once

#include "GameEngine/engine.h"
#include "Player.h"

class Bullet
{
public:
	Bullet(std::shared_ptr<Sprite>& sprite, const std::shared_ptr<Player>& player, const float boundary_X, const float boundary_Y);
	~Bullet();

public:
	//handle input and update the Bullet
	void Update(const float dt);

	std::shared_ptr<Sprite>& GetSprite() { return m_Sprite; }

	//check if the bullet should be destroyed now after his lifetime is over
	const bool IsLifeTimeOver() { return m_LifeTime < 0.0f; }
private:
	//sprite used to draw and change the position
	std::shared_ptr<Sprite> m_Sprite;
	//velocity of the bullet
	float m_Velocity_X = 0.f;
	float m_Velocity_Y = 0.f;
	//boundary of the map
	float m_Boundary_X = 0.f;
	float m_Boundary_Y = 0.f;
	//LifeTime of the bullet
	float m_LifeTime = 0.f;
};