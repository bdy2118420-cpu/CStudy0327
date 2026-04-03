#pragma once
#include "SpriteComponent.h"
#include "SDL.h"

class USpritePlayerComponent : public USpriteComponent
{
public:
	USpritePlayerComponent();
	~USpritePlayerComponent();



	virtual void Tick() override;

	virtual void Render() override;

	int SpriteIndexX = 0;
	int SpriteIndexY = 0;

	float ElapsedTime = 0;
	float ExecutionTime = 0.1f;
};
