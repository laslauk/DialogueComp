// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PlayerCharacterBase.h"
#include "AttributeSetBase.h"
#include "Inventory/InventoryComponent.h"
#include "PlayerStateBase.h"
#include "AbilitySystemComponent.h"
#include "Interfaces/InteractInterface.h"


UAbilitySystemComponent* APlayerCharacterBase::GetAbilitySystemComponent() const
{
	UE_LOG(LogTemp, Warning, TEXT("calling player characters get ability systme componetn"));

	 if (PlayerState)
	{

		 if (PlayerState->GetAbilitySystemComponent() == nullptr)
		 {
			 UE_LOG(LogTemp, Warning, TEXT("PlayerState->GetAbilitySystemComponent() == nullptr"));
		 }
		return 	PlayerState->GetAbilitySystemComponent();
	}

	else
	{
		 UE_LOG(LogTemp, Warning, TEXT("PlayerCharacterBase Ability System comp null"));

		return nullptr;
	}
}


/*

void APlayerCharacterBase::ApplyStartupEffects()
{
	UE_LOG(LogTemp, Warning, TEXT("calling APlayerCharacterBase ApplyStartupeffects"));
	if (GetAbilitySystemComponent() == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("ApplyStartupEffects GetAbiltiySYstemComp on nullptr"));

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

APlayerStateBase* APlayerCharacterBase::GetPlayerState()
{
	return PlayerState;
}

void APlayerCharacterBase::SetPlayerState(APlayerStateBase* PlayerStateIn)
{
	PlayerState = PlayerStateIn;

}



APlayerControllerBase* APlayerCharacterBase::GetPlayerController()
{
	return PlayerController;
}



void APlayerCharacterBase::SetPlayerController(APlayerControllerBase* PlayerControllerIn)
{

	PlayerController = PlayerControllerIn;
}


void APlayerCharacterBase::TryInteract()
{

	/* NOTE: Interacting with only one, may cause trouble if multiple overlapping stuff, SOLVE in game*/

	FHitResult HitResult;


	FCollisionQueryParams TraceParams(
		SCENE_QUERY_STAT(TryInteract),
		true,
		this);

	TraceParams.bReturnPhysicalMaterial = true;

	TArray<AActor*> AttachedActors;
	this->GetAttachedActors(/*out*/ AttachedActors);
	TraceParams.AddIgnoredActors(AttachedActors);

	//haetaan ase trace channel
	const ECollisionChannel TraceChannel = Lassevania_TraceChannel_Interaction;
	FVector StartTrace = GetActorLocation();
	FVector EndTrace = StartTrace;
	FCollisionShape Shape = FCollisionShape::MakeSphere(125.f);

	GetWorld()->SweepSingleByChannel(HitResult, StartTrace, EndTrace, FQuat::Identity, TraceChannel, Shape, TraceParams);
	DrawDebugSphere(GetWorld(), StartTrace, 125.f, 8, FColor::Red, false, 2.f);


	IInteractInterface* Interface = Cast<IInteractInterface>(HitResult.GetActor());

	if (Interface)
	{
		Interface->Interact(Cast<APlayerController>(GetPlayerController()));
	}
	/* Run filter ota eka mihi osuu haha */

}
