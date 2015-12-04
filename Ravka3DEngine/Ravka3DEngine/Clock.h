#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include <chrono>
#include <ctime>
#include <iostream>

namespace Ravka3DEngine
{
	typedef std::chrono::system_clock SysTime;
	typedef SysTime::time_point TimePoint;

	class Clock
	{
	public:

		void init();
		std::string retrieveSystemTime();
		TimePoint getTimeNow();
		float getElapsedTime(TimePoint timeNow);
		float toMilliseconds(float time);
		float toMinutes(float time);
		TimePoint getStartTime();

		/*
		Returns an instance of the Clock class
		There can be only one clock

		*/
		static Clock * getInstance()
		{
			if (!instance)
			{
				instance = new Clock;
			}
			return instance;
		}


	private:


		static Clock * instance;

		/*

		There can be only one clock, if the value
		of the clock is needed anywhere else
		it should be passed as a pointer.

		*/
		Clock() {}

		/*
		** getSystemTime()
		Returns the current system time in time_t format

		*/
		time_t getSystemTime()
		{
			return SysTime::to_time_t(SysTime::now());
		}

		TimePoint m_startingPoint;
		float m_currentTime;

	};

}