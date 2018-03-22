#include "stdafx.h"
#include "Engine.h"

bool Engine::detectCollisions(PlayableCharacter& character)
{

	//initialised reachedGoal to false by default
	bool reachedGoal = false;

	//make a rectangle for the character's collision
	FloatRect detectionZone = character.getPosition();

	//make a floatrect to test each block
	FloatRect block;
	block.width = TILE_SIZE;
	block.height = TILE_SIZE;

	//Build a zone around the character to detect collisons
	int startX = (int)(detectionZone.left / TILE_SIZE) - 1;
	int startY = (int)(detectionZone.top / TILE_SIZE) - 1;
	int endX = (int)(detectionZone.left / TILE_SIZE) + 2;
	int endY = (int)(detectionZone.top / TILE_SIZE) + 3; //thomas is not manlet

	//make sure we dont test positions lower than zero
	if (startX < 0) startX = 0;
	if (startY < 0) startY = 0;

	//make sure we dont't test greater than our evel size
	if (endX > m_LM.getLevelSize().x)
		endX = m_LM.getLevelSize().x;
	if (endY > m_LM.getLevelSize().y)
		endY = m_LM.getLevelSize().y;

	//handle player falling out of level
	FloatRect level(0, 0, m_LM.getLevelSize().x * TILE_SIZE, m_LM.getLevelSize().y * TILE_SIZE);

		if (!detectionZone.intersects(level))
		{
			//respawn the character 
			character.spawn(m_LM.getStartPosition(), GRAVITY);
		}

		//Loop through all nearby blocks
		for (int x = startX; x < endX; ++x)
		{
			for (int y = startY; y < endY; ++y)
			{
				//set up your block
				block.left = x *TILE_SIZE;
				block.top = y * TILE_SIZE;

				//Have we hit water or lava
				if (m_Arraylevel[y][x] == 2 || m_Arraylevel[y][x] == 3)
				{
					if (character.getHead().intersects(block))
					{
						//they are in water/lava
						character.spawn(m_LM.getStartPosition(), GRAVITY);

						//PLAS SOUND OF DEATH
						if (m_Arraylevel[y][x] == 2) //fire
						{
							//TODO: Play sound
						}
						else //water
						{
							//TODO: Play sound
						}
					}//end block collisions
				}//end water/lava test

				//is character collidiing with a regualr block
				if (m_Arraylevel[y][x] == 1)
				{
					if (character.getRight().intersects(block))
					{
						character.stopRight(block.left);
					}
					else if (character.getLeft().intersects(block))
					{
						character.stopLeft(block.left);
					}

					if (character.getFeet().intersects(block))
					{
						character.stopFalling(block.top);
					}
					else if (character.getHead().intersects(block))
					{
						character.stopJump();
					}
				} // end normal block test

				  //more collisions here once we have learned about particle effects

				  //have we reached the goal?
				if (m_Arraylevel[y][x] == 4)
				{
					// Character has reached the goal
					reachedGoal = true;
				}
				
			}//end y loop
		}//end x loop


	//return whether or not our character have completed this level
	return reachedGoal;

}//end detectCollisions()