// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


class AActor;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DEVOIR_LAMPES_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
		float fltAngle;

	UPROPERTY(EditAnywhere)
	ATriggerVolume *PressurePlate;
	
	AActor *m_Actor;

	UPROPERTY(EditAnywhere)
		float fltDelay;

	float fltLastDoorOpen;


public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void openDoor();

	void closeDoor();

	float getOverlappingMass();
	
};
