// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BoidBase.h"
#include "SteeringBehaviorBase.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BOIDSWORLD_API USteeringBehaviorBase : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USteeringBehaviorBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double weight = 1.0;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FVector force;


	UFUNCTION(BlueprintCallable, Category="Boid Functions")
	ABoidBase* GetBoid(){ return GetOwner<ABoidBase>(); }

	UFUNCTION(BlueprintCallable, Category="Boid Functions")
	FVector GetBoidLocation(){ return GetOwner<ABoidBase>()->GetActorLocation(); }

	UFUNCTION(BlueprintCallable, Category="Boid Functions")
	TArray<ABoidBase*> GetAllBoids(){ return GetOwner<ABoidBase>()->GetAllBoids(); }

    // static bool BoidInRange(const ABoidBase* BoidA, const ABoidBase* BoidB, double range){
	// 	return ABoidBase::BoidInRange( range);
	// }

	UFUNCTION(BlueprintCallable, Category="Boid Functions")
	TArray<ABoidBase*> GetAllBoidsInRange(double Range){ 
		return GetAllBoids().FilterByPredicate(
			[&](ABoidBase* OtherBoid){ return ABoidBase::BoidInRange(GetBoid(), OtherBoid, Range); }); 
	}
	


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	
	UFUNCTION(BlueprintCallable, Category="Boid Functions")
	virtual FVector CalculateForce();
	

	UFUNCTION(BlueprintCallable, Category="Boid Functions")
	FVector Seek(FVector Target);
};
