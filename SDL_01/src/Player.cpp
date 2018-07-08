#include "LoaderParams.h"
#include "Player.h"
#include "SDLGameObject.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{

}

void Player::draw()
{
	SDLGameObject::draw();
}

void Player::update()
{
	m_x++;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Player::clean()
{
	
}