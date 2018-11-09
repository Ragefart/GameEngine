#include "GameEngine/engine.h"

#ifdef _DEBUG
#define EngineMain main
#else
#define EngineMain WinMain
#endif

int EngineMain()
{
	int a = 5;
	
	Engine* engine = new Engine();

	Engine& engineRef = engine;

	delete engine;

	return 0;
}
