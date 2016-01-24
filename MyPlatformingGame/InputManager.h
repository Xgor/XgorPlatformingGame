#pragma once
#include <SDL.h>

class InputManager
{
public:
	InputManager();
	~InputManager();
	void UpdateInput(SDL_Event* e);


};
extern class InputManager* gInputManager;