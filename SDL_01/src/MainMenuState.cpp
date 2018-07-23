#include <iostream>
#include "MainMenuState.h"
#include "MenuButton.h"
#include "TextureManager.h"
#include "PlayState.h"
#include "StateParser.h"
#include "InputHandler.h"
#include "Game.h"

const std::string MainMenuState::s_menuID = "MENU";

void MainMenuState::update()
{
	if(!m_gameObjects.empty())
    {
		for(int i = 0; i < m_gameObjects.size(); i++)
		{
			if(m_gameObjects[i] != 0)
			{
				m_gameObjects[i]->update();
			}
		}
    }
}

void MainMenuState::render()
{
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool MainMenuState::onEnter()
{
	// parse the state
	StateParser stateParser;
	stateParser.parseState("assets/test.xml", s_menuID, &m_gameObjects, &m_textureIDList);
	m_callbacks.push_back(0); //pushback 0 callbackID start from 1
	m_callbacks.push_back(s_menuToPlay);
	m_callbacks.push_back(s_exitFromMenu);
	// set the callbacks for menu items
	setCallbacks(m_callbacks);
	std::cout << "entering MenuState\n";
	return true;
}

bool MainMenuState::onExit()
{
	//m_exiting = true;	
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects.back()->clean();
		m_gameObjects.pop_back();
	}
	m_gameObjects.clear();

	//clear the texture manager
	for(int i = 0; i < m_textureIDList.size(); i++)
	{
		TheTextureManager::Instance()->clearFromTextureMap(m_textureIDList[i]);
	}
	TheInputHandler::Instance()->reset();

	std::cout << "exiting MainMenuState\n";
	return true;
}

void MainMenuState::s_menuToPlay()
{
	std::cout << "Play button clicked" << std::endl;
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}

void MainMenuState::s_exitFromMenu()
{
	TheGame::Instance()->quit();
}

void MainMenuState::setCallbacks(const std::vector<Callback>& callbacks)
{
	// go through the game objects
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		// if they are of type MenuButton then assign a callback based on the id passed in from the file
		if(dynamic_cast<MenuButton*>(m_gameObjects[i]))
		{
			MenuButton* pButton = dynamic_cast<MenuButton*>(m_gameObjects[i]);
			pButton->setCallback(callbacks[pButton->getCallbackID()]);
		}
	}
}