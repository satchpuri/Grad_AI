// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCharacter.h"
#include"MyCamera.h"
#include "EngineUtils.h"



//For making character align with camera position

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Create an Isometric camera component.
	IsoCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	
	// Attach the camera component to our capsule component.

	IsoCameraComponent->SetupAttachment(RootComponent);

	

	

	
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	//IsoCameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 0.f), false, 0, ETeleportType::None);
	//FRotator NewRotation = FRotator(0.f, 0.f, 0.f);
	//IsoCameraComponent->AddLocalRotation(NewRotation, false, 0, ETeleportType::None);


	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);

}

void AMyCharacter::MoveForward(float amount)
{
	if (Controller	&&	amount)
	{
		AddMovementInput(GetActorForwardVector(), amount);
	}
}

void AMyCharacter::MoveRight(float amount)
{
	if (Controller	&&	amount)
	{
		AddMovementInput(GetActorRightVector(), amount);
	}
}