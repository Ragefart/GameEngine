#pragma once

#include "Entity.h"

class Engine;

class ISystem
{
public:
	ISystem();
	virtual ~ISystem();

	//check if the entity matches the system
	virtual bool DoesEntityMatch(std::shared_ptr<Entity>& entity) = 0; //pure virtual because of = 0
	//update the ISystem
	virtual void Update(Engine* engine, float dt);
	//add and remove the entity from the system
	void AddEntity(std::shared_ptr<Entity>& entity);
	void RemoveEntity(std::shared_ptr<Entity>& entity);

protected:
	std::vector<std::shared_ptr<Entity>> m_Entities;
};