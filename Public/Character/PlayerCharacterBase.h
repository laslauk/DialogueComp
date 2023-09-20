// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterZDBase.h"
#include "PlayerCharacterBase.generated.h"

/**
 * 
 */
UCLASS()
class LASSEVANIA_API APlayerCharacterBase : public ACharacterZDBase
{
	GENERATED_BODY()
	

public:

	UFUNCTION(BlueprintCallable)
	APlayerControllerBase* GetPlayerController();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;


	UFUNCTION(BlueprintCallable)
	APlayerStateBase* GetPlayerState();
	UFUNCTION(BlueprintCallable)
	void SetPlayerState(APlayerStateBase* PlayerStateIn);


	//virtual void ApplyStartupEffects() override;

	UFUNCTION(BlueprintCallable)
		void SetPlayerController(APlayerControllerBase* PlayerControllerIn);

	UFUNCTION(BlueprintCallable)
		void TryInteract();

private:


	APlayerStateBase* PlayerState;
	APlayerControllerBase* PlayerController;



};
