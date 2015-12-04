#pragma once
#include "GLM\glm.hpp"

namespace Ravka3DEngine
{

	enum KeyEvent
	{
		LEFT_KEYDOWN = 1,
		LEFT_KEYUP,
		RIGHT_KEYDOWN,
		RIGHT_KEYUP,
		UP_KEYDOWN,
		UP_KEYUP,
		DOWN_KEYDOWN,
		DOWN_KEYUP,
		P_KEYDOWN,
		P_KEYUP
	};
	class InputManager
	{
	public:
		InputManager();
		~InputManager();

		bool moving = false;

		void processInput();

		glm::vec2 getMousePosition()
		{
			return _mousePosition;
		}

		glm::vec2 getMouseVelocity()
		{
			return _mouseVelocity;
		}

		KeyEvent getKeyEvent()
		{
			return _keyEvent;
		}

	private:
		glm::vec2 _mousePosition;
		glm::vec2 _mouseVelocity;
		KeyEvent _keyEvent;


	};


}
