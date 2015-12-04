#include "Timer.h"

namespace Ravka3DEngine
{
	/*
	** Timer takes a pointer to the clock
	this allows the timer to correct itself
	and access the methods inside of the clock.
	Because Timer depends on these methods,
	the Clock must always be initialized
	before the timer.

	*/
	Timer::Timer(Clock * clock) :
		m_timerState(TimerState::NONE),
		m_clock(clock),
		m_pausedTime(0.0f),
		m_currentTime(0.0f)
	{
		// Empty
	}

	Timer::~Timer() {}

	/*
	** initTimer()
	Simply sets the state of the timer to allow
	it to start counting, only when it is initialized.

	*/
	void Timer::initTimer()
	{
		m_timerState = TimerState::START;
	}

	/*
	** startTimer()
	This method resumes the timer after it has been paused.
	upon resuming, the timer will be corrected, for the whole
	amount of time the timer has been paused.

	*/
	void Timer::startTimer()
	{
		correctTimer();
		m_timerState = TimerState::START;
	}

	/*
	** pauseTimer()
	Self explanatory method
	Will simply pause the timer.

	*/
	void Timer::pauseTimer()
	{
		m_timerState = TimerState::PAUSE;
	}

	/*
	** dispose()
	This method resets the values of the timer
	that calls it. This frees the timer to be
	used again from scratch, by calling init()
	on that timer.

	*/
	void Timer::dispose()
	{
		m_currentTime = 0.0f;
		m_pausedTime = 0.0f;
		m_timerState = TimerState::NONE;
	}

	/*
	** updateMilliseconds()
	This method updates the timer using the
	number of lifetime milliseconds on the clock.

	*/
	void Timer::updateMilliseconds()
	{
		if (m_timerState != TimerState::PAUSE)
		{
			m_currentTime = m_clock->toMilliseconds(m_clock->getElapsedTime(m_clock->getTimeNow())) - (m_pausedTime * 1000.0f);
		}
	}

	/*
	** updateSeconds()
	This method updates the timer using the
	number of lifetime seconds on the clock.

	*/
	void Timer::updateSeconds()
	{
		if (m_timerState != TimerState::PAUSE)
		{
			m_currentTime = m_clock->getElapsedTime(m_clock->getTimeNow()) - m_pausedTime;
		}
	}

	/*
	** updateMinutes()
	This method updates the timer using the
	number of lifetime minutes on the clock.

	*/
	void Timer::updateMinutes()
	{
		if (m_timerState != TimerState::PAUSE)
		{
			m_currentTime = m_clock->toMinutes(m_clock->getElapsedTime(m_clock->getTimeNow())) - (m_pausedTime / 60.0f);
		}
	}

	/*
	** saveTime()
	This method stores the current time into an
	unordered map, using the string key that is
	passed as a parameter.

	*/
	void Timer::saveTime(std::string keyName)
	{
		m_saveTimes[keyName] = m_currentTime;
	}

	/*
	** retrieveTime()
	This method retrieves a saved time from an
	unordered map using the string key that is
	passed as a parameter.

	*/
	float Timer::retrieveTime(std::string keyName)
	{
		auto it = m_saveTimes.find(keyName);
		if (it != m_saveTimes.end())
		{
			return it->second;
		}
		else
		{
			return false;
		}
	}

	/*
	** correctTimer()
	Because the system clock is being used
	whenever the timer is paused the amount
	of time the timer has been paused must be
	accounted for when calculating the length
	of the timer.

	*/
	void Timer::correctTimer()
	{
		/*
		If the timer is paused, keep track of the
		amount of time it has been paused.
		Since the timer can be paused and restarted,
		this value must be stored so it can be used.

		This m_pausedTime value can now be used to
		correct the timer when the timer is restarted.
		*/
		m_globalTime = m_clock->getElapsedTime(m_clock->getTimeNow());
		m_pausedTime = m_globalTime - m_currentTime;
	}
}