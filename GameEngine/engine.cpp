#include "engine.h"
#include <algorithm>

Engine::Engine(const int width, const int height, const std::string title)
{
	//this is called when the object is created
	m_IsRunning = true;
	m_Window = new Window(width, height, title);
	m_Input = new Input();
	m_Time = new Time();
}

Engine::~Engine()
{
	//this is called when the object is destroyed
	m_IsRunning = false;
	delete m_Input;
	delete m_Window;
	delete m_Time;
}

void Engine::Update()
{
	if (!m_Window->Update())
	{
		m_IsRunning = false;
		return;
	}

	m_Time->Restart();
}

void Engine::Draw()
{
	//clear and initialize rendering
	m_Window->BeginDraw();
	//go through each sprite and render it
	for (Sprite* sprite : m_Sprites)
	{
		//render the sprite for the window
		m_Window->Draw(sprite);
	}
	for (Text* text : m_Texts)
	{
		m_Window->Draw(text);
	}
	//display everything
	m_Window->EndDraw();
}

Sprite* Engine::CreateSprite(std::string filePath)
{
	Sprite* sprite = new Sprite(filePath);
	m_Sprites.push_back(sprite);
	return sprite;
}

void Engine::DestroySprite(Sprite* sprite)
{
	//remove the sprite from the vector
	m_Sprites.erase(std::remove(m_Sprites.begin(), m_Sprites.end(), sprite), m_Sprites.end());
	delete sprite;
}

bool Engine::IsKeyPressed(Key key)
{
	//ask input if the key has been pressed
	return m_Input->IsKeyPressed(key);
}

const float Engine::GetElapsedTimeAsSeconds()
{
	return m_Time->GetElapsedTimeAsSeconds();
}

Text* Engine::CreateText(std::string filePath)
{
	Text* text = new Text(filePath);
	m_Texts.push_back(text);
	return text;
}

void Engine::DestroyText(Text* text)
{
	//remove the text from the vector
	m_Texts.erase(std::remove(m_Texts.begin(), m_Texts.end(), text), m_Texts.end());
	delete text;
}