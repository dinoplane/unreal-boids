// Fill out your copyright notice in the Description page of Project Settings.


#include "SeparationBehavior.h"

FVector USeparationBehavior::CalculateForce(){
    force = FVector(0,0,0);

    TArray<ABoidBase*> boids = GetAllBoidsInRange(desiredSeparation);

    FVector diff = FVector(0, 0, 0);
    for (ABoidBase* b: boids){
        diff = GetBoidLocation() - b->GetActorLocation();
        double d = diff.Length();
        diff.Normalize();
        diff /= d;
        force += diff;
    }

    if (boids.Num() > 0){
        force /= boids.Num();
    }

    if (force.Length() > 0){
        force.Normalize();
        force *= GetBoid()->maxSpeed;
        force -= GetBoid()->velocity;
    }

    return USteeringBehaviorBase::CalculateForce();
//   let desiredseparation = WINGSPAN;
//   let steer = createVector(0, 0);
//   let count = 0;
//   // For every boid in the system, check if it's too close
//   for (let i = 0; i < boids.length; i++) {
//     let d = p5.Vector.dist(this.position,boids[i].position);
//     // If the distance is greater than 0 and less than an arbitrary amount (0 when you are yourself)
//     if ((d > 0) && (d < desiredseparation)) {
//       // Calculate vector pointing away from neighbor
//       let diff = p5.Vector.sub(this.position, boids[i].position);
//       diff.normalize();
//       diff.div(d);        // Weight by distance
//       steer.add(diff);
//       count++;            // Keep track of how many
//     }
//   }
//   // Average -- divide by how many
//   if (count > 0) {
//     steer.div(count);
//   }

//   // As long as the vector is greater than 0
//   if (steer.mag() > 0) {
//     // Implement Reynolds: Steering = Desired - Velocity
//     steer.normalize();
//     steer.mult(this.maxspeed);
//     steer.sub(this.velocity);
//     steer.limit(this.maxforce);
//   }
//   return steer;
}