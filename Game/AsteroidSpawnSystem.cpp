#include "AsteroidSpawnSystem.h"
#include <GameEngine/engine.h>
#include <GameEngine/SpriteComponent.h>
#include "PhysicComponent.h"
#include "AsteroidComponent.h"

AsteroidSpawnSystem::AsteroidSpawnSystem()
{

}
AsteroidSpawnSystem::~AsteroidSpawnSystem()
{

}

bool AsteroidSpawnSystem::DoesEntityMatch(std::shared_ptr<Entity>& entity)
{
	if (entity->HasComponent<AsteroidComponent>())
	{
		return true;
	}
	return false;
}

void AsteroidSpawnSystem::Update(Engine* engine, float dt)
{
	//dont spawn more if we already have enough
	if (m_Entities.size() == m_MaxAsteroids)
	{
		return;
	}

	//if the spawnCooldown is not equal or less zero, decrease it and return
	if (m_CurrentSpawnCD >= 0.f)
	{
		m_CurrentSpawnCD -= dt;
		return;
	}
	//currentspawnCD is zero so set it to the max again
	m_CurrentSpawnCD = m_MaxSpawnCD;

	//now we'll spawn a new entity
	std::shared_ptr<Entity> entity = std::make_shared<Entity>();
	std::shared_ptr<SpriteComponent> spriteComp = entity->AddComponent<SpriteComponent>();
	std::shared_ptr<PhysicComponent> physicComp = entity->AddComponent<PhysicComponent>();
	std::shared_ptr<AsteroidComponent> asteroidComp = entity->AddComponent<AsteroidComponent>();

	//and then we just set all values, like position, velocity
	float x = (float)(std::rand() % m_Max_X);
	float y = (float)(std::rand() % m_Max_Y);
	float xVelocity = (float)((std::rand() % m_MaxVelocity * 2) - m_MaxVelocity);
	float yVelocity = (float)((std::rand() % m_MaxVelocity * 2) - m_MaxVelocity);
	float rotationInDegree = (float)(std::rand() % 360);

	//set all components with the values we have set before
	spriteComp->CreateSprite("asteroid1.png");
	spriteComp->SetPosition(x, y);
	spriteComp->SetRotation(rotationInDegree);
	physicComp->SetVelocity(xVelocity, yVelocity);
	physicComp->SetDamping(1.0f);
	physicComp->SetCollisionFlag(AsteroidCollisionFlag | BulletCollisionFlag);

	//add the entity to the engine, thus also adding it into the System
	engine->AddEntity(entity);
}

void AsteroidSpawnSystem::SetMaxAsteroids(const unsigned int maxAsteroids)
{
	m_MaxAsteroids = maxAsteroids;
}

void AsteroidSpawnSystem::SetSpawnCooldown(const float spawnCD)
{
	m_MaxSpawnCD = spawnCD;
}

void AsteroidSpawnSystem::SetMaxVelocity(const int velocity)
{
	m_MaxVelocity = velocity;
}

void AsteroidSpawnSystem::SetBoundaries(const int max_X, const int max_Y)
{
	m_Max_X = max_X;
	m_Max_Y = max_Y;
}