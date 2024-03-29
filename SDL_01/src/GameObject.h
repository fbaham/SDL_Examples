#ifndef __GAME_OBJECT__
#define __GAME_OBJECT__

#include <iostream>
#include "LoaderParams.h"

class GameObject
{
public:
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;
	virtual void load(const LoaderParams* pParams)=0;
protected:
	GameObject(){}
	virtual ~GameObject(){}
};

#endif