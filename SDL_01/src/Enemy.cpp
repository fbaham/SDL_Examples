#include "Framework/LoaderParams.h"
#include "Enemy.h"
#include "SDLGameObject.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{

}

void Enemy::draw()
{
	SDLGameObject::draw();
}

void Enemy::update()
{
	m_x--;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Enemy::clean()
{
	
}