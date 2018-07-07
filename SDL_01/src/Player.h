#ifndef __PLAYER__
#define __PLAYER__
#include <iostream>
#include "GameObject.h"
#include <SDL2/SDL.h>

class Player : public GameObject // inerit from GameObject
{
public:
	void load(int x, int y, int width, int height, std::string textureID);
	void draw(SDL_Renderer* pRenderer);
	void update();
	void clean();
};

#endif