#ifndef __Game__
#define __Game__
#include <SDL2/SDL.h>
#include <vector>
#include "GameObject.h"
#include "InputHandler.h"
#include "GameStateMachine.h"

class Game
{
public:
	static Game* Instance ()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	SDL_Renderer* getRenderer() const { return m_pRenderer; }

	void update();
	void render();
	void draw();
	void handleEvents();
	void clean();
	void quit() { m_bRunning = false; }

	// a function to access the private running variable
	bool running() { return m_bRunning; }
	
	GameStateMachine* getStateMachine(){ return m_pGameStateMachine; }
private:
	Game(){}

	static Game* s_pInstance;

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	GameStateMachine* m_pGameStateMachine;
	
	int m_currentFrame;

	bool m_bRunning;
};

typedef Game TheGame;

#endif /* defined (__Game__) */