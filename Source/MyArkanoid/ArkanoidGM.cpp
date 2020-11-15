// Fill out your copyright notice in the Description page of Project Settings.


#include "ArkanoidGM.h"


AArkanoidGM::AArkanoidGM()
{
}

void AArkanoidGM::BeginPlay()
{

	Super::BeginPlay();

	SpawnBall();

}

void AArkanoidGM::SpawnBall()
{

	Ball = GetWorld()->SpawnActor<ABall>(BallClass, BallSpawnLocation, BallSpawnRotation, BallSpawnParams);

}
