#pragma once
#include <string>

//forward declaration
namespace sf //sfml namespace
{
	class RenderWindow;
	class Sprite;
	class Text;
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
	void Draw(const std::shared_ptr<sf::Sprite>& sprite);
	//draw a specific text
	void Draw(const std::shared_ptr<sf::Text>& text);

private:
	std::unique_ptr<sf::RenderWindow> m_Window;
};