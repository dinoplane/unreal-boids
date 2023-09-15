// Fill out your copyright notice in the Description page of Project Settings.


#include "AlignmentBehavior.h"


FVector UAlignmentBehavior::CalculateForce(){
    force = FVector(0,0,0);

    TArray<ABoidBase*> boids = GetAllBoidsInRange(neighborDist);

    for (ABoidBase* b: boids){
        force += b->velocity;
    }

    if (boids.Num() > 0){
        force /= boids.Num();
        force.Normalize();
        force *= GetBoid()->maxSpeed;
        force -= GetBoid()->velocity;
    }
    return USteeringBehaviorBase::CalculateForce();

    // UE_LOG(LogTemp, Warning, TEXT("The name of the boid is %s"), *aboid->GetName());

//   let neighbordist = 50;
//   let sum = createVector(0,0);
//   let count = 0;
//   for (let i = 0; i < boids.length; i++) {
//     let d = p5.Vector.dist(this.position,boids[i].position);
//     if ((d > 0) && (d < neighbordist)) {
//       sum.add(boids[i].velocity);
//       count++;
//     }
//   }
//   if (count > 0) {
//     sum.div(count);
//     sum.normalize();
//     sum.mult(this.maxspeed);
//     let steer = p5.Vector.sub(sum, this.velocity);
//     steer.limit(this.maxforce);
//     return steer;
//   } else {
//     return createVector(0, 0);
//   }
}