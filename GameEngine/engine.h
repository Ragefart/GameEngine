#pragma once

#include "Window.h"

class Engine
{
public:
	Engine(const int width, const int height, std::string title);
	~Engine();
	const bool isRunning() {
		return m_isRunning;
	}
	void Update();
private:
	Window* m_Window = nullptr;
	bool m_isRunning = false;
};