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
	while (engine->isRunning()) {
		engine->Update();
		if (engine->IsKeyPressed(Key::S))
		{
			sprite->Move(0, 1.0f);
		}
		if (engine->IsKeyPressed(Key::W))
		{
			sprite->Move(0, -1.0f);
		}
		if (engine->IsKeyPressed(Key::A))
		{
			sprite->Move(-1.0f, 0);
		}
		if (engine->IsKeyPressed(Key::D))
		{
			sprite->Move(1.0f, 0);
		}
		engine->Draw();
	}
	delete sprite;
	delete engine;
	return 0;
}
