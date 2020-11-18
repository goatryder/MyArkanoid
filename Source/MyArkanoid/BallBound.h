// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BallBound.generated.h"


UCLASS()
class MYARKANOID_API ABallBound : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABallBound();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* Box_Collision;

	UFUNCTION()
		void OnBoxHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			FVector NormalImpulse, const FHitResult& Hit);
	
	class AArkanoidGM* GameMode;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
