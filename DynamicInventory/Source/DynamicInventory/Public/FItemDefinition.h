#pragma once

#include "StructUtils/InstancedStruct.h"
#include "Engine/Texture2D.h"
#include "ItemBase.h"
#include "ItemWorldBase.h"
#include "ItemPlayerBase.h"
#include "FItemDefinition.generated.h"

USTRUCT(BlueprintType)
struct FItemDefinition : public FTableRowBase
{
    GENERATED_BODY()


    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FText Name;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FText Description;

    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    UTexture2D* Thumbnail = nullptr;

    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TSubclassOf<AItemPlayerBase> PlayerItem = nullptr;

    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TSubclassOf<AItemWorldBase> WorldItem = nullptr;

    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    int32 MaxStackSize = 1;


    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TArray<FInstancedStruct> ItemStates;
};