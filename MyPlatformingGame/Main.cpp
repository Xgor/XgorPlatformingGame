//Using SDL, SDL_image, standard IO, and, strings

#include <SDL.h>
#include <string>
#include <SDL_image.h>
#include <stdio.h>
#include <SDL_ttf.h>
#include "XManagers.h"
#include "TextObject.h"

//Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

SDL_Window *m_window;
SDL_Renderer *m_renderer;

SDL_Event *e;



XManagers gManagerWrapper;

TextObject * text;


TTF_Font *gFont = NULL;
SDL_Surface* textSurface;
SDL_Texture * textTexture;

RendTarget * rendTarget;

bool Init()
{
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	gManagerWrapper.CreateManagers();
	e = new SDL_Event();
	
//	gTextureManager->SetRenderer(m_renderer);
	text = new TextObject();
	rendTarget = new RendTarget();

	gFont = TTF_OpenFont("arial.ttf", 22);
	if (!text->SetFont("arial.ttf", 22))
	{
		return false;
	}
	if (gFont == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		return false;
	}
	

	m_window = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);

	m_renderer = SDL_CreateRenderer(m_window,
		-1,
		SDL_RENDERER_ACCELERATED);





	text->SetText("What does this mean");
	text->UpdateTextTexture(m_renderer);



	gWindow = m_window;
	gRenderer = m_renderer;
	gTextureManager->SetRenderer(m_renderer);
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

	textTexture = SDL_CreateTextureFromSurface(m_renderer,textSurface);

	int w, h;
	SDL_QueryTexture(textTexture, NULL, NULL, &w, &h);
	SDL_Rect rect = { 400, 400, w, h };
	rendTarget->SetTexture(textTexture);
	
	SDL_SetRenderDrawColor(m_renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(m_renderer);
	
	rendTarget->SetPosition(200, 200);
//	rendTarget->SetBounds(w, h);

//	text->SetTexture(textTexture);
	text->SetPosition(100, 100);
//	text->SetBounds(w, h);

	SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
//	SDL_SetRenderDrawColor(m_renderer, 0x00, 0x00, 0x00, 0xFF);


//	SDL_RenderCopy(m_renderer, text->GetTexture(), NULL, NULL);
//	text->Draw(m_renderer);
	text->UpdateTextTexture(m_renderer);
	rendTarget->Draw(m_renderer);
	text->Draw(m_renderer);

//	SDL_RenderCopyEx(m_renderer, textTexture, NULL,&rect,(double)(SDL_GetTicks()/10),NULL, SDL_FLIP_NONE);

//	SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
//	SDL_SetRenderDrawColor(m_renderer, 0xFF, 0x00, 0x00, 0xFF);
//	SDL_RenderFillRect(m_renderer, &fillRect);

	SDL_RenderPresent(m_renderer);

	
}

void Free()
{
	delete e;

	SDL_DestroyWindow(m_window);

	SDL_DestroyRenderer(m_renderer);
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
//		SDL_RenderClear(m_renderer);

//		text->Draw(m_renderer);

///		SDL_RenderPresent(m_renderer);


	//	Draw();
	}

	Free();

	return 0;
}