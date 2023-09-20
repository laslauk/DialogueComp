// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/ItemActorBase.h"
#include "Inventory/InventoryItemInstance.h"
#include "PaperSpriteComponent.h"
#include "Components/SphereComponent.h"
#include "LassevaniaCommonTypes.h"




AItemActorBase::AItemActorBase(const FObjectInitializer& ObjectInitializer)
{

	PrimaryActorTick.bCanEverTick = false;
	SpriteComponent = ObjectInitializer.CreateDefaultSubobject<UPaperSpriteComponent>(this, TEXT("Paper Sprite Component"));
	SpriteComponent->RegisterComponent();

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->RegisterComponent();
	SetRootComponent(SphereComponent);
}

const UItemStaticData* AItemActorBase::GetItemStaticData() const
{
	if (IsValid(ItemStaticDataClass))
	{
		return GetDefault<UItemStaticData>(ItemStaticDataClass);
	}
	return nullptr;
}

// Called when the game starts or when spawned
void AItemActorBase::BeginPlay()
{
	Super::BeginPlay();
	
	/* 1. show pickup text widget */


	/* This item has been placed to world in editor: This actor drives the creation of item instance */
	/* Uses ItemStaticData to create the instance */
	 

	/* Ei o viel‰ Liitty‰‰ItemInstanssia actorilla */
	if (IsValid(ItemInstance) == false && IsValid(ItemStaticDataClass))
	{
		ItemInstance = NewObject<UInventoryItemInstance>();
		ItemInstance->Init
		(
			ItemStaticDataClass, /*static data*/
			nullptr,			/*no owner of the item instance, placed in world */
			1					/*Quantity*/
		);


		/*
		UE_LOG(LogTemp, Warning, TEXT(" AAAAAAAAA "));
		if (SpriteComponent)
		{
			UPaperSprite* Sprite =  GetItemStaticData()->ActorSprite;
			UE_LOG(LogTemp, Warning, TEXT("BBBBBBBBB"));
			if (Sprite)
			{
				UE_LOG(LogTemp, Warning, TEXT(" CCCCCCCCC"));
				SpriteComponent->SetSprite(Sprite);
			}
		
		}
		*/
		//SpriteComponent->Attac
	}




}

// Called every frame
void AItemActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItemActorBase::Interact(APlayerController* PlayerController)
{
	UE_LOG(LogTemp, Warning, TEXT("INTeracting with item from: %s"), *PlayerController->GetName());
}

void AItemActorBase::Init(UInventoryItemInstance* InInstance, int32 Quantity)
{
}

UInventoryItemInstance* AItemActorBase::GetItemInstance()
{
	return nullptr;
}

void AItemActorBase::ShowPickupWidget(bool bShowWidget)
{
}

