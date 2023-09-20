// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerControllerBase.generated.h"


class UMainHUDWidget;
class UAbilitySystemComponent;
class UInventoryComponent;
class APlayerCharacterBase;
class ULVAbilitySystemComponent;



/*
ABILITY ACTIVATION:
Abiltity jotka lisätään AbilitySetin kautta, on FLassevaniaAbilitySet_GameplayAbility STRUCT
jossa InputTag data määritetty DataAssetille.

PostProcessInput controllerilla kutsuu joka input handle framen jälkeen jälkeen
Oman abilitySysteemin LVASC->ProcessAbilityInput(DeltaTime, bGamePaused);
joka checkaa InputHeld, InputPRssed, input released arrayt joihin laitetaan
AbilitySpecit ja se yrittää joka kutsu aktivoida abilityn.

Esim clickauksessa katsotaan InputPressedSpecHandles mitä siellä on ja yritetään aktivoidaan ne joka
frame.

Controlleri bindataan inputit AbilityInputTagPressed(InputTag) joka 
ilmoittaa AbilitySysteemille kutsumalla ASC->AbilityInputTagPressed mikä inputTag laitetaan
InputPressed/HeldSpec handle arrayhyn.


*/

UCLASS()
class LASSEVANIA_API APlayerControllerBase : public APlayerController
{
	GENERATED_BODY()

public:


	virtual void OnPossess(APawn* aPawn) override;




	UAbilitySystemComponent* GetAbilitySystemComponent() const;
	ULVAbilitySystemComponent* GetLVAbilitySystemComponent() const;

	virtual void SetupInputComponent() override;

	void Input_AbilityInputTagPressed(FGameplayTag InputTag);

	/* Todo: input mallia void ULyraAbilitySystemComponent::ProcessAbilityInput(float DeltaTime, bool bGamePaused) LyraAbilitySystemComponent*/
	
	/* called after processing ipnut */
	virtual void PostProcessInput(const float DeltaTime, const bool bGamePaused) override;

	UInventoryComponent* GetInventoryComponent();

	APlayerCharacterBase* GetPlayerCharacter();

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UInventoryMainMenuWidget> InventoryWidgetClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UMainHUDWidget> MainHUDWIdgetClass;


	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UMapMenuWidget> MapMenuWidgetClass;



	
	/* CONTROLS */

	UPROPERTY(EditDefaultsOnly)
	class UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditDefaultsOnly)
	class UInputAction* MoveRightInputAction;

	UPROPERTY(EditDefaultsOnly)
	class UInputAction* JumpInputAction;

	UPROPERTY(EditDefaultsOnly)
	class UInputAction* SprintInputAction;

	UPROPERTY(EditDefaultsOnly)
	class UInputAction* PrimaryInputAction;

	UPROPERTY(EditDefaultsOnly)
	class UInputAction* SecondaryInputAction;


	UPROPERTY(EditDefaultsOnly)
	class UInputAction* OpenMapMenuInputAction;


	UPROPERTY(EditDefaultsOnly)
	class UInputAction* InteractInputAction;

	UPROPERTY(EditDefaultsOnly)
		class UInputAction* OpenInventoryAction;

	UPROPERTY(EditDefaultsOnly)
		class UInputAction* SlotOneInputAction; 	/* TODO JÄRKEVÄMPI SLOT SYSTEM*/

	UPROPERTY(EditDefaultsOnly)
		class UInputAction* SlotTwoInputAction; 	/* TODO JÄRKEVÄMPI SLOT SYSTEM*/

	UPROPERTY(EditDefaultsOnly)
		class UInputAction* SlotThreeInputAction; 	/* TODO JÄRKEVÄMPI SLOT SYSTEM*/

	/* Input Action Callbacks */
	void OnMoveRightInputAction(const struct FInputActionValue& val);

	void OnJumpInputActionStarted(const struct FInputActionValue& val);
	void OnJumpInputActionEnded(const struct FInputActionValue& val);

	void OnInteractInputAction(const struct FInputActionValue& val);

	void OnPrimaryInputAction(const struct FInputActionValue& val);
	void OnSecondaryInputAction(const struct FInputActionValue& val);
	 
	void OnSlotOneInputAction(const struct FInputActionValue& val);  /* TODO JÄRKEVÄMPI SLOT SYSTEM*/
	void OnSlotTwoInputAction(const struct FInputActionValue& val); /* TODO JÄRKEVÄMPI SLOT SYSTEM*/
	void OnSlotThreeInputAction(const struct FInputActionValue& val); /* TODO JÄRKEVÄMPI SLOT SYSTEM*/

	void OnSprintInputActionStarted(const struct FInputActionValue& val);

	void OnMapMenuOpenInputAction(const struct FInputActionValue& val);

	void OnOpenInventoryAction(const struct FInputActionValue& val);

private:

	/* PlayerCharacter Reference set OnPossess*/
	APlayerCharacterBase* PlayerCharacter;

	class UMainHUDWidget* MainHUDWidget;

	class UMapMenuWidget* MapMenuWidget;

};
