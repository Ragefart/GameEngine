#include "engine.h"
#include <algorithm>

Engine::Engine(const int width, const int height, const std::string title)
{
	//this is called when the object is created
	m_IsRunning = true;
	m_Window = std::make_shared<Window>(width, height, title);
	m_Time = std::make_unique<Time>();

	m_RenderSystem = std::make_shared<RenderSystem>();
	AddSystem(m_RenderSystem);


}

Engine::~Engine()
{
	//this is called when the object is destroyed
	m_IsRunning = false;
}

void Engine::Update()
{
	if (!m_Window->Update())
	{
		m_IsRunning = false;
		return;
	}
	//restart the time to get the previous elapsed time in seconds
	m_Time->Restart();

	//we want to update the game 60 times a second
	const float dt = 1 / 60.0f;
	//get the elapsed time since last update
	const float deltaTime = GetElapsedTimeAsSeconds();
	//add the elapsed time to our accumulator
	m_AccumulatedTime += deltaTime;
	//check if we accumulated enough time to update once,
	//so that we always guarantee to update 60 times a second
	while (m_AccumulatedTime >= dt)
	{
		//update all systems that have Update implemented
		for (std::shared_ptr<ISystem>& system : m_Systems)
		{
			system->Update(this, dt);
		}
		//at the end, decrease the dt from the accumulator
		m_AccumulatedTime -= dt;
	}
}

void Engine::Draw()
{
	//clear and initialize rendering
	m_Window->BeginDraw();
	//render everything
	m_RenderSystem->Draw(m_Window);
	//display everything
	m_Window->EndDraw();
}

void Engine::AddEntity(std::shared_ptr<Entity> entity)
{
	//if the entity can be found, return because it's already inside
	if (std::find(m_Entities.begin(), m_Entities.end(), entity) != m_Entities.end())
	{
		return;
	}
	m_Entities.push_back(entity);

	//go through all systems and check if the entity matches the system
	for (std::shared_ptr<ISystem>& system : m_Systems)
	{
		//check if the entity matches the system
		if (system->DoesEntityMatch(entity))
		{
			//there is a match, now add it
			system->AddEntity(entity);
		}
	}
}

void Engine::RemoveEntity(std::shared_ptr<Entity> entity)
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

	//go through all systems and remove the entity if it's inside
	for (std::shared_ptr<ISystem>& system : m_Systems)
	{
		system->RemoveEntity(entity);
	}
}

void Engine::AddSystem(std::shared_ptr<ISystem> system)
{
	//if the system can be found, return because it's already inside
	if (std::find(m_Systems.begin(), m_Systems.end(), system) != m_Systems.end())
	{
		return;
	}
	m_Systems.push_back(system);
}

void Engine::RemoveSystem(std::shared_ptr<ISystem> system)
{
	//we try to get the iterator of the system
	std::vector<std::shared_ptr<ISystem>>::iterator systemItr = std::find(m_Systems.begin(), m_Systems.end(), system);
	//if the system has not been found, return
	if (systemItr == m_Systems.end())
	{
		return;
	}
	//remove the system from the vector
	m_Systems.erase(systemItr);
}

const bool Engine::IsKeyPressed(Key key) const
{
	//ask input if the key has been pressed
	return Input::IsKeyPressed(key);
}

const float Engine::GetElapsedTimeAsSeconds()
{
	return m_Time->GetElapsedTimeAsSeconds();
}