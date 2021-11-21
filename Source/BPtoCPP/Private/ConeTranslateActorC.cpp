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

}

// Called when the game starts or when spawned
void AConeTranslateActorC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AConeTranslateActorC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

