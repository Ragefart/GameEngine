#pragma once

#include <vector>
#include "Window.h"
#include "Input.h"
#include "Time.h"

class Engine
{
public:
	Engine(const int width, const int height, const std::string title); //Constructor
	~Engine(); //Destructor

public:
	//return whether the engine is still running
	const bool IsRunning() const { return m_IsRunning; }
	void Update();
	//draw every sprite text etc
	void Draw();
	//create a new sprite and save it to the vector
	Sprite* CreateSprite(std::string filePath);
	//destroy the sprite and remove it from the vector
	void DestroySprite(Sprite* sprite);
	//returns whether a key is pressed or not
	bool IsKeyPressed(Key key);
	//Return the deltaTime from Time
	const float GetElapsedTimeAsSeconds();
	Text* CreateText(std::string text);
	void DestroyText(Text* text);
private:
	//pointer to our time object
	Time* m_Time = nullptr;
	//pointer to our window object
	Window* m_Window = nullptr;
	//pointer to a input object
	Input* m_Input = nullptr;
	//variable whether engine is still running or not
	bool m_IsRunning = false;
	//all sprites that have been created by the engine
	std::vector<Sprite*> m_Sprites;
	std::vector<Text*> m_Texts;
};