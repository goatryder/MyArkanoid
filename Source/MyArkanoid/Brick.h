// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Brick.generated.h"

UCLASS()
class MYARKANOID_API ABrick : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABrick();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UStaticMeshComponent* SM_Brick;

	UFUNCTION()
		void OnBrickHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			FVector NormalImpulse, const FHitResult& Hit);

	void DestroyBrick();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
