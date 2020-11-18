// Fill out your copyright notice in the Description page of Project Settings.


#include "Brick.h"

// Sets default values
ABrick::ABrick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Tags.Add("Brick");

	SM_Brick = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM_Brick"));

	RootComponent = SM_Brick;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> FoundMesh(TEXT("/Game/Meshes/SM_Brick.SM_Brick"));
	if (FoundMesh.Succeeded())
		SM_Brick->SetStaticMesh(FoundMesh.Object);

	static ConstructorHelpers::FObjectFinder<UMaterial> FoundMaterial(TEXT("/Game/Materials/M_Brick.M_Brick"));
	if (FoundMaterial.Succeeded())
		SM_Brick->SetMaterial(0, FoundMaterial.Object);

	SM_Brick->SetCollisionProfileName(TEXT("BlockAllDynamic"));

}

// Called when the game starts or when spawned
void ABrick::BeginPlay()
{
	Super::BeginPlay();
	SM_Brick->OnComponentHit.AddDynamic(this, &ABrick::OnBrickHit);
}

void ABrick::DestroyBrick()
{

	Destroy();

}

void ABrick::OnBrickHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	
	FTimerHandle UnusedHandle;

	GetWorldTimerManager().SetTimer(UnusedHandle, this, &ABrick::DestroyBrick, 0.1f, false);

}

// Called every frame
void ABrick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

