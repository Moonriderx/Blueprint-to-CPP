// Fill out your copyright notice in the Description page of Project Settings.


#include "ConeTranslateActorC.h"

// Sets default values
AConeTranslateActorC::AConeTranslateActorC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	ConeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));

	Scene->SetupAttachment(GetRootComponent());
	ConeMesh->SetupAttachment(Scene);

	Speed = 50;
	Max = 200;

}

void AConeTranslateActorC::TestFunc(int32 Val)
{
	UE_LOG(LogTemp, Warning, TEXT("Test Func Called with Value %d"), Val);
}

int32 AConeTranslateActorC::TestPureFunc() const
{
	return 25;
}

void AConeTranslateActorC::Explode_Implementation()
{
	this->Destroy();
}

// Called when the game starts or when spawned
void AConeTranslateActorC::BeginPlay()
{
	Super::BeginPlay();

	TestImplementableFunction(75);

	isUp = true;
	const FVector Location = GetActorLocation(); // const mean cannot be changable
	CurrentZ = Location.Z;
	MinHeight = Location.Z;
	MaxHeight = Max + Location.Z;
}

// Called every frame
void AConeTranslateActorC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const float Val = DeltaTime * Speed;

	if (isUp) {

		CurrentZ = CurrentZ + Val;
	}
	else
	{
		CurrentZ = CurrentZ - Val;
	}

	FVector Location = GetActorLocation();
	Location.Z = CurrentZ;

	SetActorLocation(Location);

	if (CurrentZ > MaxHeight) {
		isUp = false;
		Explode();
	}
	else if (CurrentZ < MinHeight) {
		isUp = true;
	}

}

