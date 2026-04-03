#include "USpritePlayerComponent.h"
#include "Engine.h"
#include "Actor.h"
#include "GameplayStatics.h"
USpritePlayerComponent::USpritePlayerComponent()
{
}

USpritePlayerComponent::~USpritePlayerComponent()
{
}


void USpritePlayerComponent::Tick()
{
	__super::Tick();

	ElapsedTime += UGameplayStatics::GetWorldDeltaSeconds();
	if (ElapsedTime >= ExecutionTime)
	{
		SpriteIndexX++;
		SpriteIndexX = SpriteIndexX % 5;
		ElapsedTime = 0;
	}
}

void USpritePlayerComponent::Render()
{
	int TileSize = 30;
	int SpriteSizeX = Image->w / 5;
	int SpriteSizeY = Image->h / 5;


	SDL_Rect SourceRect = { SpriteIndexX * SpriteSizeX, SpriteIndexY * SpriteSizeY, SpriteSizeX, SpriteSizeY };
	SDL_Rect DestinationRect = { Owner->GetX() * TileSize, Owner->GetY() * TileSize, TileSize, TileSize };
	SDL_RenderCopy(GEngine->GetRenderer(), Texture, &SourceRect, &DestinationRect);
}
