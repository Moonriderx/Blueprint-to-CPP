// Fill out your copyright notice in the Description page of Project Settings.


#include "Exercise1.h"
#include <ConeTranslateActorC.cpp>

// Sets default values
AExercise1::AExercise1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AExercise1::SetupConeActor()
{
}

void AExercise1::SetupConeActorLocation()
{
	if (ConeActor != nullptr)
	{
		// local variables that are used multiple times
		const FVector ActorLocation = GetActorLocation();
		const FVector ConeActorLocation = ConeActor->GetActorLocation();
		const float WidthHeight = Width * Height;


		// Vector1
		const float Val = WidthHeight + ConeActor->Speed;
		const float AbsVal = FMath::Abs(Val);
		const FVector Vec1 = ActorLocation * AbsVal;

		// Vector2
		const int32 RoundVal = FMath::RoundToInt(WidthHeight);
		const int32 FloorVal = FMath::FloorToInt(ConeActorLocation.X);
		const int32 RoundFloorVal = RoundVal + ((FloorVal + 1) % FloorVal);
		const FVector Vec2 = ActorLocation * RoundFloorVal;

		// Vector3
		FVector Vec3;
		Vec3.X = WidthHeight * ConeActor->Speed;
		Vec3.Y = WidthHeight / ConeActor->Speed;
		Vec3.Z = FMath::Clamp(ActorLocation.Z, 10.0f, 20.0f);

		// Vector4
		FRotator Delta = ConeActor->GetActorRotation() - GetActorRotation();
		Delta.Normalize();

		const FVector ForwardVec = Delta.Vector();
		const FVector RightVec = FRotationMatrix(Delta).GetScaledAxis(EAxis::Y);
		const FVector Vec4 = UKismetMathLibrary::VLerp(RightVec, ForwardVec, 0.1f); // lerp vector

		// Set ActorLocation
		const FVector Location = Vec1 + Vec2 + Vec3 + Vec4;

		ConeActor->SetActorLocation(Location);

	}
}

// Called when the game starts or when spawned
void AExercise1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AExercise1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

