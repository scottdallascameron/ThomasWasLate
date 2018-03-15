#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Thomas.h"
#include "Bob.h"

using namespace sf;
//	SARAH NOTE: Don't use 'using' int h. files! bad.

class Engine
{
private:
	//the texture holder
	TextureHolder th;
	//SARAH NOTE: don't name things "th"

	//OUr playable cha;racter thoms and bob
	Thomas m_Thomas;
	Bob m_Bob;

	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;
	const int GRAVITY = 300;

	// A regular renderwindow
	RenderWindow m_Window;

	//the main views
	View m_mainview;
	View m_leftview;
	View m_rightview;

	//three views for background
	View m_BGmainview;
	View m_BGleftview;
	View m_BGrightview;
	
	View m_HUDview;

	//Sprite and texture for background
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;

	//Is the game currently playing
	bool m_Playing = false;

	//is character 1 or 2 the current focus
	bool m_Character1 = true;
	//SARAH NOTE: use enum instead, name better

	//Full or split screen?
	bool m_SplitScreen = false;

	//time left in current level
	float m_TimeRemaining = 10;
	Time m_GameTimeTotal;

	//is it time for a new/first level
	bool m_NewLevelRequired = true;

	//private functions for internal use
private:
	void input();
	void update(float dtAsSeconds);
	void draw();

public:
	//constructor
	Engine();

	//run will call all the private functions
	void run();
};