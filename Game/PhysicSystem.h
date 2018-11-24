#pragma once

#include <GameEngine/ISystem.h>

class PhysicSystem : public ISystem
{
public:
	PhysicSystem();
	~PhysicSystem();
public:
	//inherited from ISystem
	virtual bool DoesEntityMatch(std::shared_ptr<Entity>& entity) override;
	virtual void Update(Engine* engine, float dt) override;
public:
	void SetBoundaries(const float max_X, const float max_Y);

private:
	//inline means the code of the function is copied wherever this function is used
	//We update the position of an entity here
	void inline UpdateSingleEntityPosition(std::shared_ptr<Entity>& entity, float dt);
	//we update the collisions of an entity here
	void inline UpdateSingleEntityCollision(std::shared_ptr<Entity>& entity, float dt);
private:
	float m_Max_X = 0.f;
	float m_Max_Y = 0.f;
};