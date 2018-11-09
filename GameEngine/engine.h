#pragma once

#include "Window.h"
#include <vector>
#include <algorithm>

class Engine
{
public:
	Engine(const int width, const int height, std::string title);
	~Engine();
	const bool isRunning() {
		return m_isRunning;
	}
	void Update();
	void Draw();
	Sprite* CreateSprite(std::string filepath);
	void DestroySprite(Sprite* sprite);
private:
	Window* m_Window = nullptr;
	bool m_isRunning = false;
	std::vector<Sprite*> m_Sprites;
};