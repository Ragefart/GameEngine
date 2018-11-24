#pragma once

#include "Entity.h"

class Engine;

class ISystem
{
public:
	ISystem();
	virtual ~ISystem();
	virtual bool DoesEntityMatch(std::shared_ptr<Entity>& entity) = 0;

	void AddEntity(std::shared_ptr<Entity>& entity);
	void RemoveEntity(std::shared_ptr<Entity>& entity);
	virtual void Update(Engine* engine, float dt);


protected:
	std::vector<std::shared_ptr<Entity>> m_Entities;
};
