#pragma once
#include "InputManager.h"
#include "TextureManager.h"
class XManagers
{
public:
	XManagers();
	~XManagers();

	void CreateManagers();
	void FreeManagers();

};
extern class InputManager* gInputManager;
extern class TextureManager* gTextureManager;
extern class SDL_Window *gWindow;
extern class SDL_Renderer *gRenderer;	