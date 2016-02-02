#pragma once
#include <SDL.h>
#include <math.h>
class Vector2
{
public:
	Vector2();
	Vector2(float xPos,float yPos);
	~Vector2();

	float Length() {  return sqrt(x*y); };
	float sqrLength() { return x*y; };
	SDL_Point ToSDLPoint();
//	float Length();

	float x ,y;
};

