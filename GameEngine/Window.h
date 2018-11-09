#pragma once
//forward declaration
namespace sf  //sfml namespace
{
	class RenderWindow;
}


#include <string>
using namespace std;

class Window
{
public:
	Window(const int width, const int height, std::string title);
	virtual ~Window();
	bool Update();
private:
	sf::RenderWindow* m_Window = nullptr;
};

