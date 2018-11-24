#include "PhysicsComponent.h"



PhysicsComponent::PhysicsComponent()
{
}


PhysicsComponent::~PhysicsComponent()
{
}

void PhysicsComponent::SetVelocity(const float x, const float y)
{
	m_Velocity_X = x;
	m_Velocity_Y = y;
}

void PhysicsComponent::GetVelocity(float & x, float & y) const
{
	x = m_Velocity_X;
	y = m_Velocity_Y;
}

void PhysicsComponent::SetDamping(const float damping)
{
	m_Damping = damping;
}

void PhysicsComponent::GetDamping(float & damping) const
{
	damping = m_Damping;
}

void PhysicsComponent::SetCollisions(int flag)
{
	m_CollisionFlag = flag;
}

void PhysicsComponent::GetCollisions(int& flag) const
{
	flag = m_CollisionFlag;
}

void PhysicsComponent::SetCollisions(std::vector<std::shared_ptr<Entity>>& collisions)
{
	m_Collisions = collisions;
}

void PhysicsComponent::GetCollisions(std::vector<std::shared_ptr<Entity>>& collisions)
{
	collisions = m_Collisions;
}

bool PhysicsComponent::CanCollide(int& flag)
{
	return m_TargetFlag & flag;
}

void PhysicsComponent::SetCollisionFlag(int flag)
{
	m_CollisionFlag = flag;
}

void PhysicsComponent::SetTargetFlag(int flag)
{
	m_TargetFlag = flag;
}

void PhysicsComponent::GetCollisionflag(int & flag)
{
	flag = m_CollisionFlag;
}

void PhysicsComponent::GetTargetFlag(int & flag)
{
	flag = m_TargetFlag;
}
