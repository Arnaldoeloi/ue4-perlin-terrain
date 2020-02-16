// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "MyActor.generated.h"

UCLASS()
class MESHGENERATOR_API AMyActor : public AActor
{
	GENERATED_BODY()


private:
	UPROPERTY(VisibleAnywhere)
		UProceduralMeshComponent* mesh;

	UPROPERTY(EditAnywhere, Category="Generation")
		int plane_size;

	UPROPERTY(EditAnywhere, Category = "Generation")
		float z_multiplier;


public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void CreateTriangle();
	void PostActorCreated();
	void PostLoad();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
