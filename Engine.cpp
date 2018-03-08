#include "stdafx.h"
#include "Engine.h"

Engine::Engine()
{
	//get the screen resolution
	//and create an SFML window and view
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	m_Window.create(VideoMode(resolution.x, resolution.y),
		"ThomasWasLate",
		Style::Fullscreen);

	//initialise fullscreen view
	m_mainview.setSize(resolution);
	m_HUDview.reset(FloatRect(0, 0, resolution.x, resolution.y));

	//initialise split screen
	m_leftview.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_rightview.setViewport(FloatRect(0.5f, 0.001f, 0.498f, 0.998f));

	//backgrounds
	m_BGleftview.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_BGrightview.setViewport(FloatRect(0.5f, 0.001f, 0.498f, 0.998f));

	//get background texture
	m_BackgroundTexture = TextureHolder::GetTexture("graphics/background.png");

	//associate the sprite with the textures
	m_BackgroundSprite.setTexture(m_BackgroundTexture);
}

void Engine::run()
{
	Clock clock;

	while (m_Window.isOpen())
	{
		Time dt = clock.restart();
		//update the total game time
		m_GameTimeTotal += dt;

		//make a decimal fraction from the dt

		float dtAsSeconds = dt.asSeconds();

		//call each part of the game loop in turn
		input();
		update(dtAsSeconds);
		draw();
	}
}