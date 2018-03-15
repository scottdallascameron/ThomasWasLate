#include"stdafx.h"
#include "LevelManager.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "TextureHolder.h"
#include <sstream>
#include <fstream>

using namespace sf;
using namespace std;

int** LevelManager::nextlevel(VertexArray& rVaLevel)
{

	m_LevelSize.x = 0;
	m_LevelSize.y = 0;
	
	//get nex level
	m_CurrentLevel++;
	if (m_CurrentLevel > NUM_LVL)
	{
		m_CurrentLevel = 1;
		m_TimeModifier -= 0.1f;
	}

	//load the appropriate level from txt
	string levelToLoad;
	switch (m_CurrentLevel)
	{
	case 1:
		levelToLoad = "Levels/level1.txt";
		m_StartPosition.x = 100;
		m_StartPosition.y = 100;
		m_BaseTimeLimit = 30.0f;
		break;

	case 2:
		levelToLoad = "Levels/level2.txt";
		m_StartPosition.x = 100;
		m_StartPosition.y = 3600;
		m_BaseTimeLimit = 100.0f;
		break;

	case 3:
		levelToLoad = "Levels/level3.txt";
		m_StartPosition.x = 1250;
		m_StartPosition.y = 0;
		m_BaseTimeLimit = 30.0f;
		break;

	case 4:
		levelToLoad = "Levels/level4.txt";
		m_StartPosition.x = 50;
		m_StartPosition.y = 200;
		m_BaseTimeLimit = 50.0f;
		break;
	}//END SWITCH

	ifstream inputFile(levelToLoad);
	string s;

	//count the number of rows in the file
	while (getline(inputFile, s))
	{
		++m_LevelSize.y;
	}

	//store the length of the row (aka num of columns)
	m_LevelSize.x = s.length();

	//go back to start of file
	inputFile.clear();
	inputFile.seekg(0, ios::beg);

	//prepare the 2d array to hold the int values from the file
	int** arrayLevel = new int*[m_LevelSize.y];
	for (int i = 0; i < m_LevelSize.y; ++i)
	{
		arrayLevel[i] = new int[m_LevelSize.x];
	}

	//loop through file and store all the values
	string row;
	int y = 0;
	while (inputFile >> row)
	{
		for (int x = 0; x < row.length(); x++)
		{
			const char val = row[x];
			arrayLevel[y][x] = atoi(&val);
		}

		y++;
	}
	//close the file
	inputFile.close();

}//end of nextLevel()