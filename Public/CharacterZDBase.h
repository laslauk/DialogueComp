// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "AbilitySystemComponent.h"
#include "Abilities/GameplayAbility.h"
#include "AbilitySystemInterface.h"
#include "CharacterZDBase.generated.h"


class UAttributeSetBase;

/**
 * 
 */
UCLASS()
class LASSEVANIA_API ACharacterZDBase : public APaperZDCharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()
	

public:


	ACharacterZDBase();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "CharacterBase")
	UAbilitySystemComponent* AbilitySystemComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "CharacterBase")
	UAttributeSetBase* AttributeSetBaseComp;


	UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
	void AquireAbility(TSubclassOf<UGameplayAbility> AbilityToAquire);


};
