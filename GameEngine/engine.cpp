#include "engine.h"

Engine::Engine(const int width, const int height, std::string title)
{
	//this is called when the object is created
	m_isRunning = true;
	m_Window = new Window(width, height, title);
	m_Input = new Input();
	m_Time = new Time();
}

Engine::~Engine()
{
	//this is called when the object is destroyed
	m_isRunning = false;
	delete m_Input;
	delete m_Window;
	delete m_Time;
}

void Engine::Update()
{
	if (!m_Window->Update()) {
		m_isRunning = false;
		return;
	}

	m_Time->Restart();
}

void Engine::Draw()
{
	m_Window->BeginDraw();
	for (Sprite* sprites : m_Sprites)
	{
		m_Window->Draw(sprites);
	}
	m_Window->EndDraw();
}

Sprite* Engine::CreateSprite(std::string filepath)
{
	Sprite* sprite = new Sprite(filepath);
	m_Sprites.push_back(sprite);
	return sprite;
}

void Engine::DestroySprite(Sprite* sprite)
{
	m_Sprites.erase(std::remove(m_Sprites.begin(), m_Sprites.end(), sprite), m_Sprites.end());
	delete sprite;
}

bool Engine::IsKeyPressed(Key key)
{
	return m_Input->IsKeyPressed(key);
}

const float Engine::GetElapsedTimeAsSeconds()
{
	return m_Time->GetElapsedTimeAsSeconds();
}