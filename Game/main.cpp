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
	sprite->Move(30, 40);
	while (engine->isRunning()) {
		engine->Update();
		engine->Draw();
	}
	delete sprite;
	delete engine;
	return 0;
}
