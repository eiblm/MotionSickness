// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PickUpItem.generated.h"

UCLASS()
class THEBEGINNING_API APickUpItem : public AActor
{
	GENERATED_UCLASS_BODY()
	
public:	
	// Sets default values for this actor's properties
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
		FString Name;
	// How much you are getting
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
		int32 Quantity;
	// the sphere you collide with to pick item up
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Item)
		USphereComponent*  ProxSphere;
	// The mesh of the item
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Item)
		UStaticMeshComponent* Mesh;
	// The icon that represents the object in UI/canvas
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
		UTexture2D* Icon;
	// When something comes inside ProxSphere, this function runs
	UFUNCTION(BlueprintNativeEvent, Category = Collision)
		void Prox(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32
		OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	
	
};
