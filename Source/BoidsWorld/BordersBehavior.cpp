// Fill out your copyright notice in the Description page of Project Settings.


#include "BordersBehavior.h"

FVector UBordersBehavior::CalculateForce(){
    force = FVector(0,0,0);
    FVector position = GetOwner()->GetActorLocation();
    force.X = (abs(position.X) > 1000) ? FClangPlatformMath::Sign(position.X) * -1 * 25 : 0;
    force.Y = (abs(position.Y) > 1000) ? FClangPlatformMath::Sign(position.Y) * -1 * 25 : 0;
    force.Z = (abs(position.Z) > 1000) ? FClangPlatformMath::Sign(position.Z) * -1 * 25 : 0;

    return USteeringBehaviorBase::CalculateForce();
}