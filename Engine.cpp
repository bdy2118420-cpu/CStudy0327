#include "Engine.h"
#include "World.h"
#include <conio.h>

UEngine* UEngine::Instance = nullptr;
UEngine::UEngine()
{
	Init();
}

UEngine::~UEngine()
{
	Term();
}

void UEngine::Init()
{
	bIsRunning = true;

	World = new UWorld();
}

void UEngine::Term()
{
	delete World;
	World = nullptr;
}


void UEngine::Run()
{
	while (bIsRunning)
	{
		Tick();
		Render();
	}
}

void UEngine::input()
{
	int KeyCode = _getch();
}

void UEngine::Tick()
{
	World->Tick();
}

void UEngine::Render()
{
	World->Render();
}