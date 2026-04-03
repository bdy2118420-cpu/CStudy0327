#include "Player.h"
#include "Engine.h"
#include "World.h"
#include "GameplayStatics.h"
#include "ResourceManager.h"
#include "USpritePlayerComponent.h"
#include "CollisionComponent.h"

APlayer::APlayer(int InX, int InY, char InMesh)
{
	X = InX;
	Y = InY;

	SpriteAnimationComponent = CreateDefaultSubobject<USpritePlayerComponent>("Sprite");

	Resource TempResource = GEngine->GetResourceManager()->LoadTexture("Data/player.bmp", true, 255, 0, 255);
	SpriteAnimationComponent->Image = TempResource.Image;
	SpriteAnimationComponent->Texture = TempResource.Texture;
	SpriteAnimationComponent->ZOrder = 100;
	SpriteAnimationComponent->ExecutionTime = 0.15f;

	CollisionComponent = CreateDefaultSubobject<UCollisionComponent>("Collision");
	CollisionComponent->bIsGenerateHit = true;
	CollisionComponent->bIsGenerateOverlap = true;

}

APlayer::~APlayer()
{
}

void APlayer::BeginPlay()
{
	__super::BeginPlay();

	OnActorBeginOverlap = [&](AActor* Other) -> void {
		SDL_Log("Clear");
		};


}

void APlayer::Tick()
{
	__super::Tick();

	SDL_Event Event = GEngine->GetEvent();

	if (Event.type == SDL_KEYDOWN)
	{
		SDL_Keycode KeyCode = Event.key.keysym.sym;

		if (KeyCode == SDLK_w && PredictMove(X, Y - 1))
		{
			Y--;
			SpriteAnimationComponent->SpriteIndexY = 2;
			SpriteAnimationComponent->SpriteIndexX = 0;
		}
		if (KeyCode == SDLK_s && PredictMove(X, Y + 1))
		{
			Y++;
			SpriteAnimationComponent->SpriteIndexY = 3;
			SpriteAnimationComponent->SpriteIndexX = 0;
		}
		if (KeyCode == SDLK_a && PredictMove(X - 1, Y))
		{
			X--;
			SpriteAnimationComponent->SpriteIndexY = 0;
			SpriteAnimationComponent->SpriteIndexX = 0;
		}
		if (KeyCode == SDLK_d && PredictMove(X + 1, Y))
		{
			X++;
			SpriteAnimationComponent->SpriteIndexY = 1;
			SpriteAnimationComponent->SpriteIndexX = 0;
		}
		if (KeyCode == SDLK_ESCAPE)
		{
			GEngine->Stop();
		}
	}
}

void APlayer::ReceiveHit(AActor* Other)
{

}

void APlayer::ProcessBeginOverlap(AActor* OtherActor)
{
	SDL_Log("��ħ ");
}

