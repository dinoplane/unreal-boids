// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SteeringBehaviorBase.h"
#include "SeparationBehavior.generated.h"

/**
 * 
 */
UCLASS( ClassGroup="Boid Behaviors", meta=(BlueprintSpawnableComponent) )
class BOIDSWORLD_API USeparationBehavior : public USteeringBehaviorBase
{
	public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float desiredSeparation = 100;


	GENERATED_BODY()
	virtual FVector CalculateForce() override;
};
