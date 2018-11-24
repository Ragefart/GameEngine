#include "PhysicSystem.h"
#include "PhysicComponent.h"
#include <GameEngine/SpriteComponent.h>

PhysicSystem::PhysicSystem()
{

}

PhysicSystem::~PhysicSystem()
{

}

bool PhysicSystem::DoesEntityMatch(std::shared_ptr<Entity>& entity)
{
	//check if the entity has a spriteComponent and a physicComponent
	if (entity->HasComponent<SpriteComponent>() && entity->HasComponent<PhysicComponent>())
	{
		return true;
	}
	return false;
}

void PhysicSystem::Update(Engine* engine, float dt)
{
	//update the position for the entites
	for (std::vector<std::shared_ptr<Entity>>::iterator entityItr = m_Entities.begin(); entityItr != m_Entities.end();)
	{
 		std::shared_ptr<Entity> entity = *entityItr;
		UpdateSingleEntityPosition(entity, dt);
		++entityItr;
	}
	//seperately update the collision for the entities after the positions have been updated
	//this way we avoid that an entity has a collision but another doesn't
	for (std::vector<std::shared_ptr<Entity>>::iterator entityItr = m_Entities.begin(); entityItr != m_Entities.end();)
	{
		std::shared_ptr<Entity> entity = *entityItr;
		UpdateSingleEntityCollision(entity, dt);
		++entityItr;
	}
}

void PhysicSystem::SetBoundaries(const float max_X, const float max_Y)
{
	m_Max_X = max_X;
	m_Max_Y = max_Y;
}

void inline PhysicSystem::UpdateSingleEntityPosition(std::shared_ptr<Entity>& entity, float dt)
{
	std::shared_ptr<SpriteComponent> spriteComp = entity->GetComponent<SpriteComponent>();
	std::shared_ptr<PhysicComponent> physicComp = entity->GetComponent<PhysicComponent>();
	float X, Y = 0.f;
	float Vel_X, Vel_Y = 0.f;
	float damping = 0.f;
	spriteComp->GetPosition(X, Y);
	physicComp->GetVelocity(Vel_X, Vel_Y);
	physicComp->GetDamping(damping);
	
	Vel_X *= damping;
	Vel_Y *= damping;
	//just like in player previously, if the velocity is really small, make it zero
	if (Vel_X < 0.1f && Vel_X > -0.1f)
	{
		Vel_X = 0.f;
	}
	if (Vel_Y < 0.1f && Vel_Y > -0.1f)
	{
		Vel_Y = 0.f;
	}
	physicComp->SetVelocity(Vel_X, Vel_Y);

	//if the entity is no longer moving, we stop further calculations
	if (Vel_X == 0.f && Vel_Y == 0.f)
	{
		return;
	}
	//Update the Position based on the Velocity and dt
	X += Vel_X * dt;
	Y += Vel_Y * dt;
	//if the entity is outside of bounds, teleport him to the other side
	if (X < 0)
	{
		X = X + m_Max_X;
	}
	else if (X > m_Max_X)
	{
		X = X - m_Max_X;
	}
	if (Y < 0)
	{
		Y = Y + m_Max_Y;
	}
	else if (Y > m_Max_Y)
	{
		Y = Y - m_Max_Y;
	}
	//set the position
	spriteComp->SetPosition(X, Y);
}

void inline PhysicSystem::UpdateSingleEntityCollision(std::shared_ptr<Entity>& entity, float dt)
{
	std::shared_ptr<SpriteComponent> spriteComp = entity->GetComponent<SpriteComponent>();
	std::shared_ptr<PhysicComponent> physicComp = entity->GetComponent<PhysicComponent>();
	//define the vector of all collisions for this frame
	std::vector<std::shared_ptr<Entity>> collisions;
	//go through all entities to check for collisions
	for (std::vector<std::shared_ptr<Entity>>::iterator otherEntityItr = m_Entities.begin(); otherEntityItr != m_Entities.end();)
	{
		std::shared_ptr<Entity> otherEntity = *otherEntityItr;
		//we dont want to check collision for the same entity
		if (entity == otherEntity)
		{
			++otherEntityItr;
			continue;
		}
		//get the components of the otherEntity
		std::shared_ptr<SpriteComponent> otherSpriteComp = otherEntity->GetComponent<SpriteComponent>();
		std::shared_ptr<PhysicComponent> otherPhysicComp = otherEntity->GetComponent<PhysicComponent>();
		//get the collisionflag
		int otherCollisionFlag = 0;
		otherPhysicComp->GetCollisionFlag(otherCollisionFlag);
		//check if the collisionFlag matches the targetFlag of the entity
		//if they match, check if the sprites collides, if they collide, add them to the collisions vector
		if (physicComp->CanCollide(otherCollisionFlag) && spriteComp->IsCollidingWith(otherSpriteComp))
		{
			collisions.push_back(otherEntity);
		}
		++otherEntityItr;
	}
	//set the collisions vector
	physicComp->SetCollisions(collisions);
}