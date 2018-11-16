#include "engine.h"
#include <algorithm>

Engine::Engine(const int width, const int height, const std::string title)
{
	//this is called when the object is created
	m_IsRunning = true;
	m_Window = std::make_unique<Window>(width, height, title);
	m_Time = std::make_unique<Time>();
}

Engine::~Engine()
{
	//this is called when the object is destroyed
	m_IsRunning = false;
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
	for (std::shared_ptr<Sprite>& sprite : m_Sprites)
	{
		//render the sprite for the window
		m_Window->Draw(sprite);
	}
	//go through each text and render it
	for (std::shared_ptr<Text>& text : m_Texts)
	{
		//render the text for the window
		m_Window->Draw(text);
	}
	//display everything
	m_Window->EndDraw();
}

std::shared_ptr<Sprite> Engine::CreateSprite(std::string filePath)
{
	std::shared_ptr<Sprite> sprite = std::make_shared<Sprite>(filePath);
	m_Sprites.push_back(sprite);
	return sprite;
}

void Engine::DestroySprite(std::shared_ptr<Sprite> sprite)
{
	//remove the sprite from the vector
	m_Sprites.erase(std::remove(m_Sprites.begin(), m_Sprites.end(), sprite), m_Sprites.end());
}

std::shared_ptr<Text> Engine::CreateText(std::string filePath)
{
	std::shared_ptr<Text> text = std::make_shared<Text>(filePath);
	m_Texts.push_back(text);
	return text;
}

void Engine::DestroyText(std::shared_ptr<Text> text)
{
	//remove the text from the vector
	m_Texts.erase(std::remove(m_Texts.begin(), m_Texts.end(), text), m_Texts.end());
}

const bool Engine::IsKeyPressed(Key key) const
{
	//ask input if the key has been pressed
	return Input::IsKeyPressed(key);
}

const float Engine::GetElapsedTimeAsSeconds()
{
	return m_Time->GetElapsedTimeAsSeconds();
}