#include "BulletSystem.h"
#include "BulletComponent.h"
#include "PhysicComponent.h"
#include <GameEngine/engine.h>

BulletSystem::BulletSystem()
{

}

BulletSystem::~BulletSystem()
{

}

bool BulletSystem::DoesEntityMatch(std::shared_ptr<Entity>& entity)
{
	if (entity->HasComponent<BulletComponent>())
	{
		return true;
	}
	return false;
}

void BulletSystem::Update(Engine* engine, float dt)
{
	if (m_Entities.size() == 0)
	{
		return;
	}
	//copy all entities, so that we can iterate through all without worring about them getting deleted during the for loop
	std::vector<std::shared_ptr<Entity>> copiedEntities = m_Entities;
	for (std::vector<std::shared_ptr<Entity>>::iterator entityItr = copiedEntities.begin(); entityItr != copiedEntities.end();)
	{
		std::shared_ptr<Entity> entity = *entityItr;
		//if the entity should be removed
		if (!UpdateEntity(engine, entity, dt))
		{
			//remove him from the engine
			//because we created a copied vector, we are still iterating through all entities
			engine->RemoveEntity(entity);
		}
		++entityItr;
	}
}

bool inline BulletSystem::UpdateEntity(Engine* engine, std::shared_ptr<Entity> entity, float dt)
{
	//get the components we'll use
	std::shared_ptr<BulletComponent> bulletComp = entity->GetComponent<BulletComponent>();
	std::shared_ptr<PhysicComponent> physicComp = entity->GetComponent<PhysicComponent>();
	//get the data of the components
	float lifeTime = 0.f;
	bulletComp->GetLifeTime(lifeTime);
	//handle the data, decrease lifetime by dt
	lifeTime -= dt;
	if (lifeTime <= 0.f)
	{
		//lifetime is less than zero, so bullet's time is over
		return false;
	}
	//bullet is still alive so set the lifeTime
	bulletComp->SetLifeTime(lifeTime);

	//if there is a collision happening, bullet should die too
	std::vector<std::shared_ptr<Entity>> collisions;
	physicComp->GetCollisions(collisions);
	if (collisions.size() == 0)
	{
		//no collision and lifetime is not over, so we can return true so that the bullet is not removed
		return true;
	}
	//a collision is happening, we delete the first asteroid, because one bullet should only destroy one asteroid
	std::shared_ptr<Entity>& firstCollision = collisions[0];
	engine->RemoveEntity(firstCollision);
	//return false to destroy the bullet too
	return false;
}