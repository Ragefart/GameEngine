#include "BulletComponent.h"

BulletComponent::BulletComponent()
{

}

BulletComponent::~BulletComponent()
{

}

void BulletComponent::GetLifeTime(float& lifeTime)
{
	lifeTime = m_LifeTime;
}

void BulletComponent::SetLifeTime(float lifeTime)
{
	m_LifeTime = lifeTime;
}