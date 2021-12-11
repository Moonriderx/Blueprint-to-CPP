// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingCube.h"

// Sets default values
ARotatingCube::ARotatingCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARotatingCube::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARotatingCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RotateActor(DeltaTime);

}

void ARotatingCube::RotateActor(float DTime)
{
	FRotator Rotator;
	Rotator = GetActorRotation();

	Rotator.Yaw = RotSpeed * DTime + Rotator.Yaw;

	SetActorRotation(Rotator);

}

