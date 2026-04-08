#include "Player.h"
#include "Engine.h"
#include "World.h"
#include "GameplayStatics.h"
#include "ResourceManager.h"
#include "USpritePlayerComponent.h"
#include "CollisionComponent.h"
#include "Goal.h"
#include "AMYGM.h"
#include "Monster.h"

APlayer::APlayer(int InX, int InY, char InMesh)
{
	X = InX;
	Y = InY;

	//Resource TempResource = GEngine->GetResourceManager()->LoadTexture("Data/player.bmp", true, 255, 0, 255);
	//Image = TempResource.Image;
	//Texture = TempResource.Texture;

	SpriteAnimationComponent = CreateDefaultSubobject<USpritePlayerComponent>("Sprite");

	Resource TempResource = GEngine->GetResourceManager()->LoadTexture("Data/player.bmp", true, 255, 0, 255);
	SpriteAnimationComponent->Image = TempResource.Image;
	SpriteAnimationComponent->Texture = TempResource.Texture;
	SpriteAnimationComponent->ZOrder = 100;
	SpriteAnimationComponent->ExecutionTime = 0.15f;

	CollisionComponent = CreateDefaultSubobject<UCollisionComponent>("Collision");
	CollisionComponent->bIsGenerateHit = true;
	CollisionComponent->bIsGenerateOverlap = true;

	Name = "Player";

}

APlayer::~APlayer()
{
}

void APlayer::BeginPlay()
{
	__super::BeginPlay();

	OnActorBeginOverlap = [&](AActor* Other) -> void {
		AGoal* Goal = dynamic_cast<AGoal*>(Other);
		if (Goal)
		{
			AMYGM* GM = dynamic_cast<AMYGM*>(UGameplayStatics::GetGameMode());
			if (GM)
			{
				GM->GameComplete();
			}
		}

		AMonster* Monster = dynamic_cast<AMonster*>(Other);
		if (Monster)
		{
			AMYGM* GM = dynamic_cast<AMYGM*>(UGameplayStatics::GetGameMode());
			if (GM)
			{
				GM->GameOver();
			}
		}
		};

	//OnActorBeginOverlap = std::bind(&APlayer::ProcessBeginOverlap, this, std::placeholders::_1);

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
	SDL_Log("WWW");
}

