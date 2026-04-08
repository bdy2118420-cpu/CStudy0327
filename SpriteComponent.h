#pragma once
#include "Component.h"
#include "RenderableComponent.h"
#include "SDL.h"

class USpriteComponent : public UComponent, public IRenderableComponent
{
public:
	USpriteComponent();
	~USpriteComponent();

	virtual void BeginPlay() override;

	virtual void Tick() override;

	
	virtual void Render() override;


	SDL_Surface* Image;
	SDL_Texture* Texture;
};
