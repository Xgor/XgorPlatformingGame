//Using SDL, SDL_image, standard IO, and, strings
#include "XManagers.h"
#include <SDL.h>
#include <string>
#include <SDL_image.h>
#include <stdio.h>
#include <SDL_ttf.h>


//Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

SDL_Window *gWindow;

SDL_Renderer *gRenderer;

SDL_Surface *textSurface;

SDL_Texture *textTexture;

SDL_Event *e;

TTF_Font *gFont = NULL;

XManagers gManagerWrapper;

bool Init()
{
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	gManagerWrapper.CreateManagers();
	e = new SDL_Event();
	
	gTextureManager->SetRenderer(gRenderer);

	gFont = TTF_OpenFont("arial.ttf", 22);
	if (gFont == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		return false;
	}

	gWindow = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);

	gRenderer = SDL_CreateRenderer(gWindow,
		-1,
		SDL_RENDERER_ACCELERATED);
	return true;
}

bool Update()
{

	while (SDL_PollEvent(e)) {
//		gInputManager->UpdateInput(e);
		
		if (e->type == SDL_QUIT)
		{
			return false;
		}
	}

	return true;
}

void Draw()
{
	SDL_Color textColor = { 255, 255,255, 255 };
	textSurface = TTF_RenderText_Solid(gFont,"What does this mean", textColor);

	textTexture = SDL_CreateTextureFromSurface(gRenderer,textSurface);

	
	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(gRenderer);

	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	

	int w, h;
	SDL_QueryTexture(textTexture, NULL, NULL, &w, &h);
	SDL_Rect rect = { 400, 400, w, h };

	SDL_RenderCopyEx(gRenderer, textTexture, NULL,&rect,(double)(SDL_GetTicks()/10),NULL, SDL_FLIP_NONE);

//	SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
//	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
//	SDL_RenderFillRect(gRenderer, &fillRect);

	SDL_RenderPresent(gRenderer);

	
}

void Free()
{
	delete e;

	SDL_DestroyWindow(gWindow);

	SDL_DestroyRenderer(gRenderer);
	TTF_CloseFont(gFont);
	gManagerWrapper.FreeManagers();
	TTF_Quit();
	SDL_Quit();
}

int main(int argc, char* args[])
{

	if (!Init())
	{
		return 1;
	}

	while (Update())
	{
		Draw();
	}

	Free();

	return 0;
}