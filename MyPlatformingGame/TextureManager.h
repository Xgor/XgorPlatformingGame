#pragma once
#include <SDL.h>
#include <map>
#include <string>
#include <SDL_image.h>
#include <stdio.h>
class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	void AddTexture(std::string path, std::string key);
	void SetRenderer(SDL_Renderer * renderer) {m_renderer = renderer;};


private:
//	std::map<std::string, SDL_Texture> m_textureMap;
	SDL_Renderer * m_renderer;
};
