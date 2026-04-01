#include "Monster.h"
AMonster::AMonster(int InX, int InY, char InMesh)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	ZOrder = 50;

	R = 255;
	G = 0;
	B = 255;
}
AMonster::~AMonster()
{
}
