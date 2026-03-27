#pragma once
#include <vector>

class UWorld;


class UEngine
{
public:
	UEngine();
	~UEngine();

	void Init();
	void Term();

	void Run();

	inline UWorld* GetWorld()
	{
		return World;
	}

protected:
	void input();
	void Tick();
	void Render();

	class UWorld* World;

	int bIsRunning : 1;
};

