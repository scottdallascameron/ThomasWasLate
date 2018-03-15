#include "stdafx.h"
#include "Thomas.h"
#include "TextureHolder.h"

Thomas::Thomas()
{

	//associate a texture with the sprite
	m_Sprite = Sprite(TextureHolder::GetTexture("graphics/thomas.png"));

		m_JumpDuration = 0.45f;

}	// end thomas function

//========================================================================

bool Thomas::handleInput()
{
	//always start assuming not jumoing
	m_JustJumped = false;

	if (Keyboard::isKeyPressed(Keyboard::W))
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
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		m_LeftPressed = true;
	}
	else
	{
		m_LeftPressed = false;
	}

	//check right
	if (Keyboard::isKeyPressed(Keyboard::D))
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