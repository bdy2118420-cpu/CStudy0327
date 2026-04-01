#include "Wall.h"
AWall::AWall(int InX, int InY, char InMesh)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	ZOrder = 1;

	R = 255;
	G = 255;
	B = 0;
}

AWall::~AWall()
{
}
