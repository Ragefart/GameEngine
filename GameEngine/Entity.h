#pragma once
#include "IComponent.h"
#include <vector>
#include <memory>

class Entity
{
public:
	Entity()
	{

	}

	~Entity()
	{

	}

public:
	template<typename T>
	std::shared_ptr<T> AddComponent()
	{
		//check during compile-time if the templateclass is valid
		static_assert(std::is_base_of<IComponent, T>::value, "T must be derived from IComponent");
		//if the component is already inside, return it directly
		std::shared_ptr<T> foundComponent = GetComponent<T>();
		if (foundComponent != nullptr)
		{
			return foundComponent;
		}
		//not inside already, so we create a new Component and add it
		std::shared_ptr<T> addedComponent = std::make_shared<T>();
		m_Components.push_back(addedComponent);
		return addedComponent;
	}

	template<typename T>
	std::shared_ptr<T> GetComponent()
	{
		//check during compile-time if the templateclass is valid
		static_assert(std::is_base_of<IComponent, T>::value, "T must be derived from IComponent");
		//go through each object
		for (std::shared_ptr<IComponent>& component : m_Components)
		{
			//try to cast the object to the specific type and if possible, return it
			if (std::shared_ptr<T> cast = std::dynamic_pointer_cast<T>(component))
			{
				return cast;
			}

		}
		//no component found
		return nullptr;
	}

	template<typename T>
	void RemoveComponent()
	{
		//check during compile-time if the templateclass is valid
		static_assert(std::is_base_of<IComponent, T>::value, "T must be derived from IComponent");
		//go through all components and see if you can find a component of type T and remove it
		for (std::vector<std::shared_ptr<IComponent>>::iterator componentItr = m_Components.begin(); componentItr != m_Components.end();)
		{
			//if we can cast the component to T, therefore the component exists within our vector
			if (std::dynamic_pointer_cast<T>(*componentItr) != nullptr)
			{
				//remove the component from the bector
				m_Components.erase(componentItr);
				break;
			}
			//if it's not found yet, increment again
			++componentItr;
		}
	}

	template<typename T>
	bool HasComponent()
	{
		return GetComponent<T>() != nullptr;
	}

private:
	std::vector<std::shared_ptr<IComponent>> m_Components;
};