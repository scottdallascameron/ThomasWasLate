#include "stdafx.h"
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;

void Engine::update(float dtAsSeconds)
{
	if (m_NewLevelRequired)
	{
		//NOTE: This will be moved to loadLevel() later
		//spawn thommas and bob
		m_Thomas.spawn(Vector2f(0, 0), GRAVITY);
		m_Bob.spawn(Vector2f(100, 0), GRAVITY);

		//Initialise time and level boolean
		m_TimeRemaining = 10;
		m_NewLevelRequired = false;
	}
	
	
	
	if (m_Playing)
	{
		//update thomas and bob
		m_Thomas.update(dtAsSeconds);
		m_Bob.update(dtAsSeconds);

		//count down the time the player has left
		m_TimeRemaining -= dtAsSeconds;

		//have thomas and bob run out of time
		if (m_TimeRemaining <= 0)
		{
			m_NewLevelRequired = true;
		}


	}//end of if playing

	//set the view around the appropriate characters
	if (m_SplitScreen)
	{
		m_leftview.setCenter(m_Thomas.getCentre());
		m_rightview.setCenter(m_Bob.getCentre());
	}
	else
	{
		if (m_Character1)	// if we should focus on thomas
		{
			m_mainview.setCenter(m_Thomas.getCentre());;
		}
		
		if (m_Character1)	// if we should focus on Bob
		{
			m_mainview.setCenter(m_Bob.getCentre());;
		}
	}


}//end of update function