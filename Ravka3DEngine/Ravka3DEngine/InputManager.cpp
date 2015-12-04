#include "InputManager.h"
#include "GameEngine.h"
#include <iostream>

namespace Ravka3DEngine
{

	KeyEvent keyEvent;


	InputManager::InputManager()
	{

	}

	InputManager::~InputManager()
	{
	}

	void InputManager::processInput()
	{
		SDL_Event evt;

		while (SDL_PollEvent(&evt))
		{
			switch (evt.type)
			{
				//Quit Button
			case SDL_QUIT:
				exit(0);
				SDL_Quit();
				break;
			case SDL_MOUSEMOTION:
				_mousePosition.x = evt.motion.x;
				_mousePosition.y = evt.motion.y;
				_mouseVelocity.x = evt.motion.xrel;
				_mouseVelocity.y = evt.motion.yrel;
				moving = true;
				break;
				
				//KEY DOWN

			case SDL_KEYDOWN:
				switch (evt.key.keysym.sym)
				{
				case SDLK_LEFT:
					//	std::cout << "YOU ARE MOVING LEFT" << std::endl;
					keyEvent = KeyEvent::LEFT_KEYDOWN;
					break;
				case SDLK_RIGHT:
					//std::cout << "YOU ARE MOVING RIGHT" << std::endl;
					keyEvent = KeyEvent::RIGHT_KEYDOWN;
					break;
				case SDLK_UP:
					//std::cout << "YOU ARE MOVING FORWARD" << std::endl;
					keyEvent = KeyEvent::UP_KEYDOWN;
					break;
				case SDLK_DOWN:
					//std::cout << "YOU ARE MOVING BACKWARD" << std::endl;
					keyEvent = KeyEvent::DOWN_KEYDOWN;
					break;
				case SDLK_p:
					keyEvent = KeyEvent::P_KEYDOWN;
					break;
				case SDLK_ESCAPE:
					exit(0);
					SDL_Quit();
					break;
				default:
					break;
				}
				break;

				//KEY UP

			case SDL_KEYUP:
				switch (evt.key.keysym.sym)
				{
				case SDLK_LEFT:
					keyEvent = KeyEvent::LEFT_KEYUP;
					break;
				case SDLK_RIGHT:
					keyEvent = KeyEvent::RIGHT_KEYUP;
					break;
				case SDLK_UP:
					keyEvent = KeyEvent::UP_KEYUP;
					break;
				case SDLK_DOWN:
					keyEvent = KeyEvent::DOWN_KEYUP;
					break;
				case SDLK_p:
					keyEvent = KeyEvent::P_KEYUP;
					break;
				default:
					break;
				}
				break;

			default:
				break;
			}
		}
		_keyEvent = keyEvent;
	}



}
