// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/UnrealMathUtility.h"
#include "DiceRoll.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL_CPP_COMBAT_API UDiceRoll : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Dice)
	static int RollD6(int numDice = 1);

	UFUNCTION(BlueprintCallable, Category = Dice)
	static int RollD8(int numDice = 1);

	UFUNCTION(BlueprintCallable, Category = Dice)
	static int RollD10(int numDice = 1);

	UFUNCTION(BlueprintCallable, Category = Dice)
	static int RollD12(int numDice = 1);

	UFUNCTION(BlueprintCallable, Category = Dice)
	static int RollD20(int numDice = 1);

	/**
	* Roll a D20 vs a difficulty class. If the roll succeeds, return true
	* @param	difficultyClass		The number the roll needs to beat
	* @param	diceModifier	The number to add to the dice roll (Positive or Negative)
	* @param	numDice		The number of D20s to roll
	* @return	Returns true if the roll succeeded
	*/
	UFUNCTION(BlueprintCallable, Category = Dice)
	static bool RollD20vDC(int difficultyClass, int diceModifier, int numDice = 1);
};
