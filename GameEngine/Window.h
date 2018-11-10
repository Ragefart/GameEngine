#pragma once
//forward declaration
namespace sf  //sfml namespace
{
	class RenderWindow;
}


#include <string>
#include "Sprite.h"
#include "Text.h"
using namespace std;

class Window
{
public:
	Window(const int width, const int height, std::string title);
	virtual ~Window();
	bool Update();
	//clear the window and prepare it to draw
	void BeginDraw();
	//display everything drawn
	void EndDraw();
	//draws a specific sprite
	void Draw(Sprite* sprite);
	void Draw(Text* text);
private:
	sf::RenderWindow* m_Window = nullptr;
};

