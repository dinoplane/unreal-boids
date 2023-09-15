// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SteeringBehaviorBase.h"
#include "BordersBehavior.generated.h"

/**
 * 
 */
UCLASS( ClassGroup="Boid Behaviors", meta=(BlueprintSpawnableComponent) )
class BOIDSWORLD_API UBordersBehavior : public USteeringBehaviorBase
{
	GENERATED_BODY()
	
	virtual FVector CalculateForce() override;
};
