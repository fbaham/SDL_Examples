#include "Game.h"
#include<stdio.h>

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
	// attemp to initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "SDL init succes\n";
		//init the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if(m_pWindow != 0) // window init success
		{
			std::cout << "window creation success\n";
		}
	}
}