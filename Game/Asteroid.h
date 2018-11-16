#pragma once

#include "GameEngine/engine.h"

class Asteroid
{
public:
	Asteroid(std::shared_ptr<Sprite> sprite, const float boundary_X, const float boundary_Y);
	~Asteroid();

public:
	//Set the position of the Asteroid
	void SetPosition(const float X, const float Y);
	//Set the rotation of the Asteroid
	void SetRotation(const float rotationInDegree);
	//Set the velocity of the Asteroid
	void SetVelocity(const float X, const float Y);
	//handle input and update the Asteroid
	void Update(const float dt);

	std::shared_ptr<Sprite> GetSprite() { return m_Sprite; }
private:
	//sprite used to draw and change the position
	std::shared_ptr<Sprite> m_Sprite;
	//velocity of the player
	float m_Velocity_X = 0.f;
	float m_Velocity_Y = 0.f;
	//boundary of the map
	float m_Boundary_X = 0.f;
	float m_Boundary_Y = 0.f;
};