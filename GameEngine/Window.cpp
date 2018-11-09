#include "Window.h"
#include "SFML/Graphics.hpp"



Window::Window(const int width, const int height, std::string title)
{
	sf::VideoMode mode;
	mode.width = width;
	mode.height = height;
	int style = sf::Style::Default;
	m_Window = new sf::RenderWindow(mode, title, style);
}


Window::~Window()
{
	delete m_Window;
}

bool Window::Update()
{
	
	//create event object
	sf::Event event;
	//while we have events to poll, write something into "event" and handle it
	while (m_Window->pollEvent(event))
	{
		//handle events like closed
		if (event.type == sf::Event::Closed)
		{
			//return false because window is closed
			return false;
		}
	}
	//return true so that we say that the window is still open
	return true;
}

void Window::BeginDraw()
{
	//clear draws everything in a specific color
	m_Window->clear(sf::Color::Black);
}

void Window::EndDraw()
{	
	//displays everything again
	m_Window->display();
}

void Window::Draw(Sprite* sprite)
{
	const sf::Sprite& spriteREF = *sprite->Getsprite();

	m_Window->draw(spriteREF);
}