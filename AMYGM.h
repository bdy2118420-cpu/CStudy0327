#pragma once
#include "GameMode.h"
#include "SDL_ttf.h"

struct TTF_Font;
class AMYGM : public AGameMode
{
public:
	AMYGM();
	virtual ~AMYGM();

	void GameOver();
	void GameComplete();
	TTF_Font* Font;
};


