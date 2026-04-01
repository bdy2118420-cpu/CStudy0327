#include <iostream>
#include "Engine.h"
#include "World.h"
#include <random>


using namespace std;

int SDL_main(int argc, char* argv[])
{
	//난수 발생 알고리즘
	GEngine->GetWorld()->Load("Text.txt");

	GEngine->Run();

	delete GEngine;

	return 0;



	return 0;
}



