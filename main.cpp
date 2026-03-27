#include<iostream>
#include "Engine.h"
#include "World.h"
using namespace std;

int main()
{
	UEngine* Engine = new UEngine;

	Engine->GetWorld()->Load("Text.txt");

	Engine->Run();

	delete Engine;
}