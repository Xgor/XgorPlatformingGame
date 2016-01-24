#include "InputManager.h"

InputManager* gInputManager = NULL;

InputManager::InputManager()
{

	gInputManager = this;
}


InputManager::~InputManager()
{
}

void InputManager::UpdateInput(SDL_Event *e)
{

}