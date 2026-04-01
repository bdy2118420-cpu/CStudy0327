#include "Engine.h"
#include <conio.h>
#include "Actor.h"
#include "World.h"
#include "SDL.h"
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
	SDL_Init(SDL_INIT_EVERYTHING);

	MyWindow = SDL_CreateWindow("Hello", 100, 100, 640, 480, SDL_WINDOW_SHOWN);

	MyRender = SDL_CreateRenderer(MyWindow, -1, 0);

	bIsRunning = true;

	InitBuffer();

	World = new UWorld();
}

void UEngine::Term()
{
	SDL_DestroyWindow(MyWindow);//delete포함 api등등 모두 정리

	SDL_DestroyRenderer(MyRender);

	SDL_Quit();

	delete World;
	TermBuffer();
	World = nullptr;
}


void UEngine::Run()
{
	while (bIsRunning)
	{
		SDL_PollEvent(&MyEvent);

		Input();
		Tick();
		Render();
	}
}

void UEngine::Stop()
{
	bIsRunning = false;
}


void UEngine::InitBuffer()
{
	ScreenBufferHandle[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	ScreenBufferHandle[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	CONSOLE_CURSOR_INFO ConsoleCursorInfo;
	ConsoleCursorInfo.dwSize = 1;
	ConsoleCursorInfo.bVisible = FALSE;

	SetConsoleCursorInfo(ScreenBufferHandle[0], &ConsoleCursorInfo);
	SetConsoleCursorInfo(ScreenBufferHandle[1], &ConsoleCursorInfo);

}

void UEngine::Clear()
{
	DWORD DW;
	FillConsoleOutputCharacter(ScreenBufferHandle[ActiveScreenBufferIndex], ' ', 80 * 25, COORD{ 0, 0 }, &DW);
}

void UEngine::Render(int InX, int InY, char InMesh)
{
	char MeshString[2] = { 0, };
	MeshString[0] = InMesh;

	SetConsoleCursorPosition(ScreenBufferHandle[ActiveScreenBufferIndex], COORD{ (SHORT)InX, (SHORT)InY });
	WriteFile(ScreenBufferHandle[ActiveScreenBufferIndex], MeshString, 1, NULL, NULL);
}

void UEngine::Render(int InX, int InY, int R, int G, int B)
{
	SDL_SetRenderDrawColor(MyRender, R, G, B, 255);
	//SDL_RenderDrawPoint(MyRender, InX, InY);
	SDL_Rect MyRect = { InX*20,InY*20, 20, 20 };
	SDL_RenderFillRect(MyRender, &MyRect);
}


void UEngine::Flip()
{
	SetConsoleActiveScreenBuffer(ScreenBufferHandle[ActiveScreenBufferIndex]);
	ActiveScreenBufferIndex = !ActiveScreenBufferIndex;
}

void UEngine::TermBuffer()
{
	CloseHandle(ScreenBufferHandle[0]);
	CloseHandle(ScreenBufferHandle[1]);
}

void UEngine::Input()
{
}

void UEngine::Tick()
{
	if (MyEvent.type == SDL_QUIT)
	{
		bIsRunning = false;
	}
	World->Tick();
}

void UEngine::Render()
{
	//붓 색깔 설정
	SDL_SetRenderDrawColor(MyRender, 255, 255, 255, 255);
	SDL_RenderClear(MyRender);

	
	World->Render();
	//Gpu로 보내기
	SDL_RenderPresent(MyRender);
}