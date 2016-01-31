#pragma once
#include <SDL.h>
#include "Vector2.h"
class RendTarget
{
public:
	RendTarget();
	virtual ~RendTarget();

	void Draw(SDL_Renderer *renderer);

protected:
	void SetTexture(SDL_Surface * surface);

private:
	SDL_Rect m_sourceRect;
	SDL_Rect m_destRect;
	SDL_Point m_origin;

	Vector2 m_position;
	Vector2 m_bounds;

	SDL_Texture * m_texture;
	double m_angle =0;
	SDL_RendererFlip m_flip = SDL_FLIP_NONE;
};

