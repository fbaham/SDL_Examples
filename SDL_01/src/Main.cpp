#include<SDL.h>
#include<stdio.h>
#include"Game.h"

// our Game Object
Game* g_game = 0;

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;

int main(int argc, char* args[])
{
	g_game = new Game();
	g_game -> init("Chapter 1", 100, 100, 1280, 720, false);
	while(g_game -> running())
	{
		g_game -> handleEvents();
		g_game -> update();
		g_game -> render();
	}
	g_game -> clean();
	
	return 0;
}