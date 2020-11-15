// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Padle_Controller.generated.h"


UCLASS()
class MYARKANOID_API APadle_Controller : public APlayerController
{
	GENERATED_BODY()

	APadle_Controller();

	UFUNCTION()
		virtual void SetupInputComponent() override;
	
	virtual void BeginPlay() override;

	void MoveHorizontal(float Val);

	void Launch();

protected:
	class APadle* OwnedPadle;
	class ABall* Ball;
	class AArkanoidGM* GameMode;
	
	float PadleBoundLeft;
	float PadleBoundRight;
	float PadleSpeed;

};
