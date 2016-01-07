// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "NPC.generated.h"

UCLASS()
class THEBEGINNING_API ANPC : public ACharacter
{
	GENERATED_UCLASS_BODY()
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision)
    //class USphereComponent* ProxSphere;
		// This is the NPC's message that he has to tell us.

	
	// When you create a blueprint from this class, you want to be
	// able to edit that message in blueprints,
	// that's why we have the EditAnywhere and BlueprintReadWrite
	// properties.

	public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCMessage)
	FString NpcMessage;
	// Sets default values for this character's properties
	//ANPC();
	
	// Called when the game starts or when spawned
	//virtual void BeginPlay() override;
	
	// Called every frame
	//virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// The sphere that the player can collide with to get item
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision)
		 USphereComponent* ProxSphere;
	// The corresponding body of this function is
	// ANPC::Prox_Implementation, __not__ ANPC::Prox()!
	// This is a bit weird and not what you'd expect,
	// but it happens because this is a BlueprintNativeEvent
	UFUNCTION(BlueprintNativeEvent, Category = "Collision")
		void Prox(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32
		OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
};
