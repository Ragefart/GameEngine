#include "TextureManager.h"
#include <SFML/Graphics.hpp>



TextureManager::TextureManager()
{

}


TextureManager::~TextureManager()
{
	m_textures.clear();
}

std::shared_ptr<sf::Texture>&  TextureManager::GetTexture(std::string filepath)
{
	if (m_textures.find(filepath) == m_textures.end())
	{
		std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();
		texture->loadFromFile(filepath);

		m_textures[filepath] = texture;
		return m_textures[filepath];
	}

	return m_textures.find(filepath)->second;
}
