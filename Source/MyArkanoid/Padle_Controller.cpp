// Fill out your copyright notice in the Description page of Project Settings.


#include "Padle_Controller.h"

#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"

#include "Padle.h"
#include "Ball.h"
#include "ArkanoidGM.h"

APadle_Controller::APadle_Controller()
{

	// PrimaryActorTick.bCanEverTick = true;

}

void APadle_Controller::SetupInputComponent()
{

	APlayerController::SetupInputComponent();

	EnableInput(this);

	InputComponent->BindAxis("MoveHorizontal", this, &APadle_Controller::MoveHorizontal);
	InputComponent->BindAction("Launch", IE_Pressed, this, &APadle_Controller::Launch);
}

void APadle_Controller::BeginPlay()
{

	APlayerController::BeginPlay();

	// setup first map camera as current camera
	TArray<AActor*> CameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);
	SetViewTarget(CameraActors[0], FViewTargetTransitionParams());

	// setup owned paddle
	OwnedPadle = Cast<APadle>(GetPawn());

	// setup default values from game mode ref
	GameMode = (AArkanoidGM*)GetWorld()->GetAuthGameMode(); // (AArkanoidGM*) is Same as Cast<AArkanoidGM>()

	if (GameMode)
		PadleSpeed = GameMode->PadleSpeed;
		PadleBoundLeft = GameMode->PadleBoundLeft;
		PadleBoundRight = GameMode->PadleBoundRight;
		Ball = GameMode->Ball;
}

void APadle_Controller::MoveHorizontal(float Val)
{
	
	if (!OwnedPadle)
		return;

	FVector Location = OwnedPadle->GetActorLocation();
	
	Location.X += Val * PadleSpeed * GetWorld()->GetDeltaSeconds();

	// Constrain Movement On Horizontal Axis 
	if (Location.X < PadleBoundLeft) {
		Location.X = PadleBoundLeft;
	}
	else if (Location.X > PadleBoundRight) {
		Location.X = PadleBoundRight;
	}

	OwnedPadle->SetActorLocation(Location, true);

}

void APadle_Controller::Launch()
{

	if (Ball)
		Ball->bLaunched = true;

}
