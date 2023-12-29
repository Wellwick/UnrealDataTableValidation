# UnrealDataTableValidation
Implements data validation for Data Table assets

## Data Table overview

Data tables are useful to drive your behaviour via tables, and Unreal supports
importing via CSV files for iteration. This can improve your workflow if you
expect many values changes to be required over the course of your project. See
[Unreal's documentation](https://docs.unrealengine.com/latest/en-US/data-driven-gameplay-elements-in-unreal-engine/)
for more information.

Each table has a specified row type that it must use for all rows, with
[overridable behaviour] for Post import and Data changes. By default, there
is no way to perform validation on a data table row except for hooking into
the OnDataTableChanged behaviour, and even this will miss cases of dependent
Property values being modified. For instance, your row data could direct from a
Gameplay Tag to a blueprint actor, but deleting the blueprint actor would not
be flagged as an issue by the data table.

## Implementing Data Validation

All [UObject](https://docs.unrealengine.com/latest/en-US/API/Runtime/CoreUObject/UObject/UObject/IsDataValid/)s
implement an IsDataValid method. This is used when you perform 
[checks on your assets](https://docs.unrealengine.com/latest/en-US/ProgrammingAndScripting/ProgrammingWithCPP/Assets/DataValidation/)
which can quickly find issues when making modifications to the project. This
could be as simple as making sure a TObjectPtr for a material is non-null, or
as complex as checking compatibility of values with many other systems.

Data tables are themselves UObjects, but they do not implement any overriding
behaviour for validation by default (as of UE5.3). Since rows will be C++ defined
for a projects use anyway, the approach in this module, is to implement validation
on the row structures themselves, and have this be called via an EditorValidator.

