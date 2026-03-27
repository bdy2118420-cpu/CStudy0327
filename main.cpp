#include <iostream>
#include "Engine.h"
#include "World.h"

using namespace std;

void Sort(int* InData, int InLength, int (*Compare)(int A, int B))
{
	for (int FirstIndex = 0; FirstIndex < InLength; ++FirstIndex)
	{
		for (int SecondIndex = 0; SecondIndex < InLength; ++SecondIndex)
		{
			if (Compare(InData[FirstIndex], InData[SecondIndex])==1)
			{
				int Temp = InData[FirstIndex];
				InData[FirstIndex] = InData[SecondIndex];
				InData[SecondIndex] = Temp;
			}
		}
	}
}

int CompleteCallback()
{
	cout << "Callback" << endl;
	return 0;
}

void Connect(int (*Complete)())
{
	if (1)
	{
		Complete();
	}
}

int Ascending(int A, int B)
{
	if(A < B)
	{
		return 1;
	}
	else if (A == B)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

int Descending(int A, int B)
{
	if (A < B)
	{
		return -1;
	}
	else if (A == B)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main()
{
	//GEngine->GetWorld()->Load("level01.umap");

	//GEngine->Run();

	//delete GEngine;

	Connect(CompleteCallback);

	/*int (*CompareFunction)(void);

	CompareFunction = Compare2;

	CompareFunction();

	cout << Compare << endl;
	cout << CompareFunction << endl;*/


	int Data[8] = { 9, 1, 3, 5, 7, 8, 2, 10 };
	////search and sort
	////selection and bubble
	////1 9 3 5 4 6 7 8 2 10
	////1 2 9 5 4 6 7 8 3 10

	Sort(Data, 8, Ascending);


	for (int i = 0; i < 8; ++i)
	{
		cout << Data[i] << " ";
	}


	return 0;
}