// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FYP/FYPCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFYPCharacter() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	FYP_API UClass* Z_Construct_UClass_AFYPCharacter();
	FYP_API UClass* Z_Construct_UClass_AFYPCharacter_NoRegister();
	UPackage* Z_Construct_UPackage__Script_FYP();
// End Cross Module References
	DEFINE_FUNCTION(AFYPCharacter::execCharacterCollidedWithNavLink)
	{
		P_GET_STRUCT_REF(FVector,Z_Param_Out_LowerLocation);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_UpperLocation);
		P_GET_UBOOL_REF(Z_Param_Out_IsLower);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->CharacterCollidedWithNavLink(Z_Param_Out_LowerLocation,Z_Param_Out_UpperLocation,Z_Param_Out_IsLower);
		P_NATIVE_END;
	}
	void AFYPCharacter::StaticRegisterNativesAFYPCharacter()
	{
		UClass* Class = AFYPCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CharacterCollidedWithNavLink", &AFYPCharacter::execCharacterCollidedWithNavLink },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AFYPCharacter_CharacterCollidedWithNavLink_Statics
	{
		struct FYPCharacter_eventCharacterCollidedWithNavLink_Parms
		{
			FVector LowerLocation;
			FVector UpperLocation;
			bool IsLower;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_LowerLocation;
		static const UECodeGen_Private::FStructPropertyParams NewProp_UpperLocation;
		static void NewProp_IsLower_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsLower;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AFYPCharacter_CharacterCollidedWithNavLink_Statics::NewProp_LowerLocation = { "LowerLocation", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FYPCharacter_eventCharacterCollidedWithNavLink_Parms, LowerLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AFYPCharacter_CharacterCollidedWithNavLink_Statics::NewProp_UpperLocation = { "UpperLocation", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FYPCharacter_eventCharacterCollidedWithNavLink_Parms, UpperLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_AFYPCharacter_CharacterCollidedWithNavLink_Statics::NewProp_IsLower_SetBit(void* Obj)
	{
		((FYPCharacter_eventCharacterCollidedWithNavLink_Parms*)Obj)->IsLower = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AFYPCharacter_CharacterCollidedWithNavLink_Statics::NewProp_IsLower = { "IsLower", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(FYPCharacter_eventCharacterCollidedWithNavLink_Parms), &Z_Construct_UFunction_AFYPCharacter_CharacterCollidedWithNavLink_Statics::NewProp_IsLower_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_AFYPCharacter_CharacterCollidedWithNavLink_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((FYPCharacter_eventCharacterCollidedWithNavLink_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AFYPCharacter_CharacterCollidedWithNavLink_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(FYPCharacter_eventCharacterCollidedWithNavLink_Parms), &Z_Construct_UFunction_AFYPCharacter_CharacterCollidedWithNavLink_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFYPCharacter_CharacterCollidedWithNavLink_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFYPCharacter_CharacterCollidedWithNavLink_Statics::NewProp_LowerLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFYPCharacter_CharacterCollidedWithNavLink_Statics::NewProp_UpperLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFYPCharacter_CharacterCollidedWithNavLink_Statics::NewProp_IsLower,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFYPCharacter_CharacterCollidedWithNavLink_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFYPCharacter_CharacterCollidedWithNavLink_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "FYPCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFYPCharacter_CharacterCollidedWithNavLink_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFYPCharacter, nullptr, "CharacterCollidedWithNavLink", nullptr, nullptr, sizeof(Z_Construct_UFunction_AFYPCharacter_CharacterCollidedWithNavLink_Statics::FYPCharacter_eventCharacterCollidedWithNavLink_Parms), Z_Construct_UFunction_AFYPCharacter_CharacterCollidedWithNavLink_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFYPCharacter_CharacterCollidedWithNavLink_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AFYPCharacter_CharacterCollidedWithNavLink_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AFYPCharacter_CharacterCollidedWithNavLink_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AFYPCharacter_CharacterCollidedWithNavLink()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFYPCharacter_CharacterCollidedWithNavLink_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFYPCharacter);
	UClass* Z_Construct_UClass_AFYPCharacter_NoRegister()
	{
		return AFYPCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AFYPCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TopDownCameraComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TopDownCameraComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFYPCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_FYP,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AFYPCharacter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AFYPCharacter_CharacterCollidedWithNavLink, "CharacterCollidedWithNavLink" }, // 3058948012
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPCharacter_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "FYPCharacter.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "FYPCharacter.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPCharacter_Statics::NewProp_TopDownCameraComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/** Top down camera */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FYPCharacter.h" },
		{ "ToolTip", "Top down camera" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFYPCharacter_Statics::NewProp_TopDownCameraComponent = { "TopDownCameraComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AFYPCharacter, TopDownCameraComponent), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFYPCharacter_Statics::NewProp_TopDownCameraComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFYPCharacter_Statics::NewProp_TopDownCameraComponent_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPCharacter_Statics::NewProp_CameraBoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/** Camera boom positioning the camera above the character */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FYPCharacter.h" },
		{ "ToolTip", "Camera boom positioning the camera above the character" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFYPCharacter_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AFYPCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFYPCharacter_Statics::NewProp_CameraBoom_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFYPCharacter_Statics::NewProp_CameraBoom_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFYPCharacter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPCharacter_Statics::NewProp_TopDownCameraComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPCharacter_Statics::NewProp_CameraBoom,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFYPCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFYPCharacter>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AFYPCharacter_Statics::ClassParams = {
		&AFYPCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AFYPCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AFYPCharacter_Statics::PropPointers),
		0,
		0x008000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AFYPCharacter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFYPCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFYPCharacter()
	{
		if (!Z_Registration_Info_UClass_AFYPCharacter.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFYPCharacter.OuterSingleton, Z_Construct_UClass_AFYPCharacter_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AFYPCharacter.OuterSingleton;
	}
	template<> FYP_API UClass* StaticClass<AFYPCharacter>()
	{
		return AFYPCharacter::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFYPCharacter);
	AFYPCharacter::~AFYPCharacter() {}
	struct Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_FYPCharacter_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_FYPCharacter_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AFYPCharacter, AFYPCharacter::StaticClass, TEXT("AFYPCharacter"), &Z_Registration_Info_UClass_AFYPCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFYPCharacter), 1638751137U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_FYPCharacter_h_1133494668(TEXT("/Script/FYP"),
		Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_FYPCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_FYPCharacter_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
