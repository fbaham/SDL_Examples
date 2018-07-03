#include <iostream>
#include <stdio.h>
#include "Game.h"
#include <SDL_image.h>
#include "Framework/TextureManager.h"


using namespace std;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if(fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	// attemp to initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "SDL init succes\n";
		//init the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if(m_pWindow != 0) // window init success
		{
			std::cout << "window creation success\n";
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if(m_pRenderer != 0) // renderer init success
			{
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor (m_pRenderer, 100,149,237,255);
			}
			else
			{
				std::cout << "renderer init fail\n";
				return false; //rederer init fail
			}
		}
		else
		{
			std::cout << "window init fail\n";
			return false; // window init fail
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false; //SDL init fail
	}

	std::cout << "init success\n";

	TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer);

	m_bRunning = true; // everything inited successfully, start the main loop
	return true;
}

void Game::update()
{
	m_currentFrame = int (((SDL_GetTicks() / 100) % 6));
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer); // clear the renderer to the draw color
	
	TheTextureManager::Instance()->draw("animate", 0, 0, 128, 82, m_pRenderer);

	TheTextureManager::Instance()->drawFrame("animate", 100, 100, 128, 82, 1, m_currentFrame, m_pRenderer);

	SDL_RenderPresent(m_pRenderer); // draw the screen
}

void Game::handleEvents()
{
	SDL_Event event;
	if(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_QUIT:
				m_bRunning = false;
			break;

			default:
			break;
		}
	}
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}