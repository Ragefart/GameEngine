#pragma once

namespace sf
{
	class Clock;
}


class Time
{
public:
	Time();
	virtual ~Time();

	void Restart();
	const float GetElapsedTimeAsSeconds();

private:
	sf::Clock* m_Clock = nullptr;
	float m_DeltaTime = 0.f;
};

