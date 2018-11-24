#include "PlayerSystem.h"
#include "PlayerComponent.h"
#include "BulletComponent.h"
#include <GameEngine/engine.h>
#include <GameEngine/SpriteComponent.h>
#include "PhysicComponent.h"
#include <algorithm>


PlayerSystem::PlayerSystem()
{

}

PlayerSystem::~PlayerSystem()
{

}

bool PlayerSystem::DoesEntityMatch(std::shared_ptr<Entity>& entity)
{
	if (entity->HasComponent<PlayerComponent>())
	{
		return true;
	}
	return false;
}

void PlayerSystem::Update(Engine* engine, float dt)
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
			//because we created a copied vector, we are still iterating through all entities, so we don't worry about removed entities
			engine->RemoveEntity(entity);
		}
		++entityItr;
	}
}

bool inline PlayerSystem::UpdateEntity(Engine* engine, std::shared_ptr<Entity> entity, float dt)
{
	//get the components we'll use
	std::shared_ptr<PlayerComponent> playerComp = entity->GetComponent<PlayerComponent>();
	std::shared_ptr<PhysicComponent> physicComp = entity->GetComponent<PhysicComponent>();
	std::shared_ptr<SpriteComponent> spriteComp = entity->GetComponent<SpriteComponent>();
	//get the data of the components
	float speedPerSecond = 0.f;
	float rotationPerSecond = 0.f;
	float Vel_X, Vel_Y = 0.f;
	float player_X, player_Y = 0.f;
	float rotationInDegree = 0.f;
	float bulletSpawnCD = 0.f;
	float maxBulletSpawnCD = 0.f;
	float bulletSpeedPerSecond = 0.f;

	playerComp->GetSpeedPerSecond(speedPerSecond);
	playerComp->GetRotationPerSecond(rotationPerSecond);
	playerComp->GetBulletSpawnCooldown(bulletSpawnCD);
	playerComp->GetBulletMaxSpawnCooldown(maxBulletSpawnCD);
	playerComp->GetBulletSpeedPerSecond(bulletSpeedPerSecond);

	physicComp->GetVelocity(Vel_X, Vel_Y);

	spriteComp->GetRotation(rotationInDegree);
	spriteComp->GetPosition(player_X, player_Y);

	//Handle Input for rotation
	if (engine->IsKeyPressed(Key::A))
	{
		rotationInDegree -= rotationPerSecond * dt;
	}
	else if (engine->IsKeyPressed(Key::D))
	{
		rotationInDegree += rotationPerSecond * dt;
	}
	spriteComp->SetRotation(rotationInDegree);

	//calculate rotation in radians
	const float PI = 3.141592654f;
	//add +90 because the sprite is pointing to the right
	float rotationInRadians = (rotationInDegree + 90) * PI / 180.0f;
	//if the player accelerates using the W key
	if (engine->IsKeyPressed(Key::W))
	{
		//accelerate into a specific direction using sin/cos with the rotationInRadians
		Vel_X += sin(rotationInRadians) * speedPerSecond;
		Vel_Y -= cos(rotationInRadians) * speedPerSecond;
		//set the velocity
		physicComp->SetVelocity(Vel_X, Vel_Y);
	}

	if (bulletSpawnCD > 0)
	{
		bulletSpawnCD = std::max(0.f, bulletSpawnCD - dt);
	}

	if (engine->IsKeyPressed(Key::Space) && bulletSpawnCD <= 0.f)
	{
		//reset the cooldown
		bulletSpawnCD = maxBulletSpawnCD;

		//define the velocity of the bullet
		float bulletVelocity_X = sin(rotationInRadians) * bulletSpeedPerSecond;
		float bulletVelocity_Y = -cos(rotationInRadians) * bulletSpeedPerSecond;
		
		//create a new bullet entity
		std::shared_ptr<Entity> bulletEntity = std::make_shared<Entity>();
		std::shared_ptr<SpriteComponent> bulletSprite = bulletEntity->AddComponent<SpriteComponent>();
		std::shared_ptr<PhysicComponent> bulletPhysic = bulletEntity->AddComponent<PhysicComponent>();
		std::shared_ptr<BulletComponent> bulletComp = bulletEntity->AddComponent<BulletComponent>();

		//set the values of the components
		bulletSprite->CreateSprite("bullet.png");
		bulletSprite->SetPosition(player_X, player_Y);
		bulletPhysic->SetVelocity(bulletVelocity_X, bulletVelocity_Y);
		bulletPhysic->SetTargetFlag(AsteroidCollisionFlag);
		bulletPhysic->SetCollisionFlag(BulletCollisionFlag);
		bulletPhysic->SetDamping(1.0f);
		bulletComp->SetLifeTime(1.0f);

		//add the entity to the engine
		engine->AddEntity(bulletEntity);
	}

	//set the cooldown
	playerComp->SetBulletSpawnCooldown(bulletSpawnCD);

	//check for collisions with asteroids
	std::vector<std::shared_ptr<Entity>> collisions;
	physicComp->GetCollisions(collisions);
	if (collisions.size() == 0)
	{
		return true;
	}

	//the player collided with an asteroid
	return false;
}
