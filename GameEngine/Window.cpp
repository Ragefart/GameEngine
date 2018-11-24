#include "Window.h"
#include <SFML/Graphics.hpp>

//Constructor
Window::Window(const int width, const int height, const std::string title)
{
	sf::VideoMode mode;
	mode.width = width;
	mode.height = height;
	int style = sf::Style::Default;
	m_Window = std::make_unique<sf::RenderWindow>(mode, title, style);
}

//Destructor
Window::~Window()
{
}

bool Window::Update()
{
	//create event object
	sf::Event event;
	//while we have events to poll, write something into "event" and handle it
	while (m_Window->pollEvent(event))
	{
		//handle events, like closed, or resided
		if (event.type == sf::Event::Closed)
		{
			//return false because window is closed
			return false;
		}
	}
	//return true so that we say window is still open
	return true;
}

void Window::BeginDraw()
{
	//Clear draws everything in a specific color
	m_Window->clear(sf::Color::Black);
}

void Window::EndDraw()
{
	//display everything again
	m_Window->display();
}

void Window::Draw(const std::shared_ptr<sf::Sprite>& sprite)
{
	m_Window->draw(*sprite);
}

void Window::Draw(const std::shared_ptr<sf::Text>& text)
{
	m_Window->draw(*text);
}