#pragma once
#include "Clock.h"
#include <unordered_map>
#include <string>

#include "LogManager.h"


namespace Ravka3DEngine
{
	class Timer
	{
	private:

		void correctTimer();


		enum class TimerState
		{
			NONE,
			START,
			PAUSE
		};

		TimerState m_timerState;
		Clock * m_clock;
		float m_currentTime;
		float m_globalTime;
		float m_pausedTime;

		std::unordered_map<std::string, float> m_saveTimes;

	public:

		Timer(Clock * clock);

		~Timer();

		void initTimer();
		void startTimer();
		void pauseTimer();
		void dispose();
		void updateMilliseconds();
		void updateSeconds();
		void updateMinutes();
		void saveTime(std::string keyName);
		float retrieveTime(std::string keyName);

		//Getters

		/*
		** getTimerState()
		Returns the current state of the timer.

		*/
		TimerState getTimerState() { return m_timerState; }

		/*
		** getMilliseconds()
		Returns the current Timer length measured
		in milliseconds.

		*/
		float getMilliseconds() { return m_currentTime * 1000.0f; }

		/*
		** getSeconds()
		Returns the current Timer length measured
		in seconds.

		*/
		float getSeconds() { return m_currentTime; }

		/*
		** getMinutes()
		Returns the current Timer length measured
		in minutes.

		*/
		float getMinutes() { return m_currentTime / 60.0f; }

	};
}