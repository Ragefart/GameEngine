#pragma once

#include <GameEngine/ISystem.h>

class AsteroidSpawnSystem : public ISystem
{
public:
	AsteroidSpawnSystem();
	~AsteroidSpawnSystem();

public:
	//Override ISystem functions
	virtual bool DoesEntityMatch(std::shared_ptr<Entity>& entity) override;
	virtual void Update(Engine* engine, float dt) override;

	//max amount of asteroids we want to spawn
	void SetMaxAsteroids(const unsigned int maxAsteroids);
	//set the cooldown the asteroids spawn
	void SetSpawnCooldown(const float spawnCD);
	//set the max velocity an asteroid can have
	void SetMaxVelocity(const int velocity);
	//set the boundaries of the map so that we dont spawn an asteroid outside of it
	void SetBoundaries(const int max_X, const int max_Y);

private:
	unsigned int m_MaxAsteroids = 0;
	float m_CurrentSpawnCD = 0.f;
	float m_MaxSpawnCD = 0.f;
	int m_MaxVelocity = 0;
	int m_Max_X = 0;
	int m_Max_Y = 0;
};
