#include<iostream>
#include "Engine.h"
#include "World.h"
#include "Selection.h"
using namespace std;

int main()
{

	//GEngine->GetInstance();

	//GEngine->GetWorld()->Load("Text.txt");

	//GEngine->Run();

	//return 0;
	class Selection selection;
	float Data[10] = { 9, 1, 3, 5, 4, 6, 7, 8, 2 ,10 };
	
	selection.Sort(Data);
	
	for (int i = 0; i < 10; i++)
	{
		cout << Data[i] << " ";
	}
	
}