// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"



// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector PlayerVector;
	FRotator PlayerRotator;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(PlayerVector, PlayerRotator);


	UE_LOG(LogTemp, Log, TEXT("Player Vector : %s and Player Rotator : %s"),*PlayerVector.ToString(),*PlayerRotator.ToString() );

	// TO DO : Tracer une ligne pointant les éléments de la scène en utilisant drawDebugLine()
	//Affichage du nom de l'objet HIT
	//LineTraceSingleByObjetType()

	// ...
}

