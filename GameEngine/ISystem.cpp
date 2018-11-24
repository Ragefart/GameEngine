#include "ISystem.h"
#include "engine.h"

ISystem::ISystem()
{

}

ISystem::~ISystem()
{

}

void ISystem::Update(Engine* engine, float dt)
{

}

void ISystem::AddEntity(std::shared_ptr<Entity>& entity)
{
	//if the entity can be found, return because it's already inside
	if (std::find(m_Entities.begin(), m_Entities.end(), entity) != m_Entities.end())
	{
		return;
	}
	m_Entities.push_back(entity);
}

void ISystem::RemoveEntity(std::shared_ptr<Entity>& entity)
{
	//we try to get the iterator of the entity
	std::vector<std::shared_ptr<Entity>>::iterator entityItr = std::find(m_Entities.begin(), m_Entities.end(), entity);
	//if the entity has not been found, return
	if (entityItr == m_Entities.end())
	{
		return;
	}
	//remove the entity from the vector
	m_Entities.erase(entityItr);
}