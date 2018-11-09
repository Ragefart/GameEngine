#include "GameEngine/engine.h"

#ifdef _DEBUG
#define EngineMain main
#else
#define EngineMain WinMain
#endif

int EngineMain()
{
	Engine* engine = new Engine(640, 480, "Test");
	while (engine->isRunning()) {
		engine->Update();
	}
	delete engine;
	return 0;
}
