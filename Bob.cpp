#include "stdafx.h"
#include "Bob.h"
#include "TextureHolder.h"

Bob::Bob()
{

	//associate a texture with the sprite
	m_Sprite = Sprite(TextureHolder::GetTexture("graphics/bob.png"));

	m_JumpDuration = 0.25f;

}	// end Bob function

	//========================================================================

bool Bob::handleInput()
{
	//always start assuming not jumoing
	m_JustJumped = false;

	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		//start a jump if not already jumping, but only if standing not falling
		if (!M_IsJumping && !M_IsFalling)
		{
			//perform jump
			M_IsJumping = true;
			m_TimeThisJump = 0;
			m_JustJumped = true;
		}	//end if not jumping or falling
	}
	else
	{
		//stop jump early if "w" is not held down
		M_IsJumping = false;
		M_IsFalling = true;
	}	//end "w" not pressed

		//check left
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		m_LeftPressed = true;
	}
	else
	{
		m_LeftPressed = false;
	}

	//check right
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		m_RightPressed = true;
	}
	else
	{
		m_RightPressed = false;
	}


	//return whether we jumped or not
	return m_JustJumped;

}	//end of handleInput()