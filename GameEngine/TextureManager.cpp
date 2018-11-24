#include "TextureManager.h"
#include <SFML/Graphics.hpp>

TextureManager::TextureManager()
{

}

TextureManager::~TextureManager()
{
	m_Textures.clear();
}

std::shared_ptr<sf::Texture>& TextureManager::GetTexture(std::string filePath)
{
	//try to find the texture
	if (m_Textures.find(filePath) == m_Textures.end())
	{
		//create a new texture
		std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();
		texture->loadFromFile(filePath);
		//add the texture associated by the filePath to the map
		m_Textures[filePath] = texture;
		return m_Textures[filePath];
	}

	//return the texture now that it can be found
	return m_Textures.find(filePath)->second;

}


