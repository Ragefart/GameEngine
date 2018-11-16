#pragma once
#include <memory>

//forward declare clock
namespace sf
{
	class Clock;
}

class Time
{
public:
	Time(); //time constructor
	~Time(); //time destructor

public:
	void Restart(); //restart clock to zero
	const float GetElapsedTimeAsSeconds(); //return the time in seconds

private:
	//sfml clock to get the correct elapsed time
	std::unique_ptr<sf::Clock> m_Clock;
	//time passed since restart
	float m_DeltaTime = 0.f;
};