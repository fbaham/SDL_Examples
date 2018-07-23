#include "TextureManager.h"
#include "LoaderParams.h"
#include "SDLGameObject.h"
#include "GameObject.h"
#include "Game.h"

SDLGameObject::SDLGameObject() :	GameObject(),
									m_position(0,0),
									m_velocity(0,0),
									m_acceleration(0,0),
									m_width(0),
									m_height(0),
									m_currentRow(0),
									m_currentFrame(0),
									m_numFrames(0)
{
}

void SDLGameObject::load(const LoaderParams *pParams)
{
	m_position = Vector2D(pParams->getX(),pParams->getY());
	m_velocity = Vector2D(0,0);
	m_acceleration = Vector2D(0,0);
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_textureID = pParams->getTextureID();
	m_currentRow = 1;
	m_currentFrame = 1;
	m_numFrames = pParams->getNumFrames();
}

void SDLGameObject::update()
{
	m_velocity += m_acceleration;
	m_position += m_velocity;
}

void SDLGameObject::draw()
{
	if(m_velocity.getX() > 0)
	{
		TextureManager::Instance()->drawFrame(m_textureID, (Uint32)m_position.getX(), (Uint32)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer(),SDL_FLIP_HORIZONTAL);
	}
	else
	{
		TextureManager::Instance()->drawFrame(m_textureID, (Uint32)m_position.getX(), (Uint32)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer());
	}
}