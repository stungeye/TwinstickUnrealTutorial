// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS(Blueprintable)
class TWINSTICKSHOOTER_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	// Make a health prop
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Base Character")
		float Health = 100;

	// Make an life property
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Base Character")
		bool isDead = false;

	// Calculate death function
	virtual void CalculateDead();

	// Calculate health function
	UFUNCTION(BlueprintCallable, Category = "Base Character")
		virtual void CalculateHealth(float Delta);

#if WITH_EDITOR
	// Editor centric code for changing properties
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
