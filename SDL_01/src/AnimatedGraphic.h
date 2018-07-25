#ifndef __ANIMATED_GRAPHIC__
#define __ANIMATED_GRAPHIC__

#include <iostream>
#include"SDLGameObject.h"
#include "GameObjectFactory.h"

class AnimatedGraphic : public SDLGameObject
{
    public:
        AnimatedGraphic();
        virtual void load(const LoaderParams* pParams);
        virtual void draw();
        virtual void update();
        virtual void clean() {};

    private:
        int m_animateSpeed;
};

class AnimatedGraphicCreator : public BaseCreator
{
public:
    
    virtual GameObject* createGameObject() const
    {
        return new AnimatedGraphic();
    }
};

#endif
