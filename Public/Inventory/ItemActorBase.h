// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Interfaces/InteractInterface.h"
#include "ItemActorBase.generated.h"

class UInventoryItemInstance;
class UItemStaticData;
class UPaperSpriteComponent;

/* This class represents the Object IN WORLD, that can be picked up, has a pointer to owning item instance.
When picked up., it is destroyed*/

/* 

InventoryItemInstance
-has ptr to this actor class 
-ptr data to staticdata


IF ACTOR PLACED IN WORLD:
-> Begin play creates inventoryItemInstance

ItemStaticData 
	->


*/

UCLASS()
class LASSEVANIA_API AItemActorBase : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemActorBase(const FObjectInitializer& ObjectInitializer);

	const UItemStaticData* GetItemStaticData() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/* interact interface */
	UFUNCTION(BlueprintCallable)
	virtual void Interact(APlayerController* PlayerController) override;

	void Init(class UInventoryItemInstance* InInstance, int32 Quantity = 1);

	UInventoryItemInstance* GetItemInstance();

	UPROPERTY(VisibleAnywhere, Category = " Item properties")
	class UWidgetComponent* PickupTextWidget;

	void ShowPickupWidget(bool bShowWidget);

	/* Used to create instance when placed to the world */
	UPROPERTY(EditAnywhere)
	TSubclassOf<UItemStaticData> ItemStaticDataClass;

	UPROPERTY(EditAnywhere)
		class USphereComponent* SphereComponent;
private:
	UPROPERTY(VisibleAnywhere)
	class UPaperSpriteComponent* SpriteComponent;

	class UInventoryItemInstance* ItemInstance = nullptr;

};
