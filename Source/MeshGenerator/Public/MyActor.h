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

	UPROPERTY(EditAnywhere, Category="Mesh Generation")
		int plane_size;

	UPROPERTY(EditAnywhere, Category = "Mesh Perlin")
		float height_multiplier;

	UPROPERTY(EditAnywhere, Category = "Mesh Perlin")
		float freq_x;

	UPROPERTY(EditAnywhere, Category = "Mesh Perlin")
		float freq_y;

	UPROPERTY(EditAnywhere, Category = "Mesh Perlin")
		float x_offset;

	UPROPERTY(EditAnywhere, Category = "Mesh Perlin")
		float y_offset;



public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;

	void CreateMesh();
	void UpdateMesh();
	void PostActorCreated();
	void PostLoad();

	//vertices matrix (x,y,z)
	TArray<FVector> vertices;

	//order in which vertices should be joined together creating a mesh of triangles
	TArray<int32> Triangles;
	TArray<FLinearColor> vertexColors;
	TArray<FVector> normals;
	TArray<FVector2D> UV0;
	TArray<FProcMeshTangent> tangents;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
