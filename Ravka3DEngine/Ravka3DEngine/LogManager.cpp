#include "LogManager.h"

namespace Ravka3DEngine
{
	LogManager * LogManager::instance = nullptr;

	/*

	Destructor

	*/
	LogManager::~LogManager()
	{
		close();
	}

	/*
	**close()
	Closes the current log file

	*/
	void LogManager::close()
	{
		if (m_outputStream != nullptr)
		{
			m_outputStream->close();
			delete m_outputStream;
			m_outputStream = nullptr;
		}
	}

	/*
	**log(SeverityLevel severity, std::string message, std::string time)
	If a log message has a severity greater than the current severity
	this method will log that message and the time the message was sent
	to the current log file.
	@param severity - the severity of the message
	@param message - the message to be added to the log file
	@param time - the time the message was sent

	*/
	void LogManager::log(SeverityLevel severity, std::string message, std::string time)
	{
		if (severity >= m_currentSeverity && m_currentSeverity > SL_NONE)
		{
			if (m_outputStream == nullptr)
			{
				setLogFile(logFileName);
				setUpLog(logFileName);
			}
			Num_Errors++;
			(*m_outputStream) << "Error # : " << std::to_string(Num_Errors) << "\n"
				<< "Time Occured : " << time
				<< "Error Message : " << "\n"
				<< "---------------------------------------------" << "\n"
				<< message << "\n"
				<< "---------------------------------------------" << "\n";

			m_outputStream->flush();
		}
	}

	/*
	**setLogFile(std::string & fileName)
	This method closes the current log file and opens
	a new one using the past string as the filename.
	@param fileName - the name of the new log file

	*/
	void LogManager::setLogFile(std::string & fileName)
	{
		close();
		logWasSetup = false;
		std::string path = "./LogFiles/";
		//Getting an Error here, create a LogFiles directory.
		m_outputStream = new std::ofstream(path + fileName.c_str());
		setUpLog(fileName);
		m_currentSeverity = SL_ERROR;
	}

	/*
	**error(std::string message, std::string time)
	Add a message to the current log file with a severity of
	ERROR

	*/
	void LogManager::error(std::string message, std::string time)
	{
		log(SL_ERROR, message, time);
	}

	/*
	**warning(std::string message, std::string time)
	Add a message to the current log file with a severity of
	WARNING

	*/
	void LogManager::warning(std::string message, std::string time)
	{

		log(SL_WARNING, message, time);
	}

	/*
	**trace(std::string message, std::string time)
	Add a message to the current log file with a severity of
	TRACE

	*/
	void LogManager::trace(std::string message, std::string time)
	{
		log(SL_TRACE, message, time);
	}

	/*
	**info(std::string message, std::string time)
	Add a message to the current log file with a severity of
	INFO

	*/
	void LogManager::info(std::string message, std::string time)
	{
		log(SL_INFO, message, time);
	}

	/*
	**setUpLog(std::string fileName)
	Sets the header for the new log file, sets the number of
	errors back to zero, only does this if the log file was not already set up.

	*/
	void LogManager::setUpLog(std::string fileName)
	{
		if (!logWasSetup)
		{
			Num_Errors = 0;
			(*m_outputStream) << fileName << "\n" << "----------------- Error Log from JADE -----------------" << "\n";
			logWasSetup = true;
		}
	}
}