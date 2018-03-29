#include "stdafx.h"
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;

void Engine::update(float dtAsSeconds)
{
	if (m_NewLevelRequired)
	{
		loadLevel();
	}
	
	if (m_Playing)
	{
		//update thomas and bob
		m_Thomas.update(dtAsSeconds);
		m_Bob.update(dtAsSeconds);

		//detect collisons and see if the character have reached the goal
		if (detectCollisions(m_Thomas) && detectCollisions(m_Bob))
		{
			//new level required
			m_NewLevelRequired = true;

			//Play sound for reaching goal
			m_SM.playReachGoal();
		}
		else
		{
			//run bob collision detection
			detectCollisions(m_Bob);

			// let bob and thomas jump on each others heads
			if (m_Bob.getFeet().intersects(m_Thomas.getHead()))
			{
				m_Bob.stopFalling(m_Thomas.getHead().top);
			}

			if (m_Thomas.getFeet().intersects(m_Bob.getHead()))
			{
				m_Thomas.stopFalling(m_Bob.getHead().top);
			}

			//count down the time the player has left
			m_TimeRemaining -= dtAsSeconds;

			//have thomas and bob run out of time
			if (m_TimeRemaining <= 0)
			{
				m_NewLevelRequired = true;
			}


		}//end of if playing

		//check if fire sound needs to be played
		//iterate through the vector of vector2f objects
		for (auto it = m_FireEmitters.begin(); it != m_FireEmitters.end(); it++)
		{

			//where is this emitter
			//store the location in pos
			float posX = (*it).x;
			float posY = (*it).y;

			//is the emitter near the player
			//make a 500 pixel rectangle around the emitter
			FloatRect localRect(posX - 250, posY - 250, 500, 500);

			//is the playe rinside the local rect
			if (m_Thomas.getPosition().intersects(localRect))
			{
				//play the osund and pass in the locations
				m_SM.playFire(Vector2f(posX, posY), m_Thomas.getCentre());
			}

		}//end fire loop

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
	}

}//end of update function