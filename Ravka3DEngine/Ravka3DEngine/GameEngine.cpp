#include "GameEngine.h"

namespace Ravka3DEngine
{
	GameEngine::GameEngine()
	{

	}

	GameEngine::~GameEngine()
	{

	}

	void GameEngine::onStart()
	{
		m_clock->init();
		m_logManager->setLogFile(std::string("GameEngine.txt"));
		renderer = new OGLRenderer;
	}

	void GameEngine::onEnd()
	{
		m_logManager->close();
		delete m_logManager;
		delete m_clock;
	}

	void GameEngine::preRender()
	{
	}

	void GameEngine::render(PrimitiveTypeDef primitive)
	{
		//renderer->renderPrimitive(primitive);
		//logMessage(LogManager::SeverityLevel::SL_ERROR, "OH, ok then!", m_clock->retrieveSystemTime());
	}

	void GameEngine::render(SHAPEGL * shape, Camera3D * camera, ShaderNova * program)
	{
		renderer->renderPrimitive(shape, camera, program);
		//logMessage(LogManager::SeverityLevel::SL_ERROR, "OH, ok then!", m_clock->retrieveSystemTime());
	}

	void GameEngine::postRender()
	{
	}

	void GameEngine::logMessage(LogManager::SeverityLevel severity, std::string message, std::string time)
	{
		m_logManager->log(severity, message, time);
	}
}

