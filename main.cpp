#include <iostream>
#include "Engine.h"
#include "World.h"

#include "Actor.h"
#include "Floor.h"
#include "SpriteComponent.h"
#include "RenderableComponent.h"


#define FActorBedinOverlapSignature 
int SDL_main(int argc, char* argv[])
{

	GEngine->GetWorld()->Load("Text.txt");

	GEngine->Run();

	delete GEngine;

	return 0;
}

