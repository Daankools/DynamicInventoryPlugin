#pragma once

#include "StructUtils/InstancedStruct.h"
#include "FItemInstance.generated.h"

USTRUCT(BlueprintType)
struct FItemInstance
{
    GENERATED_BODY()

    //item unique identifier
    UPROPERTY(BlueprintReadOnly)
    FGuid ItemGuid;
    
    //use ID to look up information in data tables
    UPROPERTY(BlueprintReadOnly)
    FName ItemID;

    // how many are there in this instance
    UPROPERTY(BlueprintReadOnly)
    int32 StackSize = 1;

    // What is the current state
    UPROPERTY(BlueprintReadOnly)
    TArray<FInstancedStruct> ItemStates;
};