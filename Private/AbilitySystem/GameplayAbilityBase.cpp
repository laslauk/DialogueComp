// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/GameplayAbilityBase.h"

UGameplayAbilityBase::UGameplayAbilityBase(const FObjectInitializer& ObjectInitializer)
{
	ActivationPolicy = EAbilityActivationPolicy::OnInputTriggered;
}

void UGameplayAbilityBase::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
}

void UGameplayAbilityBase::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
}

AController* UGameplayAbilityBase::GetControllerFromActorInfo() const
{
	return nullptr;
}
