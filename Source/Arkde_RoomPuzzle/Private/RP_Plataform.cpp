// Fill out your copyright notice in the Description page of Project Settings.


#include "RP_Plataform.h"
#include "Components/StaticMeshComponent.h"
#include <Kismet/KismetMathLibrary.h>

// Sets default values
ARP_Plataform::ARP_Plataform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CustomRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("CustomRoot"));
	RootComponent = CustomRootComponent;

	PlataformMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlataformMesh"));
	PlataformMeshComponent->SetupAttachment(CustomRootComponent);

	bIsGoingUp = true;
	Speed = 10.0f;
	MinHeight = 0.0f;
	MaxHeight = 50.0f;
}

// Called when the game starts or when spawned
void ARP_Plataform::BeginPlay()
{
	Super::BeginPlay();
	
}



// Called every frame
void ARP_Plataform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move();

}

void ARP_Plataform::Move()
{
	FVector upDirection = UKismetMathLibrary::GetUpVector(GetActorRotation());

	if (bIsGoingUp)
	{
		upDirection = upDirection;
	}
	else
	{
		upDirection = upDirection * -1;
	}

	FVector CurrentVelocity = upDirection * Speed;
	FVector NewPosition = GetActorLocation() + CurrentVelocity;
	SetActorLocation(NewPosition);

	if ((bIsGoingUp && GetActorLocation().Z >= MaxHeight) || (!bIsGoingUp && GetActorLocation().Z <= MinHeight))
	{
		bIsGoingUp = !bIsGoingUp;
	}
}

