// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/BoxComponent.h"
#include "MyCharacter.generated.h"


UCLASS()
class GAMEJAM_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool IT;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool Tired;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



	/**
 * Called via input to turn at a given rate.
 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handles moving forward/backward */
	void MoveForward(float Val);

	/** Handles stafing movement, left and right */
	void MoveRight(float Val);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Buttonfunc)
	void OnFire();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
