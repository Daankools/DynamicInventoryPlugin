#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "FItemInstance.h"
#include "Engine/DataTable.h"
#include "Misc/Guid.h"
#include "UItemRegistrySubsystem.generated.h"


UCLASS()
class DYNAMICINVENTORY_API UItemRegistrySubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

    UFUNCTION(BlueprintCallable, Category = "Item Registry System")
    FItemInstance CreateItem(FDataTableRowHandle ItemRow, int32 Amount);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Item Registry System")
    FItemInstance GetItem(const FGuid& Guid);
    
    UFUNCTION(BlueprintCallable, Category = "Item Registry System")
    void RemoveItem(const FGuid& Guid, int32 Amount);
    
    UFUNCTION(BlueprintCallable, Category = "Item Registry System")
    void DestroyItem(const FGuid& Guid);

    UFUNCTION(BlueprintCallable, Category = "Item Registry System")
    bool SetItemState(const FGuid& ItemGuid, int32 StateIndex, const FInstancedStruct& NewState);

private:
    UPROPERTY()
    TMap<FGuid, FItemInstance> Items;
};