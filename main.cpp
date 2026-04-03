#include <iostream>
#include "Engine.h"
#include "World.h"

#include "Actor.h"
#include "Floor.h"
#include "SpriteComponent.h"
#include "RenderableComponent.h"
#include "AMYGM.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"


#define FActorBedinOverlapSignature 
int SDL_main(int argc, char* argv[])
{
	GEngine->GetWorld()->SetGameMode(new AMYGM());
	GEngine->GetWorld()->Load("Text.txt");

	GEngine->Run();

	delete GEngine;

	return 0;
}

