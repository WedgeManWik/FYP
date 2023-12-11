// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFYP_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_FYP;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_FYP()
	{
		if (!Z_Registration_Info_UPackage__Script_FYP.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/FYP",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x88E99E63,
				0xD4306C1E,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_FYP.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_FYP.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_FYP(Z_Construct_UPackage__Script_FYP, TEXT("/Script/FYP"), Z_Registration_Info_UPackage__Script_FYP, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x88E99E63, 0xD4306C1E));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
