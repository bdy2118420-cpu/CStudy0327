#pragma once

#include <vector>
#include <Windows.h>

#include "SDL.h"

#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")

class AActor;
class UWorld;

struct SDL_Window;

struct SDL_Renderer;

class UEngine
{
protected:
	UEngine();

	static UEngine* Instance;

public:
	~UEngine();

	static UEngine* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new UEngine();
		}

		return Instance;
	}

	void Init();
	void Term();

	void Run();
	void Stop();

	inline UWorld* GetWorld()
	{
		return World;
	}


	//Renderer
	HANDLE ScreenBufferHandle[2];
	int ActiveScreenBufferIndex = 0;

	void InitBuffer();
	void Clear();
	void Render(int InX, int InY, char InMesh);
	void Render(int InX, int InY, int R, int G, int B);
	void Flip();
	void TermBuffer();

	inline const SDL_Event& GetEvent()
	{
		return MyEvent;
	}

protected:
	void Input();
	void Tick();
	void Render();


	SDL_Window* MyWindow;

	SDL_Renderer* MyRender;

	SDL_Event MyEvent;

	class UWorld* World;

	int bIsRunning : 1;

};


#define GEngine			UEngine::GetInstance()
