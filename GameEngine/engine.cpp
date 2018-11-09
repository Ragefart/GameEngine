#include "engine.h"

Engine::Engine(const int width, const int height, std::string title)
{
	//this is called when the object is created
	m_isRunning = true;
	m_Window = new Window(width, height, title);
}

Engine::~Engine()
{
	//this is called when the object is destroyed
	m_isRunning = false;
	delete m_Window;
}

void Engine::Update()
{
	if (!m_Window->Update()) {
		m_isRunning = false;
		return;
	}
}