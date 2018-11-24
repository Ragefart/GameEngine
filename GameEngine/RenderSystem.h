#pragma once

#include "ISystem.h"
#include "Window.h"

class RenderSystem : public ISystem
{
public:
	RenderSystem();
	~RenderSystem();

public:
	//Inherited from ISystem
	virtual bool DoesEntityMatch(std::shared_ptr<Entity>& entity) override; //we need to override the pure virtual functions

public:
	void Draw(std::shared_ptr<Window>& window);


};