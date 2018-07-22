#ifndef __ANIMATEDGRAPHIC__
#define __ANIMATEDGRAPHIC__

#include"SDLGameObject.h"
#include"LoaderParams.h"

class AnimatedGraphic : public SDLGameObject
{
    public:
        AnimatedGraphic(const LoaderParams* pParams, int pAnimateSpeed);

        virtual void draw();
        virtual void update();
        virtual void clean() {};

    private:
        int m_animateSpeed;
};

#endif
