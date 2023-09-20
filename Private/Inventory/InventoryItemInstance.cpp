// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/InventoryItemInstance.h"



void UInventoryItemInstance::Init(TSubclassOf<class UItemStaticData> ItemStaticDataClassIn, AActor* OwnerActorIn, int32 InQuantity)
{
}

const UItemStaticData* UInventoryItemInstance::GetItemStaticData() const
{
	return nullptr;
}

UWorld* UInventoryItemInstance::GetWorld() const
{
	return nullptr;
}

void UInventoryItemInstance::OnEquipped(AActor* InOwner)
{
}

void UInventoryItemInstance::OnUnequipped(AActor* InOwner)
{
}

void UInventoryItemInstance::OnDropped(AActor* InOwner)
{
}

AItemActorBase* UInventoryItemInstance::GetItemActor() const
{
	return nullptr;
}

AActor* UInventoryItemInstance::GetItemOwnerActor()
{
	return nullptr;
}

void UInventoryItemInstance::TryGrantAbilities(AActor* InOwner)
{
}

void UInventoryItemInstance::TryRemoveAbilities(AActor* inOwner)
{
}
