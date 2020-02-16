// Fill out your copyright notice in the Description page of Project Settings.


#include "Math/UnrealMathUtility.h"
#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
	mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh"));
	RootComponent = mesh;
	mesh->bUseAsyncCooking = true;
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	plane_size = 10;
	z_multiplier= 500.0f;
}


// This is called when actor is spawned (at runtime or when you drop it into the world in editor)
void AMyActor::PostActorCreated() {
	Super::PostActorCreated();
	CreateTriangle();
}

void AMyActor::PostLoad() {
	Super::PostLoad();
	CreateTriangle();
}

void AMyActor::CreateTriangle()
{
	//vertices matrix (x,y,z)
	TArray<FVector> vertices;

	//order in which vertices should be joined together creating a mesh of triangles
	TArray<int32> Triangles;
	TArray<FLinearColor> vertexColors;
	for (size_t x = 0; x < plane_size; x++)
	{
		for (size_t y = 0; y < plane_size; y++)
		{
			float perlin_generated = FMath::PerlinNoise2D(FVector2D(0.1f * x, 0.1f *y));
			
			float generated_z = perlin_generated * z_multiplier;
			/*UE_LOG(LogTemp, Warning, TEXT("Generated z = %f"), generated_z * 500.0f);*/
			vertices.Add(FVector(x * 100, y * 100, generated_z));
			//vertices.Add(FVector(x*100, y*100, FMath::RandRange(0.0f, 100.0f)));
			vertexColors.Add(FLinearColor(0, 0, 0, perlin_generated));
		}
	}

	int32 iterations = (plane_size-1) * (plane_size);
	for (int i = 0; i < iterations; i++)
	{
		if ( (i+1) % plane_size !=0) {
			Triangles.Add(i);
			Triangles.Add(i+1);
			Triangles.Add(i+plane_size);

			Triangles.Add(i + 1);
			Triangles.Add(i + plane_size + 1);
			Triangles.Add(i + plane_size);
		}
	}

	/*vertices.Add(FVector(0, 0, 0));
	vertices.Add(FVector(0, 100, 0));
	vertices.Add(FVector(0, 0, 100));*/

	//Triangles.Add(0);
	//Triangles.Add(1);
	//Triangles.Add(2);

	//Triangles.Add(2);
	//Triangles.Add(3);
	//Triangles.Add(0);

	TArray<FVector> normals;
	normals.Add(FVector(1, 0, 0));
	normals.Add(FVector(1, 0, 0));
	normals.Add(FVector(1, 0, 0));

	TArray<FVector2D> UV0;
	UV0.Add(FVector2D(0, 0));
	UV0.Add(FVector2D(10, 0));
	UV0.Add(FVector2D(0, 10));


	TArray<FProcMeshTangent> tangents;
	tangents.Add(FProcMeshTangent(0, 1, 0));
	tangents.Add(FProcMeshTangent(0, 1, 0));
	tangents.Add(FProcMeshTangent(0, 1, 0));


	mesh->CreateMeshSection_LinearColor(0, vertices, Triangles, normals, UV0, vertexColors, tangents, true);

	// Enable collision data
	mesh->ContainsPhysicsTriMeshData(true);
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

