#include "Actor.h"
#include <Windows.h>
#include <iostream>

AActor::AActor(int InX, int InY, char InMesh) : X(InX), Y(InY), Mesh(InMesh)
{
 
}
AActor::~AActor()
{

}
void AActor::Render()
{
    COORD Rendering;
    Rendering.X = X;
    Rendering.Y = Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Rendering);

    std::cout << Mesh;

}

void AActor::SetLocationActor(int InX, int InY)
{
	X = InX;
	Y = InY;
}


