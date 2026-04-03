#pragma once
#include "Character.h"

#include <xkeycheck.h>

class USpritePlayerComponent;
class UCollisionComponent;
class Actor;
class APlayer : public ACharacter
{
public:
	APlayer(int InX = 1, int InY = 1, char InMesh = 'P');
	virtual ~APlayer();

	virtual void BeginPlay() override;

	virtual void Tick() override;

	void ProcessBeginOverlap(class AActor* OtherActor);

	virtual void ReceiveHit(class AActor* Other) override;

	USpritePlayerComponent* SpriteAnimationComponent;

	UCollisionComponent* CollisionComponent;

	

protected:


};
