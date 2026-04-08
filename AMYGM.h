#pragma once
#include "GameMode.h"
#include "SDL_ttf.h"

class AMYGM : public AGameMode
{
public:
	AMYGM();
	virtual ~AMYGM();

	void GameOver();
	void GameComplete();

};


