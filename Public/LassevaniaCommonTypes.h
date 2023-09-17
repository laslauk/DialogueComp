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

UENUM(BlueprintType)
enum class EDialogSpeakerSide : uint8
{
	Left UMETA(DisplayName = "Left"),
	Right UMETA(DisplayName = "Right"),
};