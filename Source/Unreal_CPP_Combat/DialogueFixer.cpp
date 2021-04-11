// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueFixer.h"
#include "Containers/UnrealString.h"

FString UDialogueFixer::FixDialogue(FString dialogue)
{
	FString dest = "\n";
	TArray<TCHAR>& chars = dest.GetCharArray();	
	return dialogue.ReplaceCharWithEscapedChar(&chars);
}
