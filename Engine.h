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

protected:
	void input();
	void Tick();
	void Render();

	class UWorld* World;
};

