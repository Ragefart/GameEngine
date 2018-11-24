#include "Text.h"
#include <SFML/Graphics.hpp>

Text::Text(const std::string fontFilePath)
{
	m_Font = std::make_unique<sf::Font>();
	m_Font->loadFromFile(fontFilePath);
	m_Text = std::make_shared<sf::Text>();

	const sf::Font& font = *m_Font;
	m_Text->setFont(font);
	//same as m_Text->setFont(*m_Font);
}

Text::~Text()
{
}

void Text::SetText(const std::string text)
{
	//set the sfml text which is drawn
	m_Text->setString(text);
}

void Text::SetPosition(const float X, const float Y)
{
	m_Text->setPosition(X, Y);
}

void Text::SetColor(const unsigned char red, const unsigned char green, const unsigned char blue, const unsigned char alpha)
{
	sf::Color color(red, green, blue, alpha);
	m_Text->setFillColor(color);
}

void Text::SetSize(const int size)
{
	m_Text->setCharacterSize(size);
}