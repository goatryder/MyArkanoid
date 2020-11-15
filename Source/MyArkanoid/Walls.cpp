// Fill out your copyright notice in the Description page of Project Settings.


#include "Walls.h"

#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AWalls::AWalls()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Tags.Add("Walls");

	SM_Walls = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM_Walls"));
	
	RootComponent = SM_Walls;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> FoundMesh(TEXT("/Game/Meshes/SM_Wall.SM_Wall"));
	if (FoundMesh.Succeeded())
		SM_Walls->SetStaticMesh(FoundMesh.Object);

	static ConstructorHelpers::FObjectFinder<UMaterial> FoundMaterial(TEXT("/Game/Materials/M_Wall.M_Wall"));
	if (FoundMaterial.Succeeded())
		SM_Walls->SetMaterial(0, FoundMaterial.Object);



}

// Called when the game starts or when spawned
void AWalls::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWalls::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

