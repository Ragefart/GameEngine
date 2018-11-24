#include "GameEngine/engine.h"
#include "GameEngine/Entity.h"
#include "GameEngine/SpriteComponent.h"
#include "PhysicComponent.h"
#include "PhysicSystem.h"
#include "PlayerSystem.h"
#include "BulletSystem.h"
#include "PlayerComponent.h"
#include "AsteroidSpawnSystem.h"
#include <memory>

#ifdef _DEBUG
#define EngineMain main
#else
#define EngineMain WinMain
#endif

int EngineMain()
{
	int windowWidth = 640;
	int windowHeight = 480;

	std::shared_ptr<Engine> engine = std::make_shared<Engine>(windowWidth, windowHeight, "Test");

	//create a new physic system and add it to the engine
	std::shared_ptr<PhysicSystem> physicSystem = std::make_shared<PhysicSystem>();
	physicSystem->SetBoundaries(windowWidth, windowHeight);
	engine->AddSystem(physicSystem);

	//create a new asteroid spawn system and add it to the engine
	std::shared_ptr<AsteroidSpawnSystem> asteroidSpawnSystem = std::make_shared<AsteroidSpawnSystem>();
	asteroidSpawnSystem->SetBoundaries(windowWidth, windowHeight);
	asteroidSpawnSystem->SetMaxVelocity(50);
	asteroidSpawnSystem->SetMaxAsteroids(10);
	asteroidSpawnSystem->SetSpawnCooldown(0.25f);
	engine->AddSystem(asteroidSpawnSystem);

	std::shared_ptr<PlayerSystem> playerSystem = std::make_shared<PlayerSystem>();
	engine->AddSystem(playerSystem);

	std::shared_ptr<BulletSystem> bulletSystem = std::make_shared<BulletSystem>();
	engine->AddSystem(bulletSystem);

	std::shared_ptr<Entity> playerEntity = std::make_shared<Entity>();
	//create and add a component
	std::shared_ptr<SpriteComponent> spriteComp = playerEntity->AddComponent<SpriteComponent>();
	std::shared_ptr<PhysicComponent> physicComp = playerEntity->AddComponent<PhysicComponent>();
	std::shared_ptr<PlayerComponent> playerComp = playerEntity->AddComponent<PlayerComponent>();
	//we set the data of the component
	spriteComp->CreateSprite("player.png");
	spriteComp->SetPosition(320, 200);
	physicComp->SetTargetFlag(AsteroidCollisionFlag);
	physicComp->SetDamping(0.98f);
	physicComp->SetVelocity(0.f, 0.0f);
	playerComp->SetSpeedPerSecond(10.0f);
	playerComp->SetRotationPerSecond(200.0f);
	playerComp->SetBulletSpeedPerSecond(200.0f);
	playerComp->SetBulletMaxSpawnCooldown(0.2f);
	//add the entity to the engine
	engine->AddEntity(playerEntity);

	bool gameEnd = false;
	while (engine->IsRunning())
	{
		//Update Engine
		engine->Update();
		engine->Draw();
	}

	//create a new sprite with the player image
	//std::shared_ptr<Sprite> backgroundSprite = engine->CreateSprite("background.png");
	//backgroundSprite->SetPosition(windowWidth / 2, windowHeight / 2);

	//std::shared_ptr<Sprite> playerSprite = engine->CreateSprite("player.png");
	//std::shared_ptr<Player> player = std::make_shared<Player>(playerSprite, windowWidth, windowHeight);

	////move the player image to the start position
	//player->SetPosition(320, 240);

	////initialize some asteroids
	//std::vector<std::shared_ptr<Asteroid>> asteroids;
	//const float maxSpawnCDForAsteroids = 1.0f;
	//const int maxAsteroidAmount = 10;
	//float spawnCDForAsteroids = 0.f;

	////our bullets we have created when the player is shooting
	//std::vector<std::shared_ptr<Bullet>> bullets;

	////create a new text with the custom font
	//std::shared_ptr<Text> text = engine->CreateText("Hyperspace.otf");
	//text->SetText("Score: "+std::to_string(score));
	//text->SetColor(255, 255, 255, 255);
	//text->SetPosition(10.0f, 10.0f);
	//text->SetSize(24);

	////Game Loop

	//float accumulator = 0.f;
	//const float dt = 1 / 60.0f;
	//bool isPlayerDead = false;
	//while (engine->IsRunning())
	//{
	//	//Update Engine
	//	engine->Update();

	//	const float deltaTime = engine->GetElapsedTimeAsSeconds();
	//	accumulator += deltaTime;
	//	while (accumulator >= dt)
	//	{
	//		if (isPlayerDead)
	//		{
	//			break;
	//		}

	//		player->Update(engine, dt);

	//		//check if player is shooting and if he is, add a new bullet to the vector
	//		if (player->IsShooting())
	//		{
	//			std::shared_ptr<Sprite> bulletSprite = engine->CreateSprite("bullet.png");
	//			std::shared_ptr<Bullet> bullet = std::make_shared<Bullet>(bulletSprite, player, windowWidth, windowHeight);
	//			bullets.push_back(bullet);
	//		}


	//		for (std::vector<std::shared_ptr<Bullet>>::iterator bulletItr = bullets.begin(); bulletItr != bullets.end();)
	//		{
	//			//update the bullet
	//			std::shared_ptr<Bullet>& bullet = (*bulletItr);
	//			bullet->Update(dt);

	//			//if the lifeTime is over, the bullet is always set to collide
	//			bool isColliding = bullet->IsLifeTimeOver();
	//			for (std::vector<std::shared_ptr<Asteroid>>::iterator asteroidItr = asteroids.begin(); asteroidItr != asteroids.end();)
	//			{
	//				std::shared_ptr<Asteroid>& asteroid = (*asteroidItr);
	//				if (bullet->GetSprite()->IsCollidingWith(asteroid->GetSprite()))
	//				{
	//					//if the bullet is colliding, destroy the asteroid
	//					isColliding = true;
	//					engine->DestroySprite(asteroid->GetSprite());
	//					asteroids.erase(asteroidItr);
	//					score += 10;
	//					text->SetText("Score: " + std::to_string(score));
	//					//break so that we don't check more asteroids
	//					break;
	//				}
	//				++asteroidItr;
	//			}
	//			//if the bullet is colliding, either through lifetimeIsOver or collision with the asteroid, delete him
	//			if (isColliding)
	//			{
	//				engine->DestroySprite(bullet->GetSprite());
	//				bulletItr = bullets.erase(bulletItr);
	//			}
	//			else
	//			{
	//				//bullet is not colliding and still alive, so iterate further
	//				++bulletItr;
	//			}
	//		}
	//		//if we have less asteroids spawned than the maxAsteroidAmount,
	//		//and if it's time to spawn an asteroid, we spawn it
	//		if (asteroids.size() < maxAsteroidAmount && spawnCDForAsteroids < 0.f)
	//		{
	//			const int maxVelocity = 100;
	//			const int collisionRange = 400;

	//			float X = std::rand() % windowWidth; //random number between 0 and windowWidth
	//			float Y = std::rand() % windowHeight; //random number between 0 and windowHeight
	//			float velocity_X = (std::rand() % maxVelocity * 2) - maxVelocity; //random number between -100 and 100
	//			float velocity_Y = (std::rand() % maxVelocity * 2) - maxVelocity; //random number between -100 and 100
	//			float rotation = std::rand() % 360; // random number between 0 and 360

	//			const int halfCollisionRange = collisionRange / 2;
	//			//check if our random position could collide with the player in a certain area
	//			//this way we can avoid that an asteroid is spawned in the area around the player, so that he would die instantly
	//			if (!player->GetSprite()->IsCollidingWith(X - halfCollisionRange, Y - halfCollisionRange, collisionRange, collisionRange))
	//			{
	//				std::shared_ptr<Sprite> asteroidSprite = engine->CreateSprite("asteroid1.png");
	//				std::shared_ptr<Asteroid> asteroid = std::make_shared<Asteroid>(asteroidSprite, windowWidth, windowHeight);
	//				asteroid->SetPosition(X, Y);
	//				asteroid->SetVelocity(velocity_X, velocity_Y);
	//				asteroid->SetRotation(rotation);

	//				asteroids.push_back(asteroid);

	//				//change the cooldown to the maxCooldown again, so we're resetting it
	//				spawnCDForAsteroids = maxSpawnCDForAsteroids;
	//			}
	//		}
	//		else
	//		{
	//			spawnCDForAsteroids -= dt;
	//		}

	//		for (std::shared_ptr<Asteroid>& asteroid : asteroids)
	//		{
	//			asteroid->Update(dt);
	//			if (player->GetSprite()->IsCollidingWith(asteroid->GetSprite()))
	//			{
	//				//delete player and playerSprite
	//				engine->DestroySprite(playerSprite);
	//				isPlayerDead = true;
	//				//Display Dead-Text
	//				text->SetText("You are dead");
	//				text->SetColor(255, 0, 0, 255);
	//				text->SetPosition(150.0f, 100.0f);
	//				text->SetSize(48);
	//				break;
	//			}
	//		}
	//		accumulator -= dt;
	//	}

	//	//draw every sprite created by the engine
	//	engine->Draw();
	//}

	//engine is destroyed and thus everything else is also destroyed

	return 0;
}
