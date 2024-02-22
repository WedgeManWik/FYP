// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FYP/FYPPlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFYPPlayerController() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
	FYP_API UClass* Z_Construct_UClass_AFYPPlayerController();
	FYP_API UClass* Z_Construct_UClass_AFYPPlayerController_NoRegister();
	NIAGARA_API UClass* Z_Construct_UClass_UNiagaraSystem_NoRegister();
	UPackage* Z_Construct_UPackage__Script_FYP();
// End Cross Module References
	DEFINE_FUNCTION(AFYPPlayerController::execFinishedMakingPaths)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->FinishedMakingPaths();
		P_NATIVE_END;
	}
	struct FYPPlayerController_eventCameraZoom_Parms
	{
		float ZoomAmount;
	};
	struct FYPPlayerController_eventFollowCustomJumpPath_Parms
	{
		FVector Start;
		FVector Destination;
	};
	static FName NAME_AFYPPlayerController_CameraZoom = FName(TEXT("CameraZoom"));
	void AFYPPlayerController::CameraZoom(float ZoomAmount)
	{
		FYPPlayerController_eventCameraZoom_Parms Parms;
		Parms.ZoomAmount=ZoomAmount;
		ProcessEvent(FindFunctionChecked(NAME_AFYPPlayerController_CameraZoom),&Parms);
	}
	static FName NAME_AFYPPlayerController_FollowCustomJumpPath = FName(TEXT("FollowCustomJumpPath"));
	void AFYPPlayerController::FollowCustomJumpPath(FVector Start, FVector Destination)
	{
		FYPPlayerController_eventFollowCustomJumpPath_Parms Parms;
		Parms.Start=Start;
		Parms.Destination=Destination;
		ProcessEvent(FindFunctionChecked(NAME_AFYPPlayerController_FollowCustomJumpPath),&Parms);
	}
	void AFYPPlayerController::StaticRegisterNativesAFYPPlayerController()
	{
		UClass* Class = AFYPPlayerController::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "FinishedMakingPaths", &AFYPPlayerController::execFinishedMakingPaths },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AFYPPlayerController_CameraZoom_Statics
	{
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ZoomAmount;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AFYPPlayerController_CameraZoom_Statics::NewProp_ZoomAmount = { "ZoomAmount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FYPPlayerController_eventCameraZoom_Parms, ZoomAmount), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFYPPlayerController_CameraZoom_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFYPPlayerController_CameraZoom_Statics::NewProp_ZoomAmount,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFYPPlayerController_CameraZoom_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "FYPPlayerController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFYPPlayerController_CameraZoom_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFYPPlayerController, nullptr, "CameraZoom", nullptr, nullptr, sizeof(FYPPlayerController_eventCameraZoom_Parms), Z_Construct_UFunction_AFYPPlayerController_CameraZoom_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFYPPlayerController_CameraZoom_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AFYPPlayerController_CameraZoom_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AFYPPlayerController_CameraZoom_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AFYPPlayerController_CameraZoom()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFYPPlayerController_CameraZoom_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AFYPPlayerController_FinishedMakingPaths_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFYPPlayerController_FinishedMakingPaths_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "FYPPlayerController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFYPPlayerController_FinishedMakingPaths_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFYPPlayerController, nullptr, "FinishedMakingPaths", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AFYPPlayerController_FinishedMakingPaths_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AFYPPlayerController_FinishedMakingPaths_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AFYPPlayerController_FinishedMakingPaths()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFYPPlayerController_FinishedMakingPaths_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AFYPPlayerController_FollowCustomJumpPath_Statics
	{
		static const UECodeGen_Private::FStructPropertyParams NewProp_Start;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Destination;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AFYPPlayerController_FollowCustomJumpPath_Statics::NewProp_Start = { "Start", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FYPPlayerController_eventFollowCustomJumpPath_Parms, Start), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AFYPPlayerController_FollowCustomJumpPath_Statics::NewProp_Destination = { "Destination", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FYPPlayerController_eventFollowCustomJumpPath_Parms, Destination), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFYPPlayerController_FollowCustomJumpPath_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFYPPlayerController_FollowCustomJumpPath_Statics::NewProp_Start,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFYPPlayerController_FollowCustomJumpPath_Statics::NewProp_Destination,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFYPPlayerController_FollowCustomJumpPath_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "FYPPlayerController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFYPPlayerController_FollowCustomJumpPath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFYPPlayerController, nullptr, "FollowCustomJumpPath", nullptr, nullptr, sizeof(FYPPlayerController_eventFollowCustomJumpPath_Parms), Z_Construct_UFunction_AFYPPlayerController_FollowCustomJumpPath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFYPPlayerController_FollowCustomJumpPath_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08820800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AFYPPlayerController_FollowCustomJumpPath_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AFYPPlayerController_FollowCustomJumpPath_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AFYPPlayerController_FollowCustomJumpPath()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFYPPlayerController_FollowCustomJumpPath_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFYPPlayerController);
	UClass* Z_Construct_UClass_AFYPPlayerController_NoRegister()
	{
		return AFYPPlayerController::StaticClass();
	}
	struct Z_Construct_UClass_AFYPPlayerController_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ShortPressThreshold_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ShortPressThreshold;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FXCursor_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FXCursor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultMappingContext_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultMappingContext;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SetDestinationClickAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SetDestinationClickAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SetDestinationTouchAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SetDestinationTouchAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MouseZoom_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MouseZoom;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFYPPlayerController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_FYP,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AFYPPlayerController_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AFYPPlayerController_CameraZoom, "CameraZoom" }, // 1709395297
		{ &Z_Construct_UFunction_AFYPPlayerController_FinishedMakingPaths, "FinishedMakingPaths" }, // 4133963304
		{ &Z_Construct_UFunction_AFYPPlayerController_FollowCustomJumpPath, "FollowCustomJumpPath" }, // 1772856756
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPPlayerController_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "FYPPlayerController.h" },
		{ "ModuleRelativePath", "FYPPlayerController.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPPlayerController_Statics::NewProp_ShortPressThreshold_MetaData[] = {
		{ "Category", "Input" },
		{ "Comment", "/** Time Threshold to know if it was a short press */" },
		{ "ModuleRelativePath", "FYPPlayerController.h" },
		{ "ToolTip", "Time Threshold to know if it was a short press" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFYPPlayerController_Statics::NewProp_ShortPressThreshold = { "ShortPressThreshold", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AFYPPlayerController, ShortPressThreshold), METADATA_PARAMS(Z_Construct_UClass_AFYPPlayerController_Statics::NewProp_ShortPressThreshold_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFYPPlayerController_Statics::NewProp_ShortPressThreshold_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPPlayerController_Statics::NewProp_FXCursor_MetaData[] = {
		{ "Category", "Input" },
		{ "Comment", "/** FX Class that we will spawn when clicking */" },
		{ "ModuleRelativePath", "FYPPlayerController.h" },
		{ "ToolTip", "FX Class that we will spawn when clicking" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFYPPlayerController_Statics::NewProp_FXCursor = { "FXCursor", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AFYPPlayerController, FXCursor), Z_Construct_UClass_UNiagaraSystem_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFYPPlayerController_Statics::NewProp_FXCursor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFYPPlayerController_Statics::NewProp_FXCursor_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPPlayerController_Statics::NewProp_DefaultMappingContext_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "Comment", "/** MappingContext */" },
		{ "ModuleRelativePath", "FYPPlayerController.h" },
		{ "ToolTip", "MappingContext" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFYPPlayerController_Statics::NewProp_DefaultMappingContext = { "DefaultMappingContext", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AFYPPlayerController, DefaultMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFYPPlayerController_Statics::NewProp_DefaultMappingContext_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFYPPlayerController_Statics::NewProp_DefaultMappingContext_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPPlayerController_Statics::NewProp_SetDestinationClickAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "Comment", "/** Jump Input Action */" },
		{ "ModuleRelativePath", "FYPPlayerController.h" },
		{ "ToolTip", "Jump Input Action" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFYPPlayerController_Statics::NewProp_SetDestinationClickAction = { "SetDestinationClickAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AFYPPlayerController, SetDestinationClickAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFYPPlayerController_Statics::NewProp_SetDestinationClickAction_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFYPPlayerController_Statics::NewProp_SetDestinationClickAction_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPPlayerController_Statics::NewProp_SetDestinationTouchAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "Comment", "/** Jump Input Action */" },
		{ "ModuleRelativePath", "FYPPlayerController.h" },
		{ "ToolTip", "Jump Input Action" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFYPPlayerController_Statics::NewProp_SetDestinationTouchAction = { "SetDestinationTouchAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AFYPPlayerController, SetDestinationTouchAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFYPPlayerController_Statics::NewProp_SetDestinationTouchAction_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFYPPlayerController_Statics::NewProp_SetDestinationTouchAction_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFYPPlayerController_Statics::NewProp_MouseZoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "Comment", "/** Move Zoom Input Action */" },
		{ "ModuleRelativePath", "FYPPlayerController.h" },
		{ "ToolTip", "Move Zoom Input Action" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFYPPlayerController_Statics::NewProp_MouseZoom = { "MouseZoom", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AFYPPlayerController, MouseZoom), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFYPPlayerController_Statics::NewProp_MouseZoom_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFYPPlayerController_Statics::NewProp_MouseZoom_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFYPPlayerController_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPlayerController_Statics::NewProp_ShortPressThreshold,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPlayerController_Statics::NewProp_FXCursor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPlayerController_Statics::NewProp_DefaultMappingContext,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPlayerController_Statics::NewProp_SetDestinationClickAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPlayerController_Statics::NewProp_SetDestinationTouchAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPlayerController_Statics::NewProp_MouseZoom,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFYPPlayerController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFYPPlayerController>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AFYPPlayerController_Statics::ClassParams = {
		&AFYPPlayerController::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AFYPPlayerController_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AFYPPlayerController_Statics::PropPointers),
		0,
		0x008002A4u,
		METADATA_PARAMS(Z_Construct_UClass_AFYPPlayerController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFYPPlayerController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFYPPlayerController()
	{
		if (!Z_Registration_Info_UClass_AFYPPlayerController.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFYPPlayerController.OuterSingleton, Z_Construct_UClass_AFYPPlayerController_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AFYPPlayerController.OuterSingleton;
	}
	template<> FYP_API UClass* StaticClass<AFYPPlayerController>()
	{
		return AFYPPlayerController::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFYPPlayerController);
	AFYPPlayerController::~AFYPPlayerController() {}
	struct Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AFYPPlayerController, AFYPPlayerController::StaticClass, TEXT("AFYPPlayerController"), &Z_Registration_Info_UClass_AFYPPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFYPPlayerController), 729714535U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_373807977(TEXT("/Script/FYP"),
		Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
