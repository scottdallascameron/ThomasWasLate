#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class PlayableCharacter
{
	//shared with thomas and bob 
protected:

	Sprite m_Sprite;

	//how long does a jump last
	float m_JumpDuration;

	//is the character currently jumping or falling
	bool M_IsJumping;
	bool M_IsFalling;

	//which direction is the character currently moving in]
	bool m_LeftPressed;
	bool m_RightPressed;

	//how long has this jump lasted so far
	float m_TimeThisJump;

	//has the player just initiated the jump
	bool m_JustJumped = false;

//these variables can only be viewed by this class, not the subclasses
private:

	//what is the gravity?
	float m_Gravity;

	//how fast is the character?
	float m_Speed = 400;

	//where is the player
	Vector2f m_position;

	// where are the character's body parts
	FloatRect m_Feet;
	FloatRect m_Head;
	FloatRect m_Right;
	FloatRect m_Left;

	Texture m_texture;

		
//public functions available to all other classes (and this one)
public:

	void spawn(Vector2f startposition, float gravity);

	//this is a pure virtual function
	//this means this class becomes an abstract class
	//meaning we cannot create an instance of this class, sub classes
	//sub classses MUST implement this funbtion in order to create instances
	bool virtual handleInput() = 0;

		//where is the player?
		FloatRect getPosition();

		// a rectangle representing the position of different aprts of the sprite
		FloatRect getFeet();
		FloatRect getHead();
		FloatRect getRight();
		FloatRect getLeft();

		//get a copy of sprite
		Sprite getSprite();

		//make the characte rstop falling
		void stopFalling(float position);
		void stopRight(float position);
		void stopLeft(float position);
		void stopJump();

		//where is the centre of the character
		Vector2f getCentre();

		//we will call this function once every frame
		void update(float elapsedTime);

}; //end of PlayableCharacter