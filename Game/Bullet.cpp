#include "Bullet.h"

Bullet::Bullet(std::shared_ptr<Sprite> sprite, const std::shared_ptr<Player>& player, const float boundary_X, const float boundary_Y)
{
	m_Sprite = sprite;
	m_Boundary_X = boundary_X;
	m_Boundary_Y = boundary_Y;
	m_LifeTime = 3.0f;

	//also initialize the velocity based on the player
	const float PI = 3.141592654f;
	const float bulletSpeedPerSecond = 200.0f;
	
	//we get the values from the player
	float rotationInDegree = 0.f;
	float pX = 0.f;
	float pY = 0.f;
	player->GetRotation(rotationInDegree);
	player->GetPosition(pX, pY);

	//calculate players rotation in radians
	float rotationInRadians = (rotationInDegree+90) * PI / 180.0f;
	//we calculate the velocity of the bullet and add a custom speed factor it
	m_Velocity_X = (sin(rotationInRadians) * bulletSpeedPerSecond);
	m_Velocity_Y = (-cos(rotationInRadians) * bulletSpeedPerSecond);
	//set the position of the bullet to the position of the player but one step further
	float x = pX;
	float y = pY;
	//set the position
	m_Sprite->SetPosition(x, y);
}

Bullet::~Bullet()
{

}

void Bullet::Update(const float dt)
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
	m_LifeTime -= dt;
}