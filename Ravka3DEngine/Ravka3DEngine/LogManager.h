#pragma once
#include <fstream>
#include <string>

namespace Ravka3DEngine
{
	class LogManager
	{
	public:

		std::string logFileName = "ErrorLog.txt";

		/*

		Enum of Severity levels of the log messages

		*/
		enum SeverityLevel
		{
			SL_NONE,
			SL_ERROR,
			SL_WARNING,
			SL_TRACE,
			SL_INFO
		};

		~LogManager();

		/*
		getInstance()
		Returns the instance of the LogManager
		There is only one instance since
		this is a singleton

		*/
		static LogManager * getInstance()
		{
			if (instance == nullptr)
			{
				instance = new LogManager;
			}
			return instance;
		}
		void close();
		void log(SeverityLevel severity, std::string message, std::string time);
		void setLogFile(std::string & fileName);

		/*
		**setSeverity(SeverityLevel severity)
		Sets the severity setting of the LogManager, only
		those messages whose severity is greater than
		or equal to this severity will be added to the log
		@param severity - The minimum severity of messages to print

		*/
		void setSeverity(SeverityLevel severity) { m_currentSeverity = severity; }

		/*
		**getSeverity()
		Returns the current severity of the LogManager

		*/
		SeverityLevel getSeverity() { return m_currentSeverity; }
		void error(std::string message, std::string time);
		void warning(std::string message, std::string time);
		void trace(std::string message, std::string time);
		void info(std::string message, std::string time);
		void setUpLog(std::string fileName);

	private:

		static LogManager * instance;
		std::ofstream * m_outputStream = nullptr;
		bool logWasSetup = false;
		SeverityLevel m_currentSeverity = SL_ERROR;

		int Num_Errors = 0;

		LogManager() {}
	};
}



