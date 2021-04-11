// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DialogueFixer.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL_CPP_COMBAT_API UDialogueFixer : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	public:
		UFUNCTION(BlueprintCallable, Category = Dialogue)
		static FString FixDialogue(FString dialogue);		
};
