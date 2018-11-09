#include "GameEngine/engine.h"

#ifdef _DEBUG
#define EngineMain main
#else
#define EngineMain WinMain
#endif

int EngineMain()
{
	Engine* engine = new Engine(640, 480, "Test");
	Sprite* sprite = engine->CreateSprite("smile.png");
	sprite->Move(360, 240);
	float accumolator = 0.f;
	const float dt = 1 / 60.f;
	while (engine->isRunning()) {
		engine->Update();

		const float deltaTime = engine->GetElapsedTimeAsSeconds();
		accumolator += deltaTime;
		while (accumolator >= dt)
		{
			if (engine->IsKeyPressed(Key::S))
			{
				sprite->Move(0, 100.0f * dt);
			}
			if (engine->IsKeyPressed(Key::W))
			{
				sprite->Move(0, -100.0f * dt);
			}
			if (engine->IsKeyPressed(Key::A))
			{
				sprite->Move(-100.0f * dt, 0);
			}
			if (engine->IsKeyPressed(Key::D))
			{
			sprite->Move(100.0f * dt, 0);
			}
			engine->Draw();
		}		
	}
	delete sprite;
	delete engine;
	return 0;
}
