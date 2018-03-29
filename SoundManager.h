#pragma once
#include <SFML/Audio.hpp>

using namespace sf;

class SoundManager {

private:
		//the buffers
	SoundBuffer m_FireBuffer;
	SoundBuffer m_FallInFireBuffer;
	SoundBuffer m_FallInWaterBuffer;
	SoundBuffer m_JumpBuffer;
	SoundBuffer m_ReachGoalBuffer;

		//the sounds
	Sound m_Fire1Sound;
	Sound m_Fire2Sound;
	Sound m_Fire3Sound;
	Sound m_FallInFireSound;
	Sound m_FallInWaterSound;
	Sound m_JumpSound;
	Sound m_ReachGoalSound;

	//which fire sound to use
	int m_NextSound = 1;

public:

	SoundManager();

	void playFire(Vector2f emitterlocation, Vector2f listenerlocation);

	void playFallInFire();
	void playFallInWater();
	void playJump();
	void playReachGoal();

};	//end of soundmanager