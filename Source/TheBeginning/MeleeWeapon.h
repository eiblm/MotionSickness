// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MeleeWeapon.generated.h"
class AMonster;
UCLASS()
class THEBEGINNING_API AMeleeWeapon : public AActor
{
	GENERATED_UCLASS_BODY()
	
	public:
		// The amount of damage attacks by this weapon do
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MeleeWeapon)
	float AttackDamage;
	// A list of things the melee weapon already hit this swing
	// Ensures each thing sword passes thru only gets hit once
	TArray<AActor*> ThingsHit;
	// prevents damage from occurring in frames where
	// the sword is not swinging
	bool Swinging;
	// "Stop hitting yourself" - used to check if the
	// actor holding the weapon is hitting himself
	AMonster *WeaponHolder;
	// bounding box that determines when melee weapon hit
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = MeleeWeapon)
		UBoxComponent* ProxBox;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category =MeleeWeapon)
		UStaticMeshComponent* Mesh;
	UFUNCTION(BlueprintNativeEvent, Category = Collision)
	void Prox(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	void Swing();
	void Rest();

	
	
};
