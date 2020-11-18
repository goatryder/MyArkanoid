// Fill out your copyright notice in the Description page of Project Settings.


#include "Padle.h"

// Sets default values
APadle::APadle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Tags.Add("Padle");

	SM_Padle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM_Padle"));

	RootComponent = SM_Padle;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> FoundMesh(TEXT("/Game/Meshes/SM_Paddle.SM_Paddle"));
	if (FoundMesh.Succeeded())
		SM_Padle->SetStaticMesh(FoundMesh.Object);

	static ConstructorHelpers::FObjectFinder<UMaterial> FoundMaterial(TEXT("/Game/Materials/M_Paddle.M_Paddle"));
	if (FoundMaterial.Succeeded())
		SM_Padle->SetMaterial(0, FoundMaterial.Object);

	SM_Padle->SetCollisionProfileName(TEXT("BlockAllDynamic"));

}

// Called when the game starts or when spawned
void APadle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APadle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APadle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

