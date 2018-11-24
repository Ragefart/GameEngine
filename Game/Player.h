#pragma once

#include "GameEngine/engine.h"

class Player
{
public:
	Player(std::shared_ptr<Sprite>& playerSprite, const float boundary_X, const float boundary_Y);
	~Player();

public:
	//Set the position of the player
	void SetPosition(const float X, const float Y);
	//handle input and update the player
	void Update(const std::shared_ptr<Engine>& engine, const float dt);

	//getter functions to return the position, velocity and rotation of the player
	void GetPosition(float& X, float& Y) const;
	void GetVelocity(float& velocity_X, float& velocity_Y) const;
	void GetRotation(float& rotationInDegree) const;

	std::shared_ptr<Sprite>& GetSprite() { return m_Sprite;  }
	const bool IsShooting() { return m_IsShooting; }

private:
	void HandleInput(const std::shared_ptr<Engine>& engine, const float dt);
	void CalculateMovement(const float dt);

private:
	//sprite used to draw and change the position
	std::shared_ptr<Sprite> m_Sprite;
	//velocity of the player
	float m_Velocity_X = 0.f;
	float m_Velocity_Y = 0.f;
	//boundary of the map
	float m_Boundary_X = 0.f;
	float m_Boundary_Y = 0.f;
	//cooldown so that the player doesn't shoot everyframe
	float m_ShootCooldown = 0.f;
	bool m_IsShooting = false;
};