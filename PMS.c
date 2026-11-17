/*
Project 2 — Projectile Motion Simulator
*/

#include <stdio.h>
#include <math.h>
#include "PhysicsFile.h"



void projectileMenu();

double calcHorizontalVelocity(double velocity, double angle);
double calcVerticalVelocity(double velocity, double angle);

double calcMaxHeight(double velocity, double angle);
double calcRange(double velocity, double angle);
double calcFlightTime(double velocity, double angle);

void displayResults(double iVx, double iA, double Vx, double Vy, double H, double R, double T);


int main(){
    projectileMenu();
    return 0;
}


void projectileMenu(){
    ProjectileData link;
    double Vx, Vy, H, R, T;
    printf("Projectile Motion Simulator\n");
    printf("1. Calculator\n");
    printf("2. Exit\n");
    printf("Enter: ");
    scanf("%d", &link.choice);

    switch (link.choice)
    {
    case 1:
        printf("Enter initial velocity (m/s): ");
        scanf("%lf", &link.initialVelocity);
        printf("Enter launch angle (degrees):");
        scanf("%lf", &link.angle);

        double iVx, iA;
        iVx = link.initialVelocity;
        iA = link.angle;

        Vx = calcHorizontalVelocity(link.initialVelocity, link.angle);
        Vy = calcVerticalVelocity(link.initialVelocity, link.angle);
        H = calcMaxHeight(link.initialVelocity, link.angle);
        R = calcRange(link.initialVelocity, link.angle);
        T = calcFlightTime(link.initialVelocity, link.angle);

        displayResults(iVx, iA, Vx, Vy, H, R, T);
        break;
    case 2:
        printf("Exiting......");
        break;
    default:
        break;
    }
}

double calcHorizontalVelocity(double velocity, double angle){ 
    ProjectileData link;
    link.horizontalVelocity = velocity * cos(angle);
    return link.horizontalVelocity;
}
double calcVerticalVelocity(double velocity, double angle){
    ProjectileData link;
    link.verticalVelocity = velocity * sin(angle);
    return link.verticalVelocity;
}

double calcMaxHeight(double velocity, double angle){
    ProjectileData link;
    double Vy = calcVerticalVelocity(velocity, angle);
    link.maxHeight = (pow(Vy, 2)) / (2 * 9.8);
    return link.maxHeight;
}
double calcRange(double velocity, double angle){
    ProjectileData link;
    link.range = (pow(velocity, 2) * sin(2 * angle)) / 9.8;
    return link.range;
}
double calcFlightTime(double velocity, double angle){
    ProjectileData link;
    double Vy = calcVerticalVelocity(velocity, angle);
    link.flightTime = (2 * Vy) / 9.8;
    return link.flightTime;
}

void displayResults(double iVx, double iA, double Vx, double Vy, double H, double R, double T){

    printf("\n===== PROJECTILE MOTION REPORT =====\n");
    printf("\nInitial Velocity : %.2lf m/s\n", iVx);
    printf("Launch Angle     : %.2f Degrees\n", iA);
    printf("\nHorizontal Velocity : %.2lf m/s\n", Vx);
    printf("Vertical Velocity   : %.2lf m/s\n", Vy);
    printf("\nMaximum Height      : %.2lf m/s\n", H);
    printf("Range               :%.2lf m/s\n", R);
    printf("Flight Time         :%.2lf  s\n", T);

}
