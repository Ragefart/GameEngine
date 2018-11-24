#include "Player.h"
#include <algorithm>

Player::Player(std::shared_ptr<Sprite>& playerSprite, const float boundary_X, const float boundary_Y)
{
	m_Sprite = playerSprite;
	m_Boundary_X = boundary_X;
	m_Boundary_Y = boundary_Y;
}

Player::~Player()
{
}

void Player::SetPosition(const float X, const float Y)
{
	m_Sprite->SetPosition(X, Y);
}

void Player::GetPosition(float& X, float& Y) const
{
	m_Sprite->GetPosition(X, Y);
}

void Player::GetVelocity(float& velocity_X, float& velocity_Y) const
{
	velocity_X = m_Velocity_X;
	velocity_Y = m_Velocity_Y;
}

void Player::GetRotation(float& rotationInDegree) const
{
	 m_Sprite->GetRotation(rotationInDegree);
}

void Player::Update(const std::shared_ptr<Engine>& engine, const float dt)
{
	HandleInput(engine, dt);
	CalculateMovement(dt);
}

void Player::HandleInput(const std::shared_ptr<Engine>& engine, const float dt)
{
	float rotationInDegree = 0.f;
	float accelerationPerSecond = 10.0f;
	float rotationPerSecond = 200.0f;
	//Get the rotation of the player
	m_Sprite->GetRotation(rotationInDegree);

	//if A or S is pressed, change the rotation of the player
	if (engine->IsKeyPressed(Key::A))
	{
		rotationInDegree -= rotationPerSecond * dt;
	}
	else if (engine->IsKeyPressed(Key::D))
	{
		rotationInDegree += rotationPerSecond * dt;
	}
	m_Sprite->SetRotation(rotationInDegree);

	//if the player accelerates using the W key
	if (engine->IsKeyPressed(Key::W))
	{
		//calculate rotation in radians
		const float PI = 3.141592654f;
		//add +90 because the sprite is pointing to the right
		float rotationInRadians = (rotationInDegree+90) * PI / 180.0f;
		//accelerate into a specific direction using sin/cos with the rotationInRadians
		m_Velocity_X += sin(rotationInRadians) * accelerationPerSecond;
		m_Velocity_Y -= cos(rotationInRadians) * accelerationPerSecond;
	}

	if (m_ShootCooldown > 0)
	{
		//reduce shootcoldown by dt, and if it's less than zero, it will be set to zero
		m_ShootCooldown = std::max(0.f, m_ShootCooldown - dt);
	}

	if (m_IsShooting)
	{
		m_ShootCooldown = 0.25f;
	}

	m_IsShooting = engine->IsKeyPressed(Key::Space) && m_ShootCooldown == 0.0f;
}

void Player::CalculateMovement(const float dt)
{
	//calculate damping so that the velocity is slowed down over time
	float damping = 0.98f;
	m_Velocity_X *= damping;
	m_Velocity_Y *= damping;
	if (m_Velocity_X < 0.1 && m_Velocity_X > -0.1f) m_Velocity_X = 0.f;
	if (m_Velocity_Y < 0.1 && m_Velocity_Y > -0.1f) m_Velocity_Y = 0.f;

	//add velocity to the position of the sprite
	float X = 0.f;
	float Y = 0.f;
	m_Sprite->GetPosition(X, Y);
	X += m_Velocity_X * dt;
	Y += m_Velocity_Y * dt;
	//check if the player is outside of the boundaries, if so, move him to the other side
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