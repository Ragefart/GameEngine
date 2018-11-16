#pragma once
#include <string>
#include "Sprite.h"
#include "Text.h"

//forward declaration
namespace sf //sfml namespace
{
	class RenderWindow;
}

class Window
{
public:
	Window(const int width, const int height, const std::string title); //Constructor
	~Window(); //Destructor
public:
	bool Update();
	//Clear the window and prepare it to draw
	void BeginDraw();
	//display everything drawn
	void EndDraw();
	//draw a specific sprite
	void Draw(std::shared_ptr<Sprite>& sprite);
	//draw a specific text
	void Draw(std::shared_ptr<Text>& text);

private:
	std::unique_ptr<sf::RenderWindow> m_Window;
};