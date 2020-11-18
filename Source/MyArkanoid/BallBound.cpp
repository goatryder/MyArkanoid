// Fill out your copyright notice in the Description page of Project Settings.


#include "BallBound.h"

#include "Components/BoxComponent.h"

#include "Ball.h"
#include "ArkanoidGM.h"

// Sets default values
ABallBound::ABallBound()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Box_Collision = CreateDefaultSubobject<UBoxComponent>((TEXT("BoxCollision")));
	Box_Collision->SetCollisionProfileName(FName(TEXT("BlockAllDynamic")));
	Box_Collision->InitBoxExtent(FVector(512.f, 32.f, 8.f));
	Box_Collision->SetGenerateOverlapEvents(true);
	
	RootComponent = Box_Collision;

}

// Called when the game starts or when spawned
void ABallBound::BeginPlay()
{
	Super::BeginPlay();
	Box_Collision->OnComponentHit.AddDynamic(this, &ABallBound::OnBoxHit);

	GameMode = (AArkanoidGM*)GetWorld()->GetAuthGameMode();

}

void ABallBound::OnBoxHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{

	ABall* Ball = Cast<ABall>(OtherActor);

	if (GameMode && Ball) {

		Ball->Destroy();
		GameMode->SpawnBall();

	}

}

// Called every frame
void ABallBound::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

