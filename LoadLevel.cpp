#include "stdafx.h"
#include "Engine.h"

void Engine::loadLevel()
{

	m_Playing = false;

	//delete the previously allocated memory
	for (int i = 0; i < m_LM.getLevelSize().y; ++i)
	{
		delete[] m_Arraylevel[i];
	}
	delete[] m_Arraylevel;

	//load th next 2d array with the map for the level
	// and repopulate the vertex array as well
	m_Arraylevel = m_LM.nextlevel(m_VALevel);

	//how long is the new time limit
	m_TimeRemaining = m_LM.getTimeLimit();

	//spawn thomas and bob
	m_Thomas.spawn(m_LM.getStartPosition(),GRAVITY);
	m_Bob.spawn(m_LM.getStartPosition(), GRAVITY);

	//MAKE SURE THIS DOESN'T RUN TWICE
	m_NewLevelRequired = false;

}//end of loadlevel()