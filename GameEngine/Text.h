#pragma once

#include <string>

//forward declare
namespace sf
{
	class Font;
	class Text;
}

class Text
{
public:
	//Constructor with the font file Path
	Text(const std::string fontFilePath);
	//destructor
	~Text();
public:
	//Changes the text
	void SetText(const std::string text);
	//Change the size of the text
	void SetSize(const int size);
	//Change the color, sfml is working with a color range from 0 to 255, just like the size of an unsigned char
	void SetColor(const unsigned char red, const unsigned char green, const unsigned char blue, const unsigned char alpha);
	//change the position of the text
	void SetPosition(const float X, const float Y);
	//Return the text so that SFML can draw it
	const std::shared_ptr<sf::Text>& GetText() { return m_Text; }
private:
	//SFML Font
	std::unique_ptr<sf::Font> m_Font;
	//SFML Text
	std::shared_ptr<sf::Text> m_Text;
};