#pragma once

#include <GameEngine/ISystem.h>

class BulletSystem : public ISystem
{
public:
	BulletSystem();
	~BulletSystem();

public:
	//inherited from ISystem
	virtual bool DoesEntityMatch(std::shared_ptr<Entity>& entity) override;
	virtual void Update(Engine* engine, float dt) override;

private:
	//update one single entity, return true if entity still exists, false if not
	bool inline UpdateEntity(Engine* engine, std::shared_ptr<Entity> entity, float dt);

};