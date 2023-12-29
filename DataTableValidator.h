// ----------------------------------------------------------------------------
// Copyright (c) Wellwick
// Licensed under the MIT license.  
// See LICENSE.TXT in the project root for license information.
// ----------------------------------------------------------------------------

#pragma once

#include "CoreMinimal.h"
#include "EditorValidatorBase.h"
#include "DataTableValidator.generated.h"

/**
 * Editor Validator which runs validation on data tables.
 * 
 * Will warn for some generically odd cases, but mostly depends
 * on custom implementation of IsRowDataValid for newly created
 * Table Row types.
 */
UCLASS()
class DATATABLEVALIDATION_API UDataTableValidator : public UEditorValidatorBase
{
	GENERATED_BODY()

	virtual bool CanValidateAsset_Implementation(UObject* InAsset) const override;

	virtual EDataValidationResult ValidateLoadedAsset_Implementation(UObject* InAsset, TArray<FText>& ValidationErrors) override;
	
};
