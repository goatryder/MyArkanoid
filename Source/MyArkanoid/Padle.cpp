// Fill out your copyright notice in the Description page of Project Settings.


#include "Padle.h"

// Sets default values
APadle::APadle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

