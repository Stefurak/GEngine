#include "Clock.h"

namespace Ravka3DEngine
{
	Clock * Clock::instance = nullptr;

	void Clock::init()
	{
		m_startingPoint = getTimeNow();
	}

	/*
	** retrieveSystemTime()
	Returns the current real time
	from the system in the format
	day, month, day of the month, 24hr time, year
	as in
	Sun Sep 20 23:18:13 2015
	as a string so it can be used in logs.

	*/
	std::string Clock::retrieveSystemTime()
	{
		time_t temp = getSystemTime();
		return ctime(&temp);
	}

	/*
	** getTimeNow()
	Returns a TimePoint for the current system time

	*/
	TimePoint Clock::getTimeNow()
	{
		return SysTime::now();
	}

	/*
	** getElapsedTime
	Returns the elapsed time since the clock was initialized
	the value returned is accurate to 7 decimal places.
	This method returns by default the number of seconds the
	clock has been alive.

	*/
	float Clock::getElapsedTime(TimePoint timeNow)
	{
		std::chrono::duration<float> time_span = std::chrono::duration_cast<std::chrono::duration<float>>(timeNow - m_startingPoint);
		return time_span.count();
	}

	/*
	** toMilliseconds()
	Converts the current elapsed time
	to milliseconds

	*/
	float Clock::toMilliseconds(float time)
	{
		return time * 1000.0f;
	}

	/*
	** toMinutes()
	Converts the current elapsed time
	to minutes

	*/
	float Clock::toMinutes(float time)
	{
		return time / 60.0f;
	}

	/*
	** getStartTime()
	Returns the point at which the clock was created

	*/
	TimePoint Clock::getStartTime()
	{
		return m_startingPoint;
	}

}