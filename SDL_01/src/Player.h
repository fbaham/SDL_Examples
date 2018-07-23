#ifndef __PLAYER__
#define __PLAYER__

#include "LoaderParams.h"
#include "SDLGameObject.h"

class Player : public SDLGameObject // inerit from GameObject
{
public:
	Player ();
	virtual void load(const LoaderParams* pParams);
	//void load(int x, int y, int width, int height, std::string textureID);
	virtual void draw();
	virtual void update();
	virtual void clean();

private:
	void handleInput();
};

#endif