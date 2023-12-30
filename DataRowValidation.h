// ----------------------------------------------------------------------------
// Copyright (c) Wellwick
// Licensed under the MIT license.  
// See LICENSE.TXT in the project root for license information.
// ----------------------------------------------------------------------------

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

class UDataTable;

/**
 * Interface to implement data row validation.
 * 
 * FTableRowBase are not UObjects, so we can not use Unreal's interface system or macros.
 * Instead we need to use C++ style interfaces.
 */
class DATATABLEVALIDATION_API IDataRowValidation
{
public:
    /** Check if row is valid. */
    virtual EDataValidationResult IsDataRowValid(FDataValidationContext& Context) const = 0;

    /** Checks across table for validity. Only run once, and can be unimplemented if there is no special logic for the table. */
    virtual EDataValidationResult IsOwningTableValid(const UDataTable& DataTable, FDataValidationContext& Context) const;
};
