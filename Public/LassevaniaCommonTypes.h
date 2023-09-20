// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Texture2D.h"
#include "GameplayTagContainer.h"

#include "Engine/DataTable.h"
#include "LassevaniaCommonTypes.generated.h"
/**
 * 
 */
class AItemActorBase;
class UGameplayAbilityBase;
class UGameplayEffect;
class UPaperSprite;




/* Channelit omaan headeriin TODO*/
#define Lassevania_TraceChannel_Interaction ECC_GameTraceChannel4



USTRUCT(BlueprintType)
struct FCharacterData
{
	GENERATED_USTRUCT_BODY();


/*
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GAS")
	TArray<TSubclassOf<class UGameplayEffect>> EffectsDefault;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GAS")
	TArray<TSubclassOf<class UGameplayAbilityBase>> AbilitiesDefault;
*/
};

USTRUCT(BlueprintType)
struct FDialogSpeakerData: public FTableRowBase
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DialogSystem")
	FName Name;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DialogSystem")
	UTexture2D* Image;
};


USTRUCT(BlueprintType)
struct FDialogContentData : public FTableRowBase
{

	GENERATED_USTRUCT_BODY();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DialogSystem")
	int32 Index;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DialogSystem")
	FText TextContent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DialogSystem")
	FGameplayTag RequiredTagFlag;

};


UCLASS(BlueprintType, Blueprintable)
class UItemStaticData : public UObject
{
	GENERATED_BODY()


public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName Name;

	/* Actor class to spawn in the world */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<class AItemActorBase> ItemActorClass;


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool bCanBeEquipped = true;

	//how to use weapons == weapons grant an USE (such as melee, shoot) ability to use the weapon
	UPROPERTY(EditDefaultsOnly, BLueprintReadOnly)
	TArray<TSubclassOf<UGameplayAbility>> GrantedAbilities; //item grants abilities

	//effects we apply to character when we equip it
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<TSubclassOf<UGameplayEffect>> OngoingEffects;


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FGameplayTag> InventoryTags;

	//1 item instance can have multiple items
	UPROPERTY(EditDefaultsOnly, Blueprintable)
	int32 MaxStackCount = 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UPaperSprite* ActorSprite;

};


UCLASS(BlueprintType, Blueprintable)
class UGearItemStaticData : public UItemStaticData
{
public:
	GENERATED_BODY()


};





UCLASS(BlueprintType, Blueprintable)
class UWeaponStaticData : public UItemStaticData
{
	GENERATED_BODY()

public:

	//effect to apply damage
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		TSubclassOf<UGameplayEffect> DamageEffect;


	UPROPERTY(EditDefaultsOnly, BLueprintReadOnly)
		float FireRate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		float BaseDamage;

	//Attack soundit on played by itemActor
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		USoundBase* AttackSound;

};



UENUM(BlueprintType)
enum class EItemState : uint8
{
	None UMETA(DIsplayName = "None"),
	Equipped UMETA(DisplayName = "Equipped"),
	Dropped UMETA(DisplayName = "Dropped"),
};




USTRUCT(BlueprintType)
struct FInventoryWidgetSlotData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "InventoryItem")
	TSubclassOf<AItemActorBase> ItemClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "InventoryItem")
	int32 Count;
};

UENUM(BlueprintType)
enum class EDialogSpeakerSide : uint8
{
	Left UMETA(DisplayName = "Left"),
	Right UMETA(DisplayName = "Right"),
};