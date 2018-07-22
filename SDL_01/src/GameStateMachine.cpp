#include "GameStateMachine.h"
#include <iostream>

void GameStateMachine::update()
{
	if(m_gameStates.empty())
	{
		std::cout << "Nada cargado";
		return;
	}
	m_gameStates.back()->getStateID();
	m_gameStates.back()->update();
}

void GameStateMachine::render()
{
	if(m_gameStates.empty())
	{
		std::cout << "Nada cargado render";
		return;	
	}
	m_gameStates.back()->render();
}

void GameStateMachine::pushState(GameState *pState)
{
	m_gameStates.push_back(pState);
	m_gameStates.back()->onEnter();
}

void GameStateMachine::popState()
{
	if(!m_gameStates.empty())
	{
		if(m_gameStates.back()->onExit())
		{
			delete m_gameStates.back();
			m_gameStates.pop_back();
		}
	}
}

void GameStateMachine::changeState(GameState *pState)
{
	std::cout << "Change State\n";
	if(!m_gameStates.empty())
	{
		std::cout << "GameStates empty\n";
		if(m_gameStates.back()->getStateID() == pState->getStateID())
		{
			return; // do nothing
		}

		popState();
	}
	// push back our new state
	m_gameStates.push_back(pState);
	// initialise it
	m_gameStates.back()->onEnter();
}