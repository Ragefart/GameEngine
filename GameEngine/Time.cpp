#include "Time.h"
#include <SFML/System.hpp>



Time::Time()
{
	m_Clock = new sf::Clock();

}


Time::~Time()
{
	delete m_Clock;
}


void Time::Restart()
{
	//restart the clock and write the time passed since last start into m_DeltaTime
	m_DeltaTime = m_Clock->restart().asSeconds();
}

const float Time::GetElapsedTimeAsSeconds()
{
	return m_DeltaTime;
}