#ifndef __ENEMY__
#define __ENEMY__

#include "SDLGameObject.h"
#include "GameObjectFactory.h"

class Enemy : public SDLGameObject
{
public:
	Enemy () : SDLGameObject()
	{
		m_velocity.setY(2);
		m_velocity.setX(0.001);
	}
	virtual void load(const LoaderParams* pParams)
	{
		SDLGameObject::load(pParams);
		m_velocity.setY(2);
	}
	//void load(int x, int y, int width, int height, std::string textureID);

	virtual void draw()
	{
		SDLGameObject::draw();
	}


	virtual void update()=0;
	virtual void clean(){}
};

#endif