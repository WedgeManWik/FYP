// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FYP/MyNavLinkProxy.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyNavLinkProxy() {}
// Cross Module References
	AIMODULE_API UClass* Z_Construct_UClass_ANavLinkProxy();
	FYP_API UClass* Z_Construct_UClass_AMyNavLinkProxy();
	FYP_API UClass* Z_Construct_UClass_AMyNavLinkProxy_NoRegister();
	UPackage* Z_Construct_UPackage__Script_FYP();
// End Cross Module References
	DEFINE_FUNCTION(AMyNavLinkProxy::execUpdateSmartLinkProperties)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateSmartLinkProperties();
		P_NATIVE_END;
	}
	void AMyNavLinkProxy::StaticRegisterNativesAMyNavLinkProxy()
	{
		UClass* Class = AMyNavLinkProxy::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "UpdateSmartLinkProperties", &AMyNavLinkProxy::execUpdateSmartLinkProperties },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMyNavLinkProxy_UpdateSmartLinkProperties_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyNavLinkProxy_UpdateSmartLinkProperties_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyNavLinkProxy.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyNavLinkProxy_UpdateSmartLinkProperties_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyNavLinkProxy, nullptr, "UpdateSmartLinkProperties", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyNavLinkProxy_UpdateSmartLinkProperties_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyNavLinkProxy_UpdateSmartLinkProperties_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyNavLinkProxy_UpdateSmartLinkProperties()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyNavLinkProxy_UpdateSmartLinkProperties_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMyNavLinkProxy);
	UClass* Z_Construct_UClass_AMyNavLinkProxy_NoRegister()
	{
		return AMyNavLinkProxy::StaticClass();
	}
	struct Z_Construct_UClass_AMyNavLinkProxy_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMyNavLinkProxy_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ANavLinkProxy,
		(UObject* (*)())Z_Construct_UPackage__Script_FYP,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AMyNavLinkProxy_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMyNavLinkProxy_UpdateSmartLinkProperties, "UpdateSmartLinkProperties" }, // 1075410316
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyNavLinkProxy_Statics::Class_MetaDataParams[] = {
		{ "AutoCollapseCategories", "SmartLink Actor" },
		{ "HideCategories", "Input" },
		{ "IncludePath", "MyNavLinkProxy.h" },
		{ "ModuleRelativePath", "MyNavLinkProxy.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMyNavLinkProxy_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyNavLinkProxy>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AMyNavLinkProxy_Statics::ClassParams = {
		&AMyNavLinkProxy::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AMyNavLinkProxy_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMyNavLinkProxy_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMyNavLinkProxy()
	{
		if (!Z_Registration_Info_UClass_AMyNavLinkProxy.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMyNavLinkProxy.OuterSingleton, Z_Construct_UClass_AMyNavLinkProxy_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AMyNavLinkProxy.OuterSingleton;
	}
	template<> FYP_API UClass* StaticClass<AMyNavLinkProxy>()
	{
		return AMyNavLinkProxy::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMyNavLinkProxy);
	AMyNavLinkProxy::~AMyNavLinkProxy() {}
	struct Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_MyNavLinkProxy_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_MyNavLinkProxy_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AMyNavLinkProxy, AMyNavLinkProxy::StaticClass, TEXT("AMyNavLinkProxy"), &Z_Registration_Info_UClass_AMyNavLinkProxy, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMyNavLinkProxy), 2147708675U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_MyNavLinkProxy_h_1052670575(TEXT("/Script/FYP"),
		Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_MyNavLinkProxy_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_MyNavLinkProxy_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
