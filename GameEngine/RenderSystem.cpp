#include "RenderSystem.h"
#include "SpriteComponent.h"

RenderSystem::RenderSystem()
{

}

RenderSystem::~RenderSystem()
{

}

bool RenderSystem::DoesEntityMatch(std::shared_ptr<Entity>& entity)
{
	//check if the entity has a spriteComponent
	if (entity->HasComponent<SpriteComponent>())
	{
		return true;
	}
	return false;
}

void RenderSystem::Draw(std::shared_ptr<Window>& window)
{
	//go through all entities where DoesEntityMatch returnes true
	for (std::shared_ptr<Entity>& entity : m_Entities)
	{
		//get their spriteComponent
		std::shared_ptr<SpriteComponent> spriteComp = entity->GetComponent<SpriteComponent>();
		//draw the entity
		window->Draw(spriteComp->GetSprite());
	}
}