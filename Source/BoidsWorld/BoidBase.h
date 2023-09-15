// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoidBase.generated.h"

UCLASS()
class BOIDSWORLD_API ABoidBase : public AActor
{
	GENERATED_BODY()
	
public:	

	static TArray<ABoidBase*> boids;
	// Sets default values for this actor's properties
	ABoidBase();
	// ~ABoidBase();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USceneComponent* SceneComponent;

	// UPROPERTY(EditAnywhere, BlueprintReadWrite,  Category = "Boid Behaviors")
	// class UActorComponent* BehaviorList;

    static bool BoidInRange(const ABoidBase* BoidA, const ABoidBase* BoidB, double Range)
	{
		double L = (BoidB->GetActorLocation() - BoidA->GetActorLocation()).Length();
		return  L > 0 && L <= Range;
	}



	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector velocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector acceleration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double maxSpeed = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double maxForce = 0.05;

	UFUNCTION(BlueprintCallable, Category="Boid Functions")
	TArray<ABoidBase*> GetAllBoids() { return boids; };

	UFUNCTION(BlueprintCallable, Category="Boid Functions")
	FVector GetForceVector();




protected:
	// Called when the game starts or when spawned


	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
