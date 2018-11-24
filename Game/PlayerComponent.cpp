#include "PlayerComponent.h"


PlayerComponent::PlayerComponent()
{

}

PlayerComponent::~PlayerComponent()
{

}

void PlayerComponent::GetSpeedPerSecond(float& speedPerSecond)
{
	speedPerSecond = m_SpeedPerSecond;
}

void PlayerComponent::SetSpeedPerSecond(float speedPerSecond)
{
	m_SpeedPerSecond = speedPerSecond;
}

void PlayerComponent::GetRotationPerSecond(float& rotationPerSecond)
{
	rotationPerSecond = m_RotationPerSecond;
}

void PlayerComponent::SetRotationPerSecond(float rotationPerSecond)
{
	m_RotationPerSecond = rotationPerSecond;
}

void PlayerComponent::GetBulletSpeedPerSecond(float& bulletSpeedPerSecond)
{
	bulletSpeedPerSecond = m_BulletSpeedPerSecond;
}

void PlayerComponent::SetBulletSpeedPerSecond(float bulletSpeedPerSecond)
{
	m_BulletSpeedPerSecond = bulletSpeedPerSecond;
}

void PlayerComponent::GetBulletSpawnCooldown(float& bulletSpawnCD)
{
	bulletSpawnCD = m_BulletSpawnCooldown;
}

void PlayerComponent::SetBulletSpawnCooldown(float bulletSpawnCD)
{
	m_BulletSpawnCooldown = bulletSpawnCD;
}

void PlayerComponent::GetBulletMaxSpawnCooldown(float& maxBulletSpawnCD)
{
	maxBulletSpawnCD = m_MaxBulletSpawnCooldown;
}

void PlayerComponent::SetBulletMaxSpawnCooldown(float maxBulletSpawnCD)
{
	m_MaxBulletSpawnCooldown = maxBulletSpawnCD;
}