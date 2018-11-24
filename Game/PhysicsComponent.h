#pragma once

#include "GameEngine/Icomponent.h"
#include <vector>
#include <memory>

class Entity;

static const unsigned char AsteroidCollisionFlag = 1 << 0;
static const unsigned char BulletCollisionFlag = 1 << 1;

class PhysicsComponent : public Icomponent
{
public:
	PhysicsComponent();
	~PhysicsComponent();

	void SetVelocity(const float x, const float y);
	void GetVelocity(float& x, float& y) const;
	void SetDamping(const float damping);
	void GetDamping(float& damping) const;

	void SetCollisions(int flag);
	void GetCollisions(int& flag) const;
	void SetCollisions(std::vector<std::shared_ptr<Entity>>& collisions);
	void GetCollisions(std::vector<std::shared_ptr<Entity>>& collisions);


	bool CanCollide(int& flag);

	void SetCollisionFlag(int flag);
	void SetTargetFlag(int flag);
	void GetCollisionflag(int& flag);
	void GetTargetFlag(int& flag);
private:
	float m_Velocity_X = 0.f;
	float m_Velocity_Y = 0.f;

	int m_CollisionFlag = 0;
	int m_TargetFlag = 0;

	float m_Damping = 0.f;

	std::vector<std::shared_ptr<Entity>> m_Collisions;
};

