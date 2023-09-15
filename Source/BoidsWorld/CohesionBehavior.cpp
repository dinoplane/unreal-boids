// Fill out your copyright notice in the Description page of Project Settings.


#include "CohesionBehavior.h"

FVector UCohesionBehavior::CalculateForce(){
    force = FVector(0,0,0);

    TArray<ABoidBase*> boids = GetAllBoidsInRange(neighborDist);

    for (ABoidBase* b: boids){
        force += b->GetActorLocation();
    }

    if (boids.Num() > 0){
        force /= boids.Num();
        force = USteeringBehaviorBase::Seek(force);
    }

    return USteeringBehaviorBase::CalculateForce();
//   let neighbordist = 50;
//   let sum = createVector(0, 0);   // Start with empty vector to accumulate all locations
//   let count = 0;
//   for (let i = 0; i < boids.length; i++) {
//     let d = p5.Vector.dist(this.position,boids[i].position);
//     if ((d > 0) && (d < neighbordist)) {
//       sum.add(boids[i].position); // Add location
//       count++;
//     }
//   }
//   if (count > 0) {
//     sum.div(count);
//     return this.seek(sum);  // Steer towards the location
//   } else {
//     return createVector(0, 0);
//   }
}