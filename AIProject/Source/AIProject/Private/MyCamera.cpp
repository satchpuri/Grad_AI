// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCamera.h"
#include "Kismet/GameplayStatics.h"
#include "Engine.h"
#include "EngineUtils.h"
#include "MyCharacter.h"
#include "GameFramework/SpringArmComponent.h"

//USpringArmComponent* OurCameraSpringArm;
//AMyCharacter* MyChar_Spawn;

// Sets default values
AMyCamera::AMyCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	//OurCameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));

}

// Called when the game starts or when spawned
void AMyCamera::BeginPlay()
{
	Super::BeginPlay();

	//APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
	//OurPlayerController->SetViewTarget(CameraOne);
	
	
}

// Called every frame
void AMyCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

//	for (TActorIterator<AMyCharacter> ActorItr(GetWorld()); ActorItr; ++ActorItr)
//	{
//		ActorItr->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
//
//	}

}

