// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "Components/StaticMeshComponent.h"
#include "ArkanoidGM.h"

#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Tags.Add("Ball");

	SM_Ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM_Ball"));
	RootComponent = SM_Ball;

	// try to setup default mesh and material
	static ConstructorHelpers::FObjectFinder<UStaticMesh> FoundMesh(TEXT("/Game/Meshes/SM_Ball.SM_Ball"));
	if (FoundMesh.Succeeded()) {

		SM_Ball->SetStaticMesh(FoundMesh.Object);
		SM_Ball->SetWorldScale3D(FVector(0.5f));

	}

	static ConstructorHelpers::FObjectFinder<UMaterial> FoundMaterial(TEXT("/Game/Materials/M_Ball.M_Ball"));
	if (FoundMaterial.Succeeded())
		SM_Ball->SetMaterial(0, FoundMaterial.Object);
	
	// use overlap event as hit event
	SM_Ball->SetGenerateOverlapEvents(true);
	SM_Ball->SetCollisionProfileName(TEXT("BlockAllDynamic"));
	SM_Ball->OnComponentHit.AddDynamic(this, &ABall::OnHit);

}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();

	// setup default values from game mode ref
	GameMode = (AArkanoidGM*)GetWorld()->GetAuthGameMode(); // (AArkanoidGM*) is Same as Cast<AArkanoidGM>()

	if (GameMode)
		Speed = GameMode->BallSpeed;
		Velocity = GameMode->BallVelocity;
		Velocity.Normalize();

}


// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bLaunched) {

		AddActorWorldOffset(Velocity * (Speed * DeltaTime), true, &SweepResult);

		//UE_LOG(LogTemp, Warning, TEXT("Tick Impact Point %s"), *SweepResult.ImpactPoint.ToString());
		//UE_LOG(LogTemp, Warning, TEXT("Tick Impact Normal %s"), *SweepResult.ImpactNormal.ToString());
		//UE_LOG(LogTemp, Warning, TEXT("Tick Hit Location %s"), *SweepResult.Location.ToString());
		//UE_LOG(LogTemp, Warning, TEXT("Tick Hit Normal %s"), *SweepResult.Normal.ToString());

	}
}

void ABall::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, 
	FVector NormalImpulse, const FHitResult& Hit)
{

	//UE_LOG(LogTemp, Warning, TEXT("On Ball Hit Impact Point %s"), *Hit.ImpactPoint.ToString());
	//UE_LOG(LogTemp, Warning, TEXT("On Ball Hit Impact Normal %s"), *Hit.ImpactNormal.ToString());
	//UE_LOG(LogTemp, Warning, TEXT("On Ball Hit Location %s"), *Hit.Location.ToString());
	//UE_LOG(LogTemp, Warning, TEXT("On Ball Hit Normal %s"), *Hit.Normal.ToString());

	// UKismetSystemLibrary::DrawDebugSphere(GetWorld(), Hit.ImpactPoint, 12.f, 12, FLinearColor::Green, 1000.f, 1.f);
	//UKismetSystemLibrary::DrawDebugCircle(GetWorld(), Hit.ImpactPoint, 12.f, 12, FLinearColor::Green, 1000.f, 1.f, FVector(1.f, 0.f, 0.f), FVector(0.f, 0.f, 1.f));
	UKismetSystemLibrary::DrawDebugPoint(GetWorld(), FVector(Hit.ImpactPoint.X, 0.f, Hit.ImpactPoint.Z), 12.f, FLinearColor::Green, 1000.f);

}
