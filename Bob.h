#pragma once
#include "Playable.h"

class Bob :public PlayableCharacter
{
public:

	//constructor
	Bob();

	//this will implement the pure virtual function from playablecharacter
	bool virtual handleInput();


};	//end of Bob class