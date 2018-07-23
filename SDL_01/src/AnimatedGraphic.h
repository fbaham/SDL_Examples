#ifndef __ANIMATEDGRAPHIC__
#define __ANIMATEDGRAPHIC__

#include"SDLGameObject.h"
#include"LoaderParams.h"

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

#endif
