// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FYP/MyNavLinkComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyNavLinkComponent() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_ENavLinkDirection();
	FYP_API UClass* Z_Construct_UClass_UMyNavLinkComponent();
	FYP_API UClass* Z_Construct_UClass_UMyNavLinkComponent_NoRegister();
	NAVIGATIONSYSTEM_API UClass* Z_Construct_UClass_UNavLinkComponent();
	UPackage* Z_Construct_UPackage__Script_FYP();
// End Cross Module References
	DEFINE_FUNCTION(UMyNavLinkComponent::execSetupLink)
	{
		P_GET_STRUCT(FVector,Z_Param_Left);
		P_GET_STRUCT(FVector,Z_Param_Right);
		P_GET_PROPERTY(FByteProperty,Z_Param_Direction);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetupLink(Z_Param_Left,Z_Param_Right,ENavLinkDirection::Type(Z_Param_Direction));
		P_NATIVE_END;
	}
	void UMyNavLinkComponent::StaticRegisterNativesUMyNavLinkComponent()
	{
		UClass* Class = UMyNavLinkComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SetupLink", &UMyNavLinkComponent::execSetupLink },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UMyNavLinkComponent_SetupLink_Statics
	{
		struct MyNavLinkComponent_eventSetupLink_Parms
		{
			FVector Left;
			FVector Right;
			TEnumAsByte<ENavLinkDirection::Type> Direction;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Left;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Right;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Direction;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMyNavLinkComponent_SetupLink_Statics::NewProp_Left = { "Left", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(MyNavLinkComponent_eventSetupLink_Parms, Left), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMyNavLinkComponent_SetupLink_Statics::NewProp_Right = { "Right", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(MyNavLinkComponent_eventSetupLink_Parms, Right), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UMyNavLinkComponent_SetupLink_Statics::NewProp_Direction = { "Direction", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(MyNavLinkComponent_eventSetupLink_Parms, Direction), Z_Construct_UEnum_Engine_ENavLinkDirection, METADATA_PARAMS(nullptr, 0) }; // 942439066
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyNavLinkComponent_SetupLink_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyNavLinkComponent_SetupLink_Statics::NewProp_Left,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyNavLinkComponent_SetupLink_Statics::NewProp_Right,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyNavLinkComponent_SetupLink_Statics::NewProp_Direction,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyNavLinkComponent_SetupLink_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyNavLinkComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyNavLinkComponent_SetupLink_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyNavLinkComponent, nullptr, "SetupLink", nullptr, nullptr, sizeof(Z_Construct_UFunction_UMyNavLinkComponent_SetupLink_Statics::MyNavLinkComponent_eventSetupLink_Parms), Z_Construct_UFunction_UMyNavLinkComponent_SetupLink_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyNavLinkComponent_SetupLink_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMyNavLinkComponent_SetupLink_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyNavLinkComponent_SetupLink_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMyNavLinkComponent_SetupLink()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyNavLinkComponent_SetupLink_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMyNavLinkComponent);
	UClass* Z_Construct_UClass_UMyNavLinkComponent_NoRegister()
	{
		return UMyNavLinkComponent::StaticClass();
	}
	struct Z_Construct_UClass_UMyNavLinkComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMyNavLinkComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UNavLinkComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_FYP,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UMyNavLinkComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UMyNavLinkComponent_SetupLink, "SetupLink" }, // 3392148265
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyNavLinkComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "HideCategories", "Activation Mobility VirtualTexture Trigger" },
		{ "IncludePath", "MyNavLinkComponent.h" },
		{ "ModuleRelativePath", "MyNavLinkComponent.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMyNavLinkComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyNavLinkComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMyNavLinkComponent_Statics::ClassParams = {
		&UMyNavLinkComponent::StaticClass,
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
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UMyNavLinkComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMyNavLinkComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMyNavLinkComponent()
	{
		if (!Z_Registration_Info_UClass_UMyNavLinkComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMyNavLinkComponent.OuterSingleton, Z_Construct_UClass_UMyNavLinkComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UMyNavLinkComponent.OuterSingleton;
	}
	template<> FYP_API UClass* StaticClass<UMyNavLinkComponent>()
	{
		return UMyNavLinkComponent::StaticClass();
	}
	UMyNavLinkComponent::UMyNavLinkComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMyNavLinkComponent);
	UMyNavLinkComponent::~UMyNavLinkComponent() {}
	struct Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_MyNavLinkComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_MyNavLinkComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UMyNavLinkComponent, UMyNavLinkComponent::StaticClass, TEXT("UMyNavLinkComponent"), &Z_Registration_Info_UClass_UMyNavLinkComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMyNavLinkComponent), 2338574701U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_MyNavLinkComponent_h_1198027311(TEXT("/Script/FYP"),
		Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_MyNavLinkComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_MyNavLinkComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
