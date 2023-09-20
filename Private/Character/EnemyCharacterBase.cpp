// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/EnemyCharacterBase.h"
#include "AbilitySystem/LVAbilitySystemComponent.h"


AEnemyCharacterBase::AEnemyCharacterBase()
{

	AbilitySystemComponent = CreateDefaultSubobject<ULVAbilitySystemComponent>(TEXT("Ability System Component"));
}

void AEnemyCharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	ApplyStartupEffects();

}

UAbilitySystemComponent* AEnemyCharacterBase::GetAbilitySystemComponent() const
{
	return GetLVAbilitySystemComponent();
}


/*
void AEnemyCharacterBase::ApplyStartupEffects()
{
	UE_LOG(LogTemp, Warning, TEXT("Calling CHARACYTER ZD BASE GetAbilitySysteMComp()"));
	if (GetAbilitySystemComponent() == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("homo"));

		return;
	}
	FGameplayEffectContextHandle EffectContext = GetAbilitySystemComponent()->MakeEffectContext();


	EffectContext.AddSourceObject(this);

	for (auto CharEffect : CharacterData.EffectsDefault)
	{
		ApplyGameplayEffectToSelf(CharEffect, EffectContext);
	}

}

*/