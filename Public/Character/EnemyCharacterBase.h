// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "CharacterZDBase.h"
#include "EnemyCharacterBase.generated.h"

/**
 * 
 */
UCLASS()
class LASSEVANIA_API AEnemyCharacterBase : public ACharacterZDBase, public IAbilitySystemInterface
{
	GENERATED_BODY()


public:

	AEnemyCharacterBase();

	virtual void PossessedBy(AController* NewController) override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	//virtual void ApplyStartupEffects() override;

	FORCEINLINE class ULVAbilitySystemComponent* GetLVAbilitySystemComponent() const { return AbilitySystemComponent; }


	UPROPERTY(VisibleAnywhere, Category = "Lassevania|Ability System")
	TObjectPtr<class ULVAbilitySystemComponent> AbilitySystemComponent;

private:



	
};
