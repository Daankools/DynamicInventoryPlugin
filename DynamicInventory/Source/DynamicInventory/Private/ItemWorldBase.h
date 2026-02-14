// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ItemBase.h"
#include "CoreMinimal.h"
#include "ItemWorldBase.generated.h"

UCLASS()
class DYNAMICINVENTORY_API AItemWorldBase : public AItemBase
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = "true"))
	bool bDropped;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = "true"))
	FVector DropDirection = FVector::ZeroVector;
};
