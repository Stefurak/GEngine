#pragma once

#include "OGlRenderer.h"
#include "Clock.h"
#include "LogManager.h"
#include "PrimitiveType.h"
#include "SceneNode.h"
#include "InputManager.h"
#include "SceneGraph.h"
#include "Frustum.h"
#include "Image.h"

namespace Ravka3DEngine
{

	class GameEngine
	{

	public:
		GameEngine();
		~GameEngine();

		virtual void onStart();
		virtual void onEnd();
		virtual void preRender();
		virtual void render(PrimitiveTypeDef primitive);
		virtual void render(SHAPEGL * shape, Camera3D * camera, ShaderNova * program);
		virtual void postRender();
		virtual void logMessage(LogManager::SeverityLevel severity, std::string message, std::string time);

		void clearScreen()
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		LogManager * m_logManager = LogManager::getInstance();
		Clock * m_clock = Clock::getInstance();
		OGLRenderer * renderer;
	};
}
