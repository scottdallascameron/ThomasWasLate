#include "stdafx.h"
#include "Playable.h"

void PlayableCharacter::spawn(Vector2f startPosition, float gravity)
{
	//place the player at the starting point
	m_position.x = startPosition.x;
	m_position.y = startPosition.y;

	//initialise the gravity
	m_Gravity = gravity;

	//move the spirte to posiiton
	m_Sprite.setPosition(m_position);

}//end spawn

void PlayableCharacter::update(float elapsedtime)
{
	//check left or right
	if (m_RightPressed)
	{
		m_position.x += m_Speed * elapsedtime;
	}
	if (m_LeftPressed)
	{
		m_position.x -= m_Speed * elapsedtime;
	}

	//handle jumping
	if (M_IsJumping)
	{
		//update how lomng the jmp has been going
		m_TimeThisJump += elapsedtime;

		//if we are still moving upwards	
		if (m_TimeThisJump < m_JumpDuration)
			{
				//move at twice the speed of gravity
				m_position.y -= m_Gravity * 2 * elapsedtime;
			}
		//if jump duration has ended
		else
			{
				M_IsJumping = false;
				M_IsFalling = true;
			}
	}//end if (m_isjumping)

	//apply gravity
	if (M_IsFalling)
	{
		m_position.y += m_Gravity * elapsedtime;
	}

	FloatRect r = getPosition();

	//feet
	m_Feet.left = r.left + 3;
	m_Feet.top = r.top + r.height - 1;
	m_Feet.width = r.width - 6;
	m_Feet.height = 1;

	//head
	m_Head.left = r.left;
	m_Head.top = r.top + (r.height * 0.3);
	m_Head.width = r.width;
	m_Head.height = 1;

	//right
	m_Right.left = r.left + r.width - 2;
	m_Right.top = r.top + r.height * 0.35;
	m_Right.width = 1;
	m_Right.height = r.height * 0.3;

	//left
	m_Left.left = r.left;
	m_Left.top = r.top + r.height * 0.35;
	m_Left.width = 1;
	m_Left.height = r.height * 0.3;

	//move the sprite into position
	m_Sprite.setPosition(m_position);

}//end update

FloatRect PlayableCharacter::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

Vector2f PlayableCharacter::getCentre()
{
	return Vector2f(
		m_position.x + m_Sprite.getGlobalBounds().width / 2,
		m_position.y + m_Sprite.getGlobalBounds().height / 2,
		);
}

FloatRect PlayableCharacter::getFeet()
{
	return m_Feet;
}

FloatRect PlayableCharacter::getHead()
{
	return m_Head;
}

FloatRect PlayableCharacter::getRight()
{
	return m_Right;
}

FloatRect PlayableCharacter::getLeft()
{
	return m_Left;
}

Sprite PlayableCharacter::getSprite()
{
	return m_Sprite;
}

void PlayableCharacter::stopFalling(float position)
{
	m_position.y = position - getPosition().height;
	m_Sprite.setPosition(m_position);
	M_IsFalling = false;
}

void PlayableCharacter::stopRight(float position)
{
	m_position.y - getPosition().height;
	m_Sprite.setPosition(m_position);
}

void PlayableCharacter::stopLeft(float position)
{
	m_position.x + getPosition().width;
	m_Sprite.setPosition(m_position);
}

void PlayableCharacter::stopJump()
{
	M_IsJumping = false;
	M_IsFalling = false;
}
