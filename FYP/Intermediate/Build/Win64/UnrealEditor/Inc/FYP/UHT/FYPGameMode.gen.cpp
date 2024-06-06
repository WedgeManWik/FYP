// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FYP/FYPGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFYPGameMode() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	FYP_API UClass* Z_Construct_UClass_AFYPGameMode();
	FYP_API UClass* Z_Construct_UClass_AFYPGameMode_NoRegister();
	UPackage* Z_Construct_UPackage__Script_FYP();
// End Cross Module References
	void AFYPGameMode::StaticRegisterNativesAFYPGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFYPGameMode);
	UClass* Z_Construct_UClass_AFYPGameMode_NoRegister()
	{
		return AFYPGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AFYPGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFYPGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_FYP,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "FYPGameMode.h" },
		{ "ModuleRelativePath", "FYPGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFYPGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFYPGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AFYPGameMode_Statics::ClassParams = {
		&AFYPGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AFYPGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFYPGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFYPGameMode()
	{
		if (!Z_Registration_Info_UClass_AFYPGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFYPGameMode.OuterSingleton, Z_Construct_UClass_AFYPGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AFYPGameMode.OuterSingleton;
	}
	template<> FYP_API UClass* StaticClass<AFYPGameMode>()
	{
		return AFYPGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFYPGameMode);
	AFYPGameMode::~AFYPGameMode() {}
	struct Z_CompiledInDeferFile_FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_FYPGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_FYPGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AFYPGameMode, AFYPGameMode::StaticClass, TEXT("AFYPGameMode"), &Z_Registration_Info_UClass_AFYPGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFYPGameMode), 118259024U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_FYPGameMode_h_3283610933(TEXT("/Script/FYP"),
		Z_CompiledInDeferFile_FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_FYPGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_FYPGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
