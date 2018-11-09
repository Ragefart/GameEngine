#include "GameEngine/engine.h"

#ifdef _DEBUG
#define EngineMain main
#else
#define EngineMain WinMain
#endif

int EngineMain()
{
	return 0;
}
