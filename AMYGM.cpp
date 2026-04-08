#include "AMYGM.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include "Engine.h"
#include "World.h"
#include "YoudieActor.h"
#include "RenderableComponent.h"
#include "Component.h"
#include "TextRenderActor.h"
#include "TextRenderComponet.h"
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

		AYoudieActor* TextActor = dynamic_cast<AYoudieActor*>(GEngine->GetWorld()->GetActorOfClass<AYoudieActor>());
		if (TextActor)
		{
			TextActor->TextRenderComponet->bIsVisible = true;
		}
	
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