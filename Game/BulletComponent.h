#pragma once

#include <GameEngine/IComponent.h>

class BulletComponent : public IComponent
{
public:
	BulletComponent();
	~BulletComponent();
public:
	//set the lifetime of the bullet how long it will exists without any collision
	void SetLifeTime(float lifeTime);
	void GetLifeTime(float& lifeTime);

private:
	float m_LifeTime = 0.f;
};