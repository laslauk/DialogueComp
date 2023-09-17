// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterZDBase.h"
#include "AttributeSetBase.h"


ACharacterZDBase::ACharacterZDBase() {

	AbilitySystemComp    = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComp");
	AttributeSetBaseComp = CreateDefaultSubobject<UAttributeSetBase>("AttributeSetBaseComp");

}

UAbilitySystemComponent* ACharacterZDBase::GetAbilitySystemComponent() const {
	return AbilitySystemComp;
 }


void ACharacterZDBase::AquireAbility(TSubclassOf<UGameplayAbility> AbilityToAquire) {

	if (AbilitySystemComp) {
		//run at server
		if (AbilityToAquire) {
			AbilitySystemComp->GiveAbility(FGameplayAbilitySpec(AbilityToAquire, 1, 0));
		}
		AbilitySystemComp->InitAbilityActorInfo(this, this);
	}

}