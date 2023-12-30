// ----------------------------------------------------------------------------
// Copyright (c) Wellwick
// Licensed under the MIT license.  
// See LICENSE.TXT in the project root for license information.
// ----------------------------------------------------------------------------


#include "DataRowValidation.h"

EDataValidationResult IDataRowValidation::IsOwningTableValid(const UDataTable& DataTable, FDataValidationContext& Context) const
{
    return EDataValidationResult::Valid;
}
