#pragma once
#include <GameEngine/IComponent.h>


class PlayerComponent : public IComponent
{
public:
	PlayerComponent();
	~PlayerComponent();

public:
	//speed the player travels if he pressed a key
	void GetSpeedPerSecond(float& speedPerSecond);
	void SetSpeedPerSecond(float speedPerSecond);

	//rotation speed the player has if he rotates
	void GetRotationPerSecond(float& rotationPerSecond);
	void SetRotationPerSecond(float rotationPerSecond);

	//speed of a bullet
	void GetBulletSpeedPerSecond(float& bulletSpeedPerSecond);
	void SetBulletSpeedPerSecond(float bulletSpeedPerSecond);

	//cooldown until we can spawn another bullet
	void GetBulletSpawnCooldown(float& bulletSpawnCD);
	void SetBulletSpawnCooldown(float bulletSpawnCD);

	//cooldown that will reset the current bullet's spawn cooldown
	void GetBulletMaxSpawnCooldown(float& maxBulletSpawnCD);
	void SetBulletMaxSpawnCooldown(float maxBulletSpawnCD);
private:
	float m_SpeedPerSecond = 0.f;
	float m_RotationPerSecond = 0.f;
	float m_BulletSpeedPerSecond = 0.f;
	float m_BulletSpawnCooldown = 0.f;
	float m_MaxBulletSpawnCooldown = 0.f;
};
