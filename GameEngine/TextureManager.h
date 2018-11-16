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
	virtual ~TextureManager();

	static TextureManager& GetInstance() {
		static TextureManager _Instance;
		return _Instance;
	}

	TextureManager(const TextureManager&) = delete; //delete copy constructor
	TextureManager& operator=(const TextureManager&) = delete; //delete copy constructor

public:
	std::shared_ptr<sf::Texture>& GetTexture(std::string filepath);

private:
	std::map<std::string, std::shared_ptr<sf::Texture>> m_textures;

};

