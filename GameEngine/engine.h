#pragma once

#include <vector>
#include "Window.h"
#include "Input.h"
#include "Time.h"
#include "Entity.h"
#include "ISystem.h"
#include "RenderSystem.h"

class Engine
{
public:
	Engine(const int width, const int height, const std::string title); //Constructor
	~Engine(); //Destructor

public:
	//return whether the engine is still running
	const bool IsRunning() const { return m_IsRunning; }

	//Update the engine and the window
	void Update();

	//draw every sprite text etc
	void Draw();

	//returns whether a key is pressed or not
	const bool IsKeyPressed(Key key) const;

	//Return the deltaTime from Time
	const float GetElapsedTimeAsSeconds();

	//ECS-Functions
	void AddEntity(std::shared_ptr<Entity> entity);
	void RemoveEntity(std::shared_ptr<Entity> entity);
	void AddSystem(std::shared_ptr<ISystem> system);
	void RemoveSystem(std::shared_ptr<ISystem> system);
private:
	//pointer to our time object
	std::unique_ptr<Time> m_Time;
	//pointer to our window object
	std::shared_ptr<Window> m_Window;
	//pointer to our rendersystem
	std::shared_ptr<RenderSystem> m_RenderSystem;

	//variable whether engine is still running or not
	bool m_IsRunning = false;
	//accumulated time until we trigger a new update
	float m_AccumulatedTime = 0.f;

	//all entities that have been added to the engine
	std::vector<std::shared_ptr<Entity>> m_Entities;
	//all systems that have been added to the engine
	std::vector<std::shared_ptr<ISystem>> m_Systems;
};