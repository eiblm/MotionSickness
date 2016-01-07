// Fill out your copyright notice in the Description page of Project Settings.

#include "TheBeginning.h"
#include "Monster.h"
#include "Avatar.h"



AMonster::AMonster(const class FObjectInitializer& PCIP) : 
Super(PCIP)
{
	Speed = 20;
	HitPoints = 20;
	Experience = 0;
	BPLoot = NULL;
	BaseAttackDamage = 1;
	AttackTimeout = 1.5f;
	TimeSinceLastStrike = 0;
	SightSphere = PCIP.CreateDefaultSubobject<USphereComponent>(this,
		TEXT("SightSphere"));
	SightSphere->AttachTo(RootComponent);
	AttackRangeSphere = PCIP.CreateDefaultSubobject <USphereComponent>(this,
		TEXT("AttackRangeSphere"));
	AttackRangeSphere->AttachTo(RootComponent);
}
void AMonster::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	// basic intel: move the monster towards the player
	AAvatar *avatar = Cast<AAvatar>(
		UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	/*if (!avatar){
		return;
	}*/
	FVector toPlayer = avatar->GetActorLocation() - GetActorLocation();
	//toPlayer.Normalize(); // reduce to unit vector
	// Actually move the monster towards the player a bit
	float distanceToPlayer = toPlayer.Size();
	// If the player is not in the SightSphere of the monster,
	// go back
	if (distanceToPlayer > SightSphere->GetScaledSphereRadius())
	{
		// If the player is out of sight,
		// then the enemy cannot chase
		return;
	}
	toPlayer /= distanceToPlayer;
	AddMovementInput(toPlayer, Speed*DeltaSeconds);
	// At least face the target
	// Gets you the rotator to turn something
	// that looks in the `toPlayer` direction
	FRotator toPlayerRotation = toPlayer.Rotation();
	toPlayerRotation.Pitch = 0; // 0 off the pitch
	RootComponent->SetWorldRotation(toPlayerRotation);
}