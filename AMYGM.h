#pragma once
#include "GameMode.h"
class AMYGM : public AGameMode
{
public:
	AMYGM();
	virtual ~AMYGM();

	void GameOver();
	void GameComplete();
};


