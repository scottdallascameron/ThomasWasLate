#pragma once
#include "Playable.h"

class Thomas:public PlayableCharacter
{
public:

	//constructor
	Thomas();

	//this will implement the pure virtual function from playablecharacter
		bool virtual handleInput();


};	//end of thomas class