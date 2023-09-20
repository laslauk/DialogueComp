// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InventoryItemInstance.generated.h"



class AItemActorBase;
class UItemStaticData;
class UWorld;
/**
 * 
 */
UCLASS()
class LASSEVANIA_API UInventoryItemInstance : public UObject
{
	GENERATED_BODY()

public:

	virtual void Init(TSubclassOf<class UItemStaticData> ItemStaticDataClass, AActor* owner, int32 InQuantity = 1);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	const UItemStaticData* GetItemStaticData() const; //static datat

	/* UOBJECT ALWAYS returns nullptr GetWorld() joten teh‰‰ oma override*/
	virtual UWorld* GetWorld() const override final;

	virtual void OnEquipped(AActor* InOwner = nullptr);
	virtual void OnUnequipped(AActor* InOwner = nullptr);
	virtual void OnDropped(AActor* InOwner = nullptr);


	UFUNCTION(BlueprintCallable,BlueprintPure)
	AItemActorBase* GetItemActor() const;

	AActor* GetItemOwnerActor();
	/* add abilities on equip */
	void TryGrantAbilities(AActor* InOwner);
	void TryRemoveAbilities(AActor* inOwner);

	/* add Effects on equip */
	void TryApplyEffects(AActor* InOwner);
	void TryRemoveEffects(AActor* inOwner);

protected:






	//effect handles to be saved for use
	UPROPERTY(EditDefaultsOnly, Category = "Effects")
		TArray<FActiveGameplayEffectHandle> OnGoingItemAddedEffectHandles;

	UPROPERTY()
	TArray<FGameplayAbilitySpecHandle> GrantedAbilityHandles;

private:

	UPROPERTY(/* replicated */)
	TSubclassOf<class UItemStaticData> ItemStaticDataClass;


	UPROPERTY()
	class AActor* OwningActor;

	UPROPERTY()
	AItemActorBase* ItemActor;


};
