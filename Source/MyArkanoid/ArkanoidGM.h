// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"

#include "Ball.h"

#include "ArkanoidGM.generated.h"


UCLASS()
class MYARKANOID_API AArkanoidGM : public AGameMode
{
	GENERATED_BODY()

	AArkanoidGM();

	virtual void BeginPlay() override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float PadleSpeed = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float PadleBoundLeft = -140.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float PadleBoundRight = 140.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector BallSpawnLocation = FVector(10.f, 0.f, 40.f);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FRotator BallSpawnRotation = FRotator(0.f, 0.f, 0.f);
	
	FActorSpawnParameters BallSpawnParams;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABall> BallClass = ABall::StaticClass();

	UPROPERTY(BlueprintReadOnly)
		ABall* Ball;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float BallSpeed = 200.f;

	void SpawnBall();

};
