#pragma once

#include <GameEngine/IComponent.h>
#include <vector>
#include <memory>

//forward declare entity
class Entity;

static const unsigned char AsteroidCollisionFlag = 1 << 0;
static const unsigned char BulletCollisionFlag = 1 << 1;

class PhysicComponent : public IComponent
{
public:
	PhysicComponent();
	~PhysicComponent();
public:
	//Velocity the component moves every frame
	void SetVelocity(const float X, const float Y);
	void GetVelocity(float& X, float& Y) const;
	//damping that is applied to the velocity each frame
	void SetDamping(const float damping);
	void GetDamping(float& damping) const;
	//get and set the collisions for this component/entity
	void SetCollisions(std::vector<std::shared_ptr<Entity>>& collisions);
	void GetCollisions(std::vector<std::shared_ptr<Entity>>& collisions) const;
	//check if the flag masks our targetFlag, 
	//therefore the bit is set and there is a collision
	bool CanCollide(int& flag);
	//defines which components we can collide with
	void SetCollisionFlag(int flag);
	void GetCollisionFlag(int& flag);
	//defines which components we want to collide with
	void SetTargetFlag(int flag);
	void GetTargetFlag(int& flag);
private:
	float m_Velocity_X = 0.f;
	float m_Velocity_Y = 0.f;
	float m_Damping = 0.f;
	int m_CollisionFlag = 0;
	int m_TargetFlag = 0;
	std::vector<std::shared_ptr<Entity>> m_Collisions;
};