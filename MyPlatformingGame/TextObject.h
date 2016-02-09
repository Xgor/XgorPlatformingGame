#pragma once
#include <string>
#include <SDL_ttf.h>
#include "RendTarget.h"
#include "XManagers.h"
class TextObject :
	public RendTarget
{
public:
	TextObject();
	~TextObject();
	
	void SetText(std::string text);
	bool SetFont(std::string fontPath, int size);

	bool UpdateTextTexture(SDL_Renderer * renderer);
private:
	TTF_Font * m_font = NULL;
	std::string m_text;
};