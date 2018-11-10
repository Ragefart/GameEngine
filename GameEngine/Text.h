#pragma once
#include <string>

namespace sf
{
	class Text;
	class Font;
}


class Text
{
public:
	Text(const std::string fontFilePath);
	virtual ~Text();

	void SetText(std::string text);
	void SetSize(const int size);
	void SetColor(const unsigned char red, const unsigned char green, const unsigned char blue, const unsigned char alpha);
	void SetPosition(const float x,const float y);
	sf::Text* GetText();
private:
	sf::Font* m_Font = nullptr;
	sf::Text* m_Text = nullptr;
};

