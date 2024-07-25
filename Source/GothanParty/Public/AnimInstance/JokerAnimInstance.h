// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "JokerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class GOTHANPARTY_API UJokerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	void NativeUpdateAnimation(float DeltaSeconds) override;

	// 定义的变量都是在动画图表里进行更新
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Joker")
	bool isTurnLeft;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Joker")
	bool isTurnRight;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Joker")
	bool isPunch;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CharacterBase")
	class AJokerCharacterBase * CurrentPlayerPawn;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Joker")
	float Speed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Joker")
	float Direction;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Joker")
	float Pitch;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Joker")
	float Yaw;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Joker")
	bool IsJump;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Joker")
	bool IsCrouch;
	
};
