#include "Text.h"
#include <SFML/Graphics.hpp>


Text::Text(const std::string fontFilePath)
{
	m_Font = new sf::Font();
	m_Font->loadFromFile(fontFilePath);
	m_Text = new sf::Text();

	const sf::Font& font = *m_Font;
	m_Text->setFont(font);
}


Text::~Text()
{
	delete m_Font;
	delete m_Text;
}

void Text::SetText(std::string text)
{
	m_Text->setString(text);
}

void Text::SetSize(const int size)
{
	m_Text->setCharacterSize(size);
}
void Text::SetColor(const unsigned char red, const unsigned char green, const unsigned char blue, const unsigned char alpha)
{
	sf::Color color(red, green, blue, alpha);
	m_Text->setFillColor(color);
}
void Text::SetPosition(const float x, const float y)
{
	m_Text->setPosition(x, y);
}

sf::Text* Text::GetText()
{
	return m_Text;
}