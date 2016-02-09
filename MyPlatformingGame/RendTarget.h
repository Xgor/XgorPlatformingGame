#pragma once
#include <SDL.h>
#include <math.h>
#include "Vector2.h"

#define _USE_MATH_DEFINES
class RendTarget
{
public:
	RendTarget();
	virtual ~RendTarget();

	void Draw(SDL_Renderer *renderer);

	Vector2 GetPosition() { return m_position; };
	Vector2 GetBounds() { return m_bounds; };
	SDL_Texture * GetTexture() { return m_texture; };



	void SetPosition(Vector2 position);
	void SetPosition(float x, float y);
//	void Set
//	void SetBounds(Vector2 position);
//	void SetBounds(float x, float y);
	void Move(Vector2 position);
	void Move(float x, float y);
	void MoveDirection(float speed, float angle);
	void Rotate(float rotation);
	void SetAngle(float angle) { m_angle = angle; };
	void SetFlipState(SDL_RendererFlip flip) { m_flip = flip; };
	void SetTexture(SDL_Texture * texture);


protected:

private:
	SDL_Rect m_sourceRect;
	SDL_Rect m_destRect; 
	SDL_Point m_origin;

	Vector2 m_position;
	Vector2 m_bounds;	
	Vector2 m_sourcePos;
	Vector2 m_sourceSize;

	SDL_Texture * m_texture;
	double m_angle =0;
	SDL_RendererFlip m_flip = SDL_FLIP_NONE;


	void UpdateRects();
};

