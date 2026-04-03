#include "AMYGM.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include "Engine.h"
AMYGM::AMYGM()
{
	Name = "MyGM";
	Font = TTF_OpenFont("asset/MonaS12TextKR.ttf", 24);
}

AMYGM::~AMYGM()
{
}

void AMYGM::GameOver()
{
	static bool bGameOver = false;

	if (!bGameOver)
	{
		SDL_Color White = { 255, 255, 255, 255 };
		SDL_Surface* Surface = TTF_RenderText_Blended(Font, "게임오버", White);
		// Surface를 Texture로 변환
		SDL_Texture* Texture = SDL_CreateTextureFromSurface(GEngine->GetRenderer(), Surface);

		SDL_Rect DestRect = { X, Y, Surface->w, Surface->h };
		SDL_RenderCopy(GEngine->GetRenderer(), Texture, nullptr, &DestRect);

		// 메모리 해제 (중요: 매 프레임 생성한다면 반드시 해제해야 함)
		SDL_FreeSurface(Surface);
		SDL_DestroyTexture(Texture);
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