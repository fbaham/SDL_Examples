#ifndef __Game__
#define __Game__
#include<SDL.h>
#include"GameObject.h"
#include"Player.h"
#include <vector>

class Game
{
public:
	Game(){}
	~Game(){}
	// simply set the running variable to true
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void update();
	void render();
	void draw();
	void handleEvents();
	void clean();

	// a function to access the private running variable
	bool running() { return m_bRunning; }
private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	GameObject* m_go;
	GameObject* m_player;

	GameObject* m_enemy;

	std::vector<GameObject*> m_gameObjects;

	int m_currentFrame;

	bool m_bRunning;
};

#endif /* defined (__Game__) */