#pragma once

#include <map>
#include <string>

namespace sf
{
	class Texture;
}

class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	//GetInstance will return the same object everytime we call it
	static TextureManager& GetInstance()
	{
		static TextureManager _instance; //this object will life until the end of the program
		return _instance;
	}

	TextureManager(const TextureManager&) = delete; //delete copy constructor
	TextureManager& operator=(const TextureManager&) = delete; //delete copy operator

public:
	//return the texture which can be associated with the filePath
	std::shared_ptr<sf::Texture>& GetTexture(std::string filePath);

private:
	//in a map we can search for a string and get the texture that is associated with this string
	std::map<std::string, std::shared_ptr<sf::Texture>> m_Textures;
};