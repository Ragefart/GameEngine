#include "PhysicComponent.h"
#include <GameEngine/Entity.h>

PhysicComponent::PhysicComponent()
{

}
PhysicComponent::~PhysicComponent()
{

}

void PhysicComponent::SetVelocity(const float X, const float Y)
{
	m_Velocity_X = X;
	m_Velocity_Y = Y;
}

void PhysicComponent::GetVelocity(float& X, float& Y) const
{
	X = m_Velocity_X;
	Y = m_Velocity_Y;
}

void PhysicComponent::SetDamping(const float damping)
{
	m_Damping = damping;
}

void PhysicComponent::GetDamping(float& damping) const
{
	damping = m_Damping;
}

void PhysicComponent::SetCollisions(std::vector<std::shared_ptr<Entity>>& collisions)
{
	m_Collisions = collisions;
}

void PhysicComponent::GetCollisions(std::vector<std::shared_ptr<Entity>>& collisions) const
{
	collisions = m_Collisions;
}

bool PhysicComponent::CanCollide(int& flag)
{
	return m_TargetFlag & flag;
}

void PhysicComponent::SetCollisionFlag(int flag)
{
	m_CollisionFlag = flag;
}
void PhysicComponent::GetCollisionFlag(int& flag)
{
	flag = m_CollisionFlag;
}

void PhysicComponent::SetTargetFlag(int flag)
{
	m_TargetFlag = flag;
}

void PhysicComponent::GetTargetFlag(int& flag) 
{
	flag = m_TargetFlag;
}