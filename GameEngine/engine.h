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
	//Update the engine and the window
	void Update();
	//draw every sprite text etc
	void Draw();
	//create a new sprite and save it to the vector
	std::shared_ptr<Sprite> CreateSprite(std::string filePath);
	//destroy the sprite and remove it from the vector
	void DestroySprite(std::shared_ptr<Sprite> sprite);

	//create a new text and save it to the vector
	std::shared_ptr<Text> CreateText(std::string filePath);
	//destroy the text and remove it from the vector
	void DestroyText(std::shared_ptr<Text> text);

	//returns whether a key is pressed or not
	const bool IsKeyPressed(Key key) const;

	//Return the deltaTime from Time
	const float GetElapsedTimeAsSeconds();
private:
	//pointer to our time object
	std::unique_ptr<Time> m_Time;
	//pointer to our window object
	std::unique_ptr<Window> m_Window;
	//variable whether engine is still running or not
	bool m_IsRunning = false;
	//all sprites that have been created by the engine
	std::vector<std::shared_ptr<Sprite>> m_Sprites;
	//all texts that have been created by the engine
	std::vector<std::shared_ptr<Text>> m_Texts;
};