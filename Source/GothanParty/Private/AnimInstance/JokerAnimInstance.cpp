// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance/JokerAnimInstance.h"

#include "Character/JokerCharacterBase.h"
#include "GameFramework/CharacterMovementComponent.h"

void UJokerAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	CurrentPlayerPawn = Cast<AJokerCharacterBase>(TryGetPawnOwner());
	if (CurrentPlayerPawn)
	{
		FVector Velocity = CurrentPlayerPawn->GetVelocity();
		FRotator ActorRotation = CurrentPlayerPawn->GetActorRotation();	//得到当前ActorRotation
		FRotator ControlRotation = CurrentPlayerPawn->GetControlRotation();	//得到当前Pawn的ControlRotation

		Speed = Velocity.Size();
		Direction = CalculateDirection(Velocity, CurrentPlayerPawn->GetActorRotation());	//计算速度向量和旋转量之间的夹角
		
		FRotator DeltaRotation = ControlRotation - ActorRotation;
		Yaw = FRotator::NormalizeAxis(DeltaRotation.Yaw);
		Pitch = FRotator::NormalizeAxis(DeltaRotation.Pitch) * 2.0f;

		//检测跳跃
		IsJump = CurrentPlayerPawn->GetCharacterMovement()->IsFalling();

		//检测下蹲
		IsCrouch = CurrentPlayerPawn->GetMovementComponent()->IsCrouching();
		
	}
}
