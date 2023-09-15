// Fill out your copyright notice in the Description page of Project Settings.
#include "BoidBase.h"
#include "DrawDebugHelpers.h"
#include "Math/UnrealMathUtility.h"
#include "SteeringBehaviorBase.h"

TArray<ABoidBase*> ABoidBase::boids;
// Sets default values
ABoidBase::ABoidBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SetRootComponent(SceneComponent);

	// velocity = FMath::VRand();
	acceleration = FVector(0, 0, 0);


}

// ABoidBase::~ABoidBase()
// {
// 	// boids.Remove(this); 
// 	Super::~AActor();
// }


// Called when the game starts or when spawned
void ABoidBase::BeginPlay()
{
	Super::BeginPlay();
	boids.Add(this);

	for (ABoidBase* boi : boids){
		UE_LOG(LogTemp, Warning, TEXT("The name of the oi is %s"), *boi->GetName());
	}
}

void ABoidBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	boids.Remove(this);
	Super::EndPlay(EndPlayReason);
}

// Called every frame
void ABoidBase::Tick(float DeltaTime)
{



	DrawDebugDirectionalArrow(GetWorld(), 
								K2_GetActorLocation(),
								K2_GetActorLocation() + velocity.GetSafeNormal() * 100.0, 
								1000.0,
								FColor(255, 0, 0, 255));

	
	// UE_LOG(LogTemp, Warning, TEXT("The vector value is: %s"), *(SceneComponent->GetForwardVector() + FVector(0.0, 0.0, 100.0)).ToString());
	
	
	// UE_LOG(LogTemp, Warning, TEXT("The vector value is: %s"), *K2_GetActorLocation().ToString());
	Super::Tick(DeltaTime);

}



FVector ABoidBase::GetForceVector(){
	TArray<USteeringBehaviorBase*> behaviors;
	GetComponents(behaviors, false);

	// TArray<FVector> forces;
	// forces.Init(0, behaviors.Num());

	FVector ret = FVector(0, 0, 0);
	for (int32 i = 0; i < behaviors.Num(); i++){
		USteeringBehaviorBase* b = behaviors[i];

		// UE_LOG(LogTemp, Warning, TEXT("The name of the behavior is %s"), *b->GetReadableName());
		ret += b->CalculateForce();
	}

	return ret;
}