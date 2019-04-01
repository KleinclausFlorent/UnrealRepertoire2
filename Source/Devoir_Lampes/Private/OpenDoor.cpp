// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"



// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	fltAngle = 90.f;
	PressurePlate = nullptr;
	m_Actor = nullptr;
	fltLastDoorOpen = 0.f;
	fltDelay = 1.f;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	/*
	FRotator rotate(0.f, fltAngle, 0.f);
	GetOwner()->SetActorRotation(rotate);
	*/
	m_Actor = GetWorld()->GetFirstPlayerController()->GetPawn();

	// ...
	
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//ASSERTION
	/*
	if (!ensure(PressurePlate) != NULL)
	{ 
		UE_LOG(LogTemp, Warning, TEXT("REF NULL PRESSURE PLATE"));
		return;
	}
	*/

	//UE_LOG(LogTemp, Log, TEXT("Mass : %f"), getOverlappingMass());
	if (getOverlappingMass() > 8.f)
	{
		openDoor();
		fltLastDoorOpen = GetWorld()->GetTimeSeconds();
	}

	if (GetWorld()->GetTimeSeconds() - fltLastDoorOpen > fltDelay) {
		closeDoor();
	}
	/*
	if (PressurePlate->IsOverlappingActor(m_Actor)) {

		openDoor();
		fltLastDoorOpen = GetWorld()->GetTimeSeconds();
	}

	if (GetWorld()->GetTimeSeconds() - fltLastDoorOpen > fltDelay) {
		closeDoor();
	}
	*/
}

float UOpenDoor::getOverlappingMass()
{
	float fltMass = 0.f;

	TArray<AActor*> OverlappingActors;
	
	if (!ensure(PressurePlate)) { return fltMass; }

	PressurePlate->GetOverlappingActors(OverlappingActors);

	for (AActor* Actor : OverlappingActors) {//Parcours TArray jusqu
		fltMass = fltMass + Actor->FindComponentByClass<UStaticMeshComponent>()->GetMass();
	}
	return fltMass;
}
void UOpenDoor::openDoor()
{
	FRotator rotate(0.f, fltAngle, 0.f);
	GetOwner()->SetActorRotation(rotate);
}

void UOpenDoor::closeDoor()
{
	FRotator rotate(0.f, 0.f, 0.f);
	GetOwner()->SetActorRotation(rotate);
}

