// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"

void AMyAIController::BeginPlay()
{
	Super::BeginPlay();
}
FString AMyAIController::TalkToPlayer()
{
	return TEXT("Hello, Player!, lo sai che tommaso è gay");
}