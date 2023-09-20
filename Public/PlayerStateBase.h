// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "PlayerStateBase.generated.h"

class UAbilitySystemComponent;
class UInventoryComponent;
class APlayerControllerBase;
class ULVAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class LASSEVANIA_API APlayerStateBase : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	
	
	APlayerStateBase();


	FORCEINLINE ULVAbilitySystemComponent* GetLVAbilitySystemComponent() const { return AbilitySystemComponent; }
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	

	UFUNCTION(BlueprintCallable)
	FORCEINLINE UInventoryComponent* GetInventoryComponent() { return InventoryComponent; }


	/* TODO DEFAULT ABVILITIES AND ACQUIRING AND GIVING ABILTIIES, DO LIKE IN LYRA FOR STARTERS */
	/* separate different activation methods */

	// The ability system component sub-object used by player characters.
	UPROPERTY(VisibleAnywhere, Category = "Lassevania|PlayerState")
	TObjectPtr<ULVAbilitySystemComponent> AbilitySystemComponent;



private:

	UInventoryComponent* InventoryComponent;
	APlayerControllerBase* PlayerController;

	//UAbilitySystemComponent* AbilitySystemComponent;


};
