#include "stdafx.h"
#include "Engine.h"

void Engine::draw()
{
	//erase last frame
	m_Window.clear(Color::White);

	//single screen
	if (!m_SplitScreen)
	{
		//switch to background view
		m_Window.setView(m_BGmainview);
		//draw the background
		m_Window.draw(m_BackgroundSprite);
		//set main view
		m_Window.setView(m_mainview);
		//TODO: draw all the stuff

		//draw the level
		m_Window.draw(m_VALevel, &m_TextureTiles);

		//draw thomas and bob
		m_Window.draw(m_Thomas.getSprite());
		m_Window.draw(m_Bob.getSprite());

	}//end single screen
	//split screen
	else
	{
		//draw thomas' side of screen
		//switch to background view
		m_Window.setView(m_BGleftview);
		//draw background
		m_Window.draw(m_BackgroundSprite);
		//switch to main view for left
		m_Window.setView(m_leftview);
		//TODO: draw all the stuff

		//draw the level
		m_Window.draw(m_VALevel, &m_TextureTiles);

		//draw thomas and bob
		m_Window.draw(m_Thomas.getSprite());
		m_Window.draw(m_Bob.getSprite());
		//draw bob's side of screen
		//switch to background view
		m_Window.setView(m_BGrightview);
		//draw background
		m_Window.draw(m_BackgroundSprite);
		//switch to main view for right
		m_Window.setView(m_rightview);
		//TODO: draw all the stuff

		//draw the level
		m_Window.draw(m_VALevel, &m_TextureTiles);

		//draw thomas and bob
		m_Window.draw(m_Thomas.getSprite());
		m_Window.draw(m_Bob.getSprite());


	}//end split screen

	//draw HUD
	//switch to HUD
	m_Window.setView(m_HUDview);
	//TODO: draw hud

	//show everthing we have just drawn
	m_Window.display();
}//end of draw function