#ifndef __ENEMY__
#define __ENEMY__

#include "SDLGameObject.h"
#include "GameObjectFactory.h"

class Enemy : public SDLGameObject
{
public:
	Enemy ();
	virtual void load(const LoaderParams* pParams);
	//void load(int x, int y, int width, int height, std::string textureID);
	virtual void draw();
	virtual void update();
	virtual void clean();
};

class EnemyCreator : public BaseCreator
{
    GameObject* createGameObject() const
    {
        return new Enemy();
    }
};

#endif