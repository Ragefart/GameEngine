#include "Asteroid.h"

Asteroid::Asteroid(std::shared_ptr<Sprite>& sprite, const float boundary_X, const float boundary_Y)
{
	m_Sprite = sprite;
	m_Boundary_X = boundary_X;
	m_Boundary_Y = boundary_Y;
}

Asteroid::~Asteroid()
{
}

void Asteroid::SetPosition(const float X, const float Y)
{
	m_Sprite->SetPosition(X, Y);
}

void Asteroid::SetVelocity(const float X, const float Y)
{
	m_Velocity_X = X;
	m_Velocity_Y = Y;
}

void Asteroid::SetRotation(const float rotationInDegree)
{
	m_Sprite->SetRotation(rotationInDegree);
}

void Asteroid::Update(const float dt)
{
	//add velocity to the position of the sprite
	float X = 0.f;
	float Y = 0.f;
	m_Sprite->GetPosition(X, Y);
	X += m_Velocity_X * dt;
	Y += m_Velocity_Y * dt;
	//check if the Asteroid is outside of the boundaries, if so, move him to the other side
	if (X > m_Boundary_X)
	{
		X -= m_Boundary_X;
	}
	else if (X < 0)
	{
		X += m_Boundary_X;
	}
	if (Y > m_Boundary_Y)
	{
		Y -= m_Boundary_Y;
	}
	else if (Y < 0)
	{
		Y += m_Boundary_Y;
	}

	m_Sprite->SetPosition(X, Y);
}