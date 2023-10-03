// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RP_Plataform.generated.h"

class UStaticMeshComponent;

UCLASS()
class ARKDE_ROOMPUZZLE_API ARP_Plataform : public AActor
{
	GENERATED_BODY()

protected:

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USceneComponent* CustomRootComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly ,Category = "Components")
	UStaticMeshComponent* PlataformMeshComponent;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Plataform")
	bool bIsGoingUp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Plataform")
	float Speed;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Plataform")
	float MinHeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Plataform")
	float MaxHeight;
	
public:	
	// Sets default values for this actor's properties
	ARP_Plataform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void Move();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
