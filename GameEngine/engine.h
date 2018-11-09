#pragma once

#include "Window.h"
#include "Input.h"
#include "Time.h"
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

	bool IsKeyPressed(Key key);
	const float GetElapsedTimeAsSeconds();
private:
	Time* m_Time = nullptr;
	Window* m_Window = nullptr;
	bool m_isRunning = false;
	std::vector<Sprite*> m_Sprites;
	Input* m_Input = nullptr;
};