// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeSetBase.h"
#include "GameplayEffectExtension.h"
#include "GameplayEffect.h"

UAttributeSetBase::UAttributeSetBase():Health(100.0f) {

}



void UAttributeSetBase::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) {

	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<FProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Health))) {
		UE_LOG(LogTemp, Warning, TEXT("Damaged damage, now health is: %f"), Health.GetCurrentValue());
	}
	
}