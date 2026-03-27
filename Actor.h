#pragma once
class AActor
{
public:
	AActor(int InX=0, int InY=0, char InMesh = ' ');
	virtual ~AActor();

	virtual void Render();

	void SetLocationActor(int InX, int InY);

	

protected:
	int X;
	int Y;
	char Mesh;
};

