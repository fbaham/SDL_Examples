#include "GameOverState.h"
#include "MainMenuState.h"
#include "PlayState.h"
#include "TextureManager.h"
#include "AnimatedGraphic.h"
#include "Game.h"
#include "MenuButton.h"
#include "InputHandler.h"
#include "StateParser.h"

const std::string GameOverState::s_gameOverID = "GAMEOVER";
void GameOverState::s_gameOverToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(new MainMenuState());
}

void GameOverState::s_restartPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}

void GameOverState::update()
{
    for (int x = 0; x < m_gameObjects.size(); x++) {
        m_gameObjects[x]->update();
    }
}

void GameOverState::render()
{
    for (int x = 0; x < m_gameObjects.size(); x++) {
        m_gameObjects[x]->draw();
    }
}

bool GameOverState::onEnter()
{
	// parse the state
	StateParser stateParser;
	stateParser.parseState("assets/test.xml", s_gameOverID, &m_gameObjects, &m_textureIDList);
	m_callbacks.push_back(0);
	m_callbacks.push_back(s_gameOverToMain);
	m_callbacks.push_back(s_restartPlay);
	// set the callbacks for menu items
	setCallbacks(m_callbacks);
	std::cout << "entering GameOverState\n";
	return true;
}

bool GameOverState::onExit()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	// clear the texture manager
	for(int i = 0; i < m_textureIDList.size(); i++)
	{
		TheTextureManager::Instance()->clearFromTextureMap(m_textureIDList[i]);
	}

	// reset the mouse button states to false
	TheInputHandler::Instance()->reset();
	std::cout << "exiting GameOverState\n";
	return true;
}

void GameOverState::setCallbacks(const std::vector<Callback>& callbacks)
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