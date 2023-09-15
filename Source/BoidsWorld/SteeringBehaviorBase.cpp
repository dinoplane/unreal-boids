// Fill out your copyright notice in the Description page of Project Settings.


#include "SteeringBehaviorBase.h"
#include "Kismet/KismetMathLibrary.h" 


// Sets default values for this component's properties
USteeringBehaviorBase::USteeringBehaviorBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USteeringBehaviorBase::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USteeringBehaviorBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FVector USteeringBehaviorBase::CalculateForce(){
	force = UKismetMathLibrary::ClampVectorSize(force, 0, GetBoid()->maxForce);

	// UE_LOG(LogTemp, Warning, TEXT("The vector value is: %s"), *K2_GetActorLocation().ToString());
	return force * weight;
}


FVector USteeringBehaviorBase::Seek(FVector Target){
	FVector desired = FVector(0,0,0);
	desired = Target - GetBoidLocation();
	desired.Normalize();
	desired *= GetBoid()->maxSpeed; // Make a better API!!!

	FVector ret = desired - GetBoid()->velocity;
	return ret;
}
// Boid.prototype.seek = function(target) {
//   let desired = p5.Vector.sub(target,this.position);  // A vector pointing from the location to the target
//   // Normalize desired and scale to maximum speed
//   desired.normalize();
//   desired.mult(this.maxspeed);
//   // Steering = Desired minus Velocity
//   let steer = p5.Vector.sub(desired,this.velocity);
//   steer.limit(this.maxforce);  // Limit to maximum steering force
//   return steer;
// }
