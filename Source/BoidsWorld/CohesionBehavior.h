// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SteeringBehaviorBase.h"
#include "CohesionBehavior.generated.h"

/**
 * 
 */
UCLASS( ClassGroup="Boid Behaviors", meta=(BlueprintSpawnableComponent) )
class BOIDSWORLD_API UCohesionBehavior : public USteeringBehaviorBase
{
	public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double neighborDist = 200;

	GENERATED_BODY()
	virtual FVector CalculateForce() override;
};
