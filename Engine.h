#pragma once
#include <vector>

class UWorld;


class UEngine
{
protected:
	UEngine();

	static UEngine* Instance;
public:


	static UEngine* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new UEngine();
		}

		return Instance;
	}
	~UEngine();

	void Init();
	void Term();

	void Run();

	inline UWorld* GetWorld()
	{
		return World;
	}

	static int KeyCode;

protected:
	void input();
	void Tick();
	void Render();

	int Num;

	class UWorld* World;

	int bIsRunning : 1;
};

#define GEngine			UEngine::GetInstance()

