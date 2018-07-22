#include <iostream>
#include "InputHandler.h"
#include "TextureManager.h"
#include "LoaderParams.h"
#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "GameStateMachine.h"
#include "PlayState.h"
#include "MenuState.h"

using namespace std;

Game* Game::s_pInstance = 0;

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

	TheInputHandler::Instance()->initialiseJoysticks();
	TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer);

	m_gameObjects.push_back(new Player(new LoaderParams(100,100,128,82,"animate")));
	m_gameObjects.push_back(new Enemy(new LoaderParams(300,300,128,82,"animate")));

	m_pGameStateMachine = new GameStateMachine();
	m_pGameStateMachine->changeState(new MenuState());

	m_bRunning = true; // everything inited successfully, start the main loop
	return true;
}

void Game::update()
{
	// for(std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	// {
	// 	m_gameObjects[i]->update();
	// }
	m_pGameStateMachine->update();
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer); // clear the renderer to the draw color
	
	m_pGameStateMachine->render();

	SDL_RenderPresent(m_pRenderer); // draw the screen
}

void Game::draw()
{
	for(std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

void Game::handleEvents()
{
	TheInputHandler::Instance()->update();

	if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pGameStateMachine->changeState(new PlayState());
	}
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	TheInputHandler::Instance()->clean();
	SDL_Quit();
}