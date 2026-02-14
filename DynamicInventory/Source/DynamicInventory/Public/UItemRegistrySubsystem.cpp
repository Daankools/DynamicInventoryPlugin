#include "UItemRegistrySubsystem.h"
#include "FItemDefinition.h"

void UItemRegistrySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
		Super::Initialize(Collection);
}

void UItemRegistrySubsystem::Deinitialize()
{
}

FItemInstance UItemRegistrySubsystem::CreateItem(FDataTableRowHandle ItemRow, int32 Amount)
{
	FItemInstance NewItem;

	if (!ItemRow.DataTable || ItemRow.RowName.IsNone())
	{
		return NewItem;
	}

	FItemDefinition* Row = ItemRow.DataTable->FindRow<FItemDefinition>(ItemRow.RowName, TEXT("CreateItem"));
	if (!Row)
	{
		return NewItem;
	}

	NewItem.ItemGuid = FGuid::NewGuid();
	NewItem.ItemID = ItemRow.RowName;
	
	//If for whatever reason someone makes more items than allowed, clamp it.
	NewItem.StackSize = FMath::Clamp(Amount, 0, Row->MaxStackSize);

	//Copy over item state structs
	for (const FInstancedStruct& TemplateState : Row->ItemStates)
	{
		FInstancedStruct InstStruct;

		if (TemplateState.IsValid())
		{
			InstStruct = TemplateState;
			NewItem.ItemStates.Add(InstStruct);
		}
	}

	Items.Add(NewItem.ItemGuid, NewItem);
	return NewItem;
}

FItemInstance UItemRegistrySubsystem::GetItem(const FGuid& Guid)
{
	if (FItemInstance* FoundItem = Items.Find(Guid))
	{
		return *FoundItem;
	}

	return FItemInstance();
}

void UItemRegistrySubsystem::RemoveItem(const FGuid& Guid, int32 Amount)
{
	FItemInstance FoundItem;
	FoundItem = GetItem(Guid);

	if (FoundItem.StackSize - Amount <= 0)
	{
		DestroyItem(Guid);
	}

	else
	{
		FoundItem.StackSize -= Amount;
	}
}

void UItemRegistrySubsystem::DestroyItem(const FGuid& Guid)
{
	Items.FindAndRemoveChecked(Guid);
}

bool UItemRegistrySubsystem::SetItemState(const FGuid& ItemGuid, int32 StateIndex, const FInstancedStruct& NewState)
{
	FItemInstance* Item = Items.Find(ItemGuid);
	if (!Item)
	{
		return false;
	}

	if (!Item->ItemStates.IsValidIndex(StateIndex))
	{
		return false;
	}

	if (Item->ItemStates[StateIndex].GetScriptStruct() != NewState.GetScriptStruct())
	{
		UE_LOG(LogTemp, Warning, TEXT("SetItemState failed: struct type mismatch"));
		return false;
	}

	Item->ItemStates[StateIndex] = NewState;

	return true;
}
