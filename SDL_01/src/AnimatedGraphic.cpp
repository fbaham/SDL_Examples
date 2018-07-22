#include<SDL2/SDL.h>
#include"AnimatedGraphic.h"

AnimatedGraphic::AnimatedGraphic(const LoaderParams *pParams, int pAnimateSpeed):
    SDLGameObject(pParams), m_animateSpeed(pAnimateSpeed)
{
}

void AnimatedGraphic::draw()
{
    SDLGameObject::draw();
}

void AnimatedGraphic::update()
{
    m_currentFrame = int(SDL_GetTicks() / (1000 / m_animateSpeed) % 2);
}
