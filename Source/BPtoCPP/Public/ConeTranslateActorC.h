// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ConeTranslateActorC.generated.h"

UCLASS()
class BPTOCPP_API AConeTranslateActorC : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AConeTranslateActorC(); 
	UFUNCTION(BlueprintCallable, Category = "Cone Functions")
		void TestFunc(int32 Val);

	UFUNCTION(BlueprintCallable, Category = "Cone Functions")
		int32 TestPureFunc() const;

	UFUNCTION(BlueprintImplementableEvent, Category = "Cone Functions") // for this we don't need to implement this into the cpp. The header will handle and compile this
		void TestImplementableFunction(int32 Val);

	UFUNCTION(BlueprintNativeEvent, Category = "Cone Functions")
		void Explode();
	    void Explode_Implementation();

protected:
	// Called when the game starts or when spawned
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UStaticMeshComponent* ConeMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ConeActor")
		bool isUp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ConeActor")
		float MinHeight;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ConeActor")
		float MaxHeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConeActor")
		float Max;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ConeActor")
		float CurrentZ;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConeActor")
		float Speed;



	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
