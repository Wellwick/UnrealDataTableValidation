// ----------------------------------------------------------------------------
// Copyright (c) Wellwick
// Licensed under the MIT license.  
// See LICENSE.TXT in the project root for license information.
// ----------------------------------------------------------------------------


#include "DataTableValidator.h"

#include "Engine/DataTable.h"

bool UDataTableValidator::CanValidateAsset_Implementation(UObject* InAsset) const
{
    // Check if this is a data table asset
    const UDataTable* DataTable = Cast<UDataTable>(InAsset);
    return DataTable != nullptr;
}

EDataValidationResult UDataTableValidator::ValidateLoadedAsset_Implementation(UObject* InAsset, TArray<FText>& ValidationErrors)
{
    const UDataTable* DataTable = Cast<UDataTable>(InAsset);
    if (DataTable == nullptr)
    {
        // This should never occur, because the CanValidateAsset method already checks
        // if this is a DataTable asset
        AssetFails(InAsset, INVTEXT("Asset is not data table"), ValidationErrors);
        return EDataValidationResult::Invalid;
    }

    EDataValidationResult Result = EDataValidationResult::Valid;
    static const FString ContextString(TEXT("UDataTableValidator::ValidateLoadedAsset_Implementation"));

    // We want to check each data table no matter what type of row they contain
    TArray<FTableRowBase*> TableRows;
    DataTable->GetAllRows<FTableRowBase>(ContextString, TableRows);

    // Warn in the case of an empty table
    if (TableRows.IsEmpty())
    {
        AssetWarning(InAsset, INVTEXT("Table is empty. Consider removing the asset if it has no usage."));
    }

    for (int32 Index = 0; Index < TableRows.Num(); ++Index)
    {
        const FTableRowBase* Row = TableRows[Index];
        if (Row == nullptr)
        {
            AssetFails(InAsset, FText::Format(INVTEXT("Row at {0} index does not exist!"), Index), ValidationErrors);
            Result = CombineDataValidationResults(Result, EDataValidationResult::Invalid);
            continue;
        }
    }

    return Result;
}
