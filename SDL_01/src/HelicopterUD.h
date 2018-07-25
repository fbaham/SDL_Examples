#ifndef __HELICOPTER_UD__
#define __HELICOPTER_UD__

#include "Enemy.h"
#include "SDLGameObject.h"

class HelicopterUD : public Enemy
{
public:
	virtual void update()
	{
		m_currentFrame = int(((SDL_GetTicks() / 100) % 5));
		if(m_position.getY() < 0)
		{
			m_velocity.setY(2);
		}
		else if(m_position.getY() > 400)
		{
			m_velocity.setY(-2);
		}
		SDLGameObject::update();
	}
	
};

class HelicopterUDCreator : public BaseCreator
{
    GameObject* createGameObject() const
    {
        return new HelicopterUD();
    }
};

#endif