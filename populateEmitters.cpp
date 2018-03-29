#include "stdafx.h"
#include "Engine.h"

using namespace sf;
using namespace std;

void Engine::populateEmitters(vector <Vector2f> & vSoundEmitters, int ** arrayLevel)
{
	//make sure the vector is empty
	vSoundEmitters.clear();

	//keep track of the previous emitter
	//so we dont make too many
	FloatRect previousEmitter;

	//search through the level arrayfor fire
	for (int x = 0; x < m_LM.getLevelSize().x; x++)
	{
		for (int y = 0; y < m_LM.getLevelSize().y; y++)
		{
			if (arrayLevel[y][x] == 2) //2 = fire
			{
				//skip over any fire tiles to near to the previous emitter
				FloatRect currentTile = FloatRect(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE);
				if (!currentTile.intersects(previousEmitter))
				{
					//add the coords of this block
					vSoundEmitters.push_back(Vector2f(x*TILE_SIZE, y*TILE_SIZE));

					//make a rectangle 6 x 6 blocks so we dont make anymore emittiers too close
					previousEmitter.left = x*TILE_SIZE;
					previousEmitter.top = y*TILE_SIZE;
					previousEmitter.width = TILE_SIZE * 6;
					previousEmitter.height = TILE_SIZE * 6;
					
				} // end if not too close to other emitter

			}//end if fire

		}//end y loop

	}	//end x loop



} // end populateEmitters()