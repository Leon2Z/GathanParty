// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "JokerCharacterBase.generated.h"

UCLASS()
class GOTHANPARTY_API AJokerCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AJokerCharacterBase();

	// 声明一些角色通用的组件

	// 摄像机弹簧臂
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USpringArmComponent * CameraBoomComp;

	// 摄像机
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UCameraComponent * CameraComp;

	// 用于表示Actor位置
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent * ThrowWeaponScene;

	// 角色移动组件
	UCharacterMovementComponent * MovementComp;

public:
	// 小跑速度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerState")
	int32 SprintSpeed;
	// 跑步速度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerState")
	int32 RunSpeed;
	// 行走速度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerState")
	int32 WalkSpeed;
	// 下蹲速度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerState")
	int32 CrouchSpeed;

	// 默认视角
	float DefaultFOV;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void MoveForward(float Value);

	UFUNCTION()
	void MoveRight(float Value);

	UFUNCTION()
    void StartJump();

	UFUNCTION()
	void StopJump();

	UFUNCTION()
	void StartAttack();

	UFUNCTION()
	void StopAttack();
	
	UFUNCTION()
	void SprintPressed();

	UFUNCTION()
	void SprintReleased();

	UFUNCTION()
	void WalkPressed();

	UFUNCTION()
	void WalkReleased();

	UFUNCTION()
	void CrouchPressed();

	UFUNCTION()
	void CrouchReleased();
	
};
