#pragma once
#include "Character.h"


class USpritePlayerComponent;
class UCollisionComponent;
class AActor;

class APlayer : public ACharacter
{
public:
	APlayer(int InX = 1, int InY = 1, char InMesh = 'P');
	virtual ~APlayer();

	virtual void BeginPlay() override;

	virtual void Tick() override;

	virtual void ReceiveHit(AActor* Other) override;

	void ProcessBeginOverlap(AActor* OtherActor);

	USpritePlayerComponent* SpriteAnimationComponent;

	UCollisionComponent* CollisionComponent;
};
