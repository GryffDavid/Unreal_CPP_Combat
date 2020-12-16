// Fill out your copyright notice in the Description page of Project Settings.


#include "SithTrooper_Enemy.h"

ASithTrooper_Enemy::ASithTrooper_Enemy()
{
	OnTestDelegate.AddDynamic(this, &ASithTrooper_Enemy::TestFunction);
}

void ASithTrooper_Enemy::TestFunction()
{
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	//MyAttackWidget->SetVisibility(false);
	//MyAttackWidget->SetWidgetClass(TSubclassOf<UAttackWidget>);

	if (IsTargeted == true)
		UE_LOG(LogTemp, Warning, TEXT("Hello"));
}