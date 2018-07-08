#ifndef __ENEMY__
#define __ENEMY__
#include <SDL2/SDL.h>
#include <iostream>
#include "LoaderParams.h"
#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
public:
	Enemy (const LoaderParams* pParams);
	//void load(int x, int y, int width, int height, std::string textureID);
	virtual void draw();
	virtual void update();
	virtual void clean();
};

#endif