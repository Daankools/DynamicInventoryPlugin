// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "ItemPlayerBase.generated.h"

UCLASS()
class DYNAMICINVENTORY_API AItemPlayerBase : public AItemBase
{
	GENERATED_BODY()

public: 	
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Item Base")
	void DropItem();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Item Base")
	void SetEquipItem(bool Equip);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Item Base")
	void StartPrimaryInteraction();
};
