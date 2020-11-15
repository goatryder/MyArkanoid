// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "ArkanoidGM.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Tags.Add("Ball");

	SM_Ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM_Ball"));

	RootComponent = SM_Ball;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> FoundMesh(TEXT("/Game/Meshes/SM_Ball.SM_Ball"));
	if (FoundMesh.Succeeded())
		SM_Ball->SetStaticMesh(FoundMesh.Object);
		SM_Ball->SetWorldScale3D(FVector(0.5f));

	static ConstructorHelpers::FObjectFinder<UMaterial> FoundMaterial(TEXT("/Game/Materials/M_Ball.M_Ball"));
	if (FoundMaterial.Succeeded())
		SM_Ball->SetMaterial(0, FoundMaterial.Object);

}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	
	// setup default values from game mode ref
	GameMode = (AArkanoidGM*)GetWorld()->GetAuthGameMode(); // (AArkanoidGM*) is Same as Cast<AArkanoidGM>()

	if (GameMode)
		Speed = GameMode->BallSpeed;

}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bLaunched) {

		AddActorWorldOffset(FVector(0.f, 0.f, Speed * DeltaTime));
	}
}

