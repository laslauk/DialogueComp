// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllerBase.h"
#include "PlayerStateBase.h"
#include "AbilitySystemComponent.h"
#include "EnhancedPlayerInput.h"
#include "InputActionValue.h"
#include "AbilitySystem/LVAbilitySystemComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Inventory/InventoryMainMenuWidget.h"
#include "UI/MainHUDWidget.h"
#include "UI/MapMenuWidget.h"
#include "Character/PlayerCharacterBase.h"
#include "Inventory/InventoryComponent.h"
#include "AbilitySystem/LVAbilitySystemComponent.h"

#include "Components/CapsuleComponent.h"
#include "EnhancedInputComponent.h"
#include "CharacterZDBase.h"


void APlayerControllerBase::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);


	/*Set Character's Variable references to PlayerState and COntroller*/
	 PlayerCharacter = Cast<APlayerCharacterBase>(aPawn);

	if (PlayerCharacter)
	{
		APlayerStateBase* PlayerStateRef = GetPlayerState<APlayerStateBase>();

		PlayerCharacter->SetPlayerController(this);
		PlayerCharacter->SetPlayerState(PlayerStateRef);
		PlayerStateRef->GetInventoryComponent()->InitInventoryWidget(InventoryWidgetClass);
	}

	if (MainHUDWIdgetClass)
	{
		MainHUDWidget = CreateWidget<UMainHUDWidget>(this, MainHUDWIdgetClass);
		MainHUDWidget->AddToViewport();

		/* Set audio listener to PlayerCharacter - Cinematic Camera currently so far away that sounds are weird, due to wanted Depth of Field blur ffect*/
		SetAudioListenerOverride
		(
			PlayerCharacter->GetCapsuleComponent(), /* Component to attach */
			PlayerCharacter->GetCapsuleComponent()->GetComponentLocation(), /* location */
			FRotator::ZeroRotator /* rotation */
		);
		
	}

	if (MapMenuWidgetClass)
	{
		MapMenuWidget = CreateWidget<UMapMenuWidget>(this, MapMenuWidgetClass);
		MapMenuWidget->AddToViewport();
		MapMenuWidget->SetVisibility((ESlateVisibility::Collapsed));
	}


	/* DONE IN INVENTORY COMPONENT  - Inventory component is concerned on opening it
	if (InventoryWidgetClass)
	{
		InventoryMenuWidget = CreateWidget<UInventoryMainMenuWidget>(this, InventoryWidgetClass);

		InventoryMenuWidget->AddToViewport();
		InventoryMenuWidget->SetVisibility((ESlateVisibility::Collapsed));
	}

	*/



	/* DEFAULT STARTING STAST + ABILITIES - Importan*/
	/* Note: do this here, if character is placed in world before haviing possessed, AbiliySystem from player staten ot found*/
	PlayerCharacter->ApplyStartupEffects();
	PlayerCharacter->GiveAbilities();


}


UAbilitySystemComponent* APlayerControllerBase::GetAbilitySystemComponent() const
{
	return GetPlayerState<APlayerStateBase>()->GetAbilitySystemComponent();
}


ULVAbilitySystemComponent* APlayerControllerBase::GetLVAbilitySystemComponent() const
{
	return GetPlayerState<APlayerStateBase>()->GetLVAbilitySystemComponent();
}

UInventoryComponent* APlayerControllerBase::GetInventoryComponent()
{
	return GetPlayerState<APlayerStateBase>()->GetInventoryComponent();
}

APlayerCharacterBase* APlayerControllerBase::GetPlayerCharacter()
{
	return PlayerCharacter;
}



void APlayerControllerBase::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	if (Subsystem)
	{
		Subsystem->ClearAllMappings();
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}

	UEnhancedInputComponent* EI = Cast<UEnhancedInputComponent>(InputComponent);

	if (EI)
	{
		if (PrimaryInputAction)
		{
			EI->BindAction(PrimaryInputAction, ETriggerEvent::Started, this, &APlayerControllerBase::OnPrimaryInputAction);
		}
		if (JumpInputAction)
		{
			EI->BindAction(JumpInputAction, ETriggerEvent::Started, this, &APlayerControllerBase::OnJumpInputActionStarted);
			EI->BindAction(JumpInputAction, ETriggerEvent::Completed, this, &APlayerControllerBase::OnJumpInputActionEnded);
		}

		if (MoveRightInputAction)
		{
			EI->BindAction(MoveRightInputAction, ETriggerEvent::Triggered, this, &APlayerControllerBase::OnMoveRightInputAction);
		}

		if (InteractInputAction)
		{
			EI->BindAction(InteractInputAction, ETriggerEvent::Started, this, &APlayerControllerBase::OnInteractInputAction);
		}

		if (OpenInventoryAction)
		{
			EI->BindAction(OpenInventoryAction, ETriggerEvent::Started, this, &APlayerControllerBase::OnOpenInventoryAction);
		}

		if (OpenMapMenuInputAction)
		{
			EI->BindAction(OpenMapMenuInputAction, ETriggerEvent::Started, this, &APlayerControllerBase::OnMapMenuOpenInputAction);
		}
	}

}

void APlayerControllerBase::Input_AbilityInputTagPressed(FGameplayTag InputTag)
{
	if (PlayerCharacter)
	{

		ULVAbilitySystemComponent* AbilitySystemComp = GetLVAbilitySystemComponent();
		if (AbilitySystemComp)
		{

			UE_LOG(LogTemp, Warning, TEXT("Input_AbilityInputTagPressed -->"));
			AbilitySystemComp->AbilityInputTagPressed(InputTag);
		}
	}
}

void APlayerControllerBase::OnPrimaryInputAction(const  FInputActionValue& val)
{
	Input_AbilityInputTagPressed(InputTagDEBUG);
}




void APlayerControllerBase::OnMapMenuOpenInputAction(const FInputActionValue& val)
{
	if (MapMenuWidget)
	{
		/* Nyt widgetissä palautetaan - TODO joku more robost system 
		sitten kun keksii miten UI ja input (common Ui plugin perhaps)
		*/
		FInputModeUIOnly InputMode;
		SetInputMode(InputMode);
		MapMenuWidget->SetVisibility(ESlateVisibility::Visible);
		MapMenuWidget->SetFocus();
		//InputMode.SetWidgetToFocus(MapMenuWidget->TakeWidget());
		SetShowMouseCursor(true);
	}
}

/* NOTE, NYT WIDGET OTTAA INPUT CONSUMEN NIIN EI KOSKAAN KUTSUTA CLOSE */
void APlayerControllerBase::OnOpenInventoryAction(const FInputActionValue& val)
{
	UInventoryComponent* InventoryComp = GetInventoryComponent();

	if (InventoryComp->bIsMenuWidgetOpen)
	{
		UE_LOG(LogTemp, Warning, TEXT("closing Inventory"));
		InventoryComp->SetShowInventoryMenu(EInventoryMenuVisibility::Hide);
	}

	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Opening Inventory"));
		InventoryComp->SetShowInventoryMenu(EInventoryMenuVisibility::Show);
	}

}

void APlayerControllerBase::OnJumpInputActionStarted(const  FInputActionValue& val)
{


}

void APlayerControllerBase::OnJumpInputActionEnded(const  FInputActionValue& val)
{


}

void APlayerControllerBase::OnMoveRightInputAction(const  FInputActionValue& val)
{

	PlayerCharacter->TryMovement(val.GetMagnitude());

}

void APlayerControllerBase::OnInteractInputAction(const  FInputActionValue& val)
{
	if (PlayerCharacter)
	{
		UE_LOG(LogTemp, Warning, TEXT("INTERACTING"));
		PlayerCharacter->TryInteract();
		//PlayerCharacter->TryI
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerCharacter - null - INTERACTING"));
	}
}

void APlayerControllerBase::PostProcessInput(const float DeltaTime, const bool bGamePaused)
{
	if (ULVAbilitySystemComponent* LVASC = GetLVAbilitySystemComponent())
	{
		LVASC->ProcessAbilityInput(DeltaTime, bGamePaused);
	}

	Super::PostProcessInput(DeltaTime, bGamePaused);
}