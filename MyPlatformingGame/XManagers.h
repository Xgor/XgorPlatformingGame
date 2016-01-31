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