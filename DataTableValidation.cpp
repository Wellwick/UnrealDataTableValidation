// ----------------------------------------------------------------------------
// Copyright (c) Wellwick
// Licensed under the MIT license.  
// See LICENSE.TXT in the project root for license information.
// ----------------------------------------------------------------------------

#include "DataTableValidation.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_GAME_MODULE(FDataTableValidation, DataTableValidation);

DEFINE_LOG_CATEGORY(LogDataTableValidation)

void FDataTableValidation::StartupModule()
{
    UE_LOG(LogDataTableValidation, Log, TEXT("DataTableValidation: Log Started"));
}

void FDataTableValidation::ShutdownModule()
{
    UE_LOG(LogDataTableValidation, Log, TEXT("DataTableValidation: Log Ended"));
}
