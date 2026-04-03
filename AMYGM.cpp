#include "AMYGM.h"
#include "SDL.h"

AMYGM::AMYGM()
{
	Name = "MyGM";
}

AMYGM::~AMYGM()
{
}

void AMYGM::GameOver()
{
	static bool bGameOver = false;

	if (!bGameOver)
	{
		SDL_Log("Game Over");
		bGameOver = true;
	}
}

void AMYGM::GameComplete()
{
	static bool bGameComplte = false;

	if (!bGameComplte)
	{
		SDL_Log("Game Complete");

		bGameComplte = true;
	}
}