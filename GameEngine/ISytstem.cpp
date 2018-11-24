#include "ISytstem.h"
#include "engine.h"

ISystem::ISystem()
{
}

ISystem::~ISystem()
{
}

void ISystem::AddEntity(std::shared_ptr<Entity>& entity)
{
	if (std::find(m_Entities.begin(), m_Entities.end(), entity) != m_Entities.end())
	{
		return;
	}
	m_Entities.push_back(entity);
}

void ISystem::RemoveEntity(std::shared_ptr<Entity>& entity)
{
	std::vector<std::shared_ptr<Entity>>::iterator entityItr = std::find(m_Entities.begin(), m_Entities.end(), entity);

	if (entityItr == m_Entities.end())
	{
		return;
	}
	m_Entities.erase(entityItr);
}

void ISystem::Update(Engine * engine, float dt)
{

}


