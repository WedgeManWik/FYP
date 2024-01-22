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
	FYP_API UScriptStruct* Z_Construct_UScriptStruct_FCustomPathPoint();
	FYP_API UScriptStruct* Z_Construct_UScriptStruct_FJumpPoint();
	NAVIGATIONSYSTEM_API UClass* Z_Construct_UClass_ARecastNavMesh_NoRegister();
	NIAGARA_API UClass* Z_Construct_UClass_UNiagaraSystem_NoRegister();
	UPackage* Z_Construct_UPackage__Script_FYP();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_JumpPoint;
class UScriptStruct* FJumpPoint::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_JumpPoint.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_JumpPoint.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FJumpPoint, (UObject*)Z_Construct_UPackage__Script_FYP(), TEXT("JumpPoint"));
	}
	return Z_Registration_Info_UScriptStruct_JumpPoint.OuterSingleton;
}
template<> FYP_API UScriptStruct* StaticStruct<FJumpPoint>()
{
	return FJumpPoint::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FJumpPoint_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Left_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Left;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Right_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Right;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FJumpPoint_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "FYPPlayerController.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FJumpPoint_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FJumpPoint>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FJumpPoint_Statics::NewProp_Left_MetaData[] = {
		{ "Category", "JumpPoint" },
		{ "ModuleRelativePath", "FYPPlayerController.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJumpPoint_Statics::NewProp_Left = { "Left", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FJumpPoint, Left), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FJumpPoint_Statics::NewProp_Left_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJumpPoint_Statics::NewProp_Left_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FJumpPoint_Statics::NewProp_Right_MetaData[] = {
		{ "Category", "JumpPoint" },
		{ "ModuleRelativePath", "FYPPlayerController.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FJumpPoint_Statics::NewProp_Right = { "Right", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FJumpPoint, Right), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FJumpPoint_Statics::NewProp_Right_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJumpPoint_Statics::NewProp_Right_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FJumpPoint_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJumpPoint_Statics::NewProp_Left,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FJumpPoint_Statics::NewProp_Right,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FJumpPoint_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_FYP,
		nullptr,
		&NewStructOps,
		"JumpPoint",
		sizeof(FJumpPoint),
		alignof(FJumpPoint),
		Z_Construct_UScriptStruct_FJumpPoint_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJumpPoint_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FJumpPoint_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FJumpPoint_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FJumpPoint()
	{
		if (!Z_Registration_Info_UScriptStruct_JumpPoint.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_JumpPoint.InnerSingleton, Z_Construct_UScriptStruct_FJumpPoint_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_JumpPoint.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_CustomPathPoint;
class UScriptStruct* FCustomPathPoint::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_CustomPathPoint.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_CustomPathPoint.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCustomPathPoint, (UObject*)Z_Construct_UPackage__Script_FYP(), TEXT("CustomPathPoint"));
	}
	return Z_Registration_Info_UScriptStruct_CustomPathPoint.OuterSingleton;
}
template<> FYP_API UScriptStruct* StaticStruct<FCustomPathPoint>()
{
	return FCustomPathPoint::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FCustomPathPoint_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IsJumpPoint_MetaData[];
#endif
		static void NewProp_IsJumpPoint_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsJumpPoint;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCustomPathPoint_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "FYPPlayerController.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FCustomPathPoint_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCustomPathPoint>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCustomPathPoint_Statics::NewProp_Location_MetaData[] = {
		{ "Category", "CustomPathPoint" },
		{ "ModuleRelativePath", "FYPPlayerController.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCustomPathPoint_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FCustomPathPoint, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FCustomPathPoint_Statics::NewProp_Location_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCustomPathPoint_Statics::NewProp_Location_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCustomPathPoint_Statics::NewProp_IsJumpPoint_MetaData[] = {
		{ "Category", "CustomPathPoint" },
		{ "ModuleRelativePath", "FYPPlayerController.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FCustomPathPoint_Statics::NewProp_IsJumpPoint_SetBit(void* Obj)
	{
		((FCustomPathPoint*)Obj)->IsJumpPoint = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FCustomPathPoint_Statics::NewProp_IsJumpPoint = { "IsJumpPoint", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(FCustomPathPoint), &Z_Construct_UScriptStruct_FCustomPathPoint_Statics::NewProp_IsJumpPoint_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FCustomPathPoint_Statics::NewProp_IsJumpPoint_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCustomPathPoint_Statics::NewProp_IsJumpPoint_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCustomPathPoint_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCustomPathPoint_Statics::NewProp_Location,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCustomPathPoint_Statics::NewProp_IsJumpPoint,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCustomPathPoint_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_FYP,
		nullptr,
		&NewStructOps,
		"CustomPathPoint",
		sizeof(FCustomPathPoint),
		alignof(FCustomPathPoint),
		Z_Construct_UScriptStruct_FCustomPathPoint_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCustomPathPoint_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FCustomPathPoint_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCustomPathPoint_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FCustomPathPoint()
	{
		if (!Z_Registration_Info_UScriptStruct_CustomPathPoint.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_CustomPathPoint.InnerSingleton, Z_Construct_UScriptStruct_FCustomPathPoint_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_CustomPathPoint.InnerSingleton;
	}
	DEFINE_FUNCTION(AFYPPlayerController::execGetGoalDestination)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->GetGoalDestination();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AFYPPlayerController::execGoToNextPointOnCustomPath)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GoToNextPointOnCustomPath();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AFYPPlayerController::execFindPath)
	{
		P_GET_OBJECT(ARecastNavMesh,Z_Param_Nav);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->FindPath(Z_Param_Nav);
		P_NATIVE_END;
	}
	struct FYPPlayerController_eventCustomGoingToNextPoint_Parms
	{
		FJumpPoint JumpLink;
	};
	struct FYPPlayerController_eventCustomJump_Parms
	{
		FVector LowerLocation;
		FVector UpperLocation;
	};
	static FName NAME_AFYPPlayerController_CustomGoingToNextPoint = FName(TEXT("CustomGoingToNextPoint"));
	void AFYPPlayerController::CustomGoingToNextPoint(FJumpPoint JumpLink)
	{
		FYPPlayerController_eventCustomGoingToNextPoint_Parms Parms;
		Parms.JumpLink=JumpLink;
		ProcessEvent(FindFunctionChecked(NAME_AFYPPlayerController_CustomGoingToNextPoint),&Parms);
	}
	static FName NAME_AFYPPlayerController_CustomJump = FName(TEXT("CustomJump"));
	void AFYPPlayerController::CustomJump(FVector LowerLocation, FVector UpperLocation)
	{
		FYPPlayerController_eventCustomJump_Parms Parms;
		Parms.LowerLocation=LowerLocation;
		Parms.UpperLocation=UpperLocation;
		ProcessEvent(FindFunctionChecked(NAME_AFYPPlayerController_CustomJump),&Parms);
	}
	static FName NAME_AFYPPlayerController_FindNavData = FName(TEXT("FindNavData"));
	void AFYPPlayerController::FindNavData()
	{
		ProcessEvent(FindFunctionChecked(NAME_AFYPPlayerController_FindNavData),NULL);
	}
	void AFYPPlayerController::StaticRegisterNativesAFYPPlayerController()
	{
		UClass* Class = AFYPPlayerController::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "FindPath", &AFYPPlayerController::execFindPath },
			{ "GetGoalDestination", &AFYPPlayerController::execGetGoalDestination },
			{ "GoToNextPointOnCustomPath", &AFYPPlayerController::execGoToNextPointOnCustomPath },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AFYPPlayerController_CustomGoingToNextPoint_Statics
	{
		static const UECodeGen_Private::FStructPropertyParams NewProp_JumpLink;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AFYPPlayerController_CustomGoingToNextPoint_Statics::NewProp_JumpLink = { "JumpLink", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FYPPlayerController_eventCustomGoingToNextPoint_Parms, JumpLink), Z_Construct_UScriptStruct_FJumpPoint, METADATA_PARAMS(nullptr, 0) }; // 1750899947
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFYPPlayerController_CustomGoingToNextPoint_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFYPPlayerController_CustomGoingToNextPoint_Statics::NewProp_JumpLink,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFYPPlayerController_CustomGoingToNextPoint_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "FYPPlayerController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFYPPlayerController_CustomGoingToNextPoint_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFYPPlayerController, nullptr, "CustomGoingToNextPoint", nullptr, nullptr, sizeof(FYPPlayerController_eventCustomGoingToNextPoint_Parms), Z_Construct_UFunction_AFYPPlayerController_CustomGoingToNextPoint_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFYPPlayerController_CustomGoingToNextPoint_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AFYPPlayerController_CustomGoingToNextPoint_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AFYPPlayerController_CustomGoingToNextPoint_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AFYPPlayerController_CustomGoingToNextPoint()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFYPPlayerController_CustomGoingToNextPoint_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AFYPPlayerController_CustomJump_Statics
	{
		static const UECodeGen_Private::FStructPropertyParams NewProp_LowerLocation;
		static const UECodeGen_Private::FStructPropertyParams NewProp_UpperLocation;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AFYPPlayerController_CustomJump_Statics::NewProp_LowerLocation = { "LowerLocation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FYPPlayerController_eventCustomJump_Parms, LowerLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AFYPPlayerController_CustomJump_Statics::NewProp_UpperLocation = { "UpperLocation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FYPPlayerController_eventCustomJump_Parms, UpperLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFYPPlayerController_CustomJump_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFYPPlayerController_CustomJump_Statics::NewProp_LowerLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFYPPlayerController_CustomJump_Statics::NewProp_UpperLocation,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFYPPlayerController_CustomJump_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "FYPPlayerController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFYPPlayerController_CustomJump_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFYPPlayerController, nullptr, "CustomJump", nullptr, nullptr, sizeof(FYPPlayerController_eventCustomJump_Parms), Z_Construct_UFunction_AFYPPlayerController_CustomJump_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFYPPlayerController_CustomJump_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08820800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AFYPPlayerController_CustomJump_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AFYPPlayerController_CustomJump_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AFYPPlayerController_CustomJump()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFYPPlayerController_CustomJump_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AFYPPlayerController_FindNavData_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFYPPlayerController_FindNavData_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "FYPPlayerController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFYPPlayerController_FindNavData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFYPPlayerController, nullptr, "FindNavData", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AFYPPlayerController_FindNavData_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AFYPPlayerController_FindNavData_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AFYPPlayerController_FindNavData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFYPPlayerController_FindNavData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AFYPPlayerController_FindPath_Statics
	{
		struct FYPPlayerController_eventFindPath_Parms
		{
			ARecastNavMesh* Nav;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Nav;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AFYPPlayerController_FindPath_Statics::NewProp_Nav = { "Nav", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FYPPlayerController_eventFindPath_Parms, Nav), Z_Construct_UClass_ARecastNavMesh_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFYPPlayerController_FindPath_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFYPPlayerController_FindPath_Statics::NewProp_Nav,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFYPPlayerController_FindPath_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "FYPPlayerController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFYPPlayerController_FindPath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFYPPlayerController, nullptr, "FindPath", nullptr, nullptr, sizeof(Z_Construct_UFunction_AFYPPlayerController_FindPath_Statics::FYPPlayerController_eventFindPath_Parms), Z_Construct_UFunction_AFYPPlayerController_FindPath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFYPPlayerController_FindPath_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AFYPPlayerController_FindPath_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AFYPPlayerController_FindPath_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AFYPPlayerController_FindPath()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFYPPlayerController_FindPath_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AFYPPlayerController_GetGoalDestination_Statics
	{
		struct FYPPlayerController_eventGetGoalDestination_Parms
		{
			FVector ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AFYPPlayerController_GetGoalDestination_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FYPPlayerController_eventGetGoalDestination_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFYPPlayerController_GetGoalDestination_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFYPPlayerController_GetGoalDestination_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFYPPlayerController_GetGoalDestination_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "FYPPlayerController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFYPPlayerController_GetGoalDestination_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFYPPlayerController, nullptr, "GetGoalDestination", nullptr, nullptr, sizeof(Z_Construct_UFunction_AFYPPlayerController_GetGoalDestination_Statics::FYPPlayerController_eventGetGoalDestination_Parms), Z_Construct_UFunction_AFYPPlayerController_GetGoalDestination_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFYPPlayerController_GetGoalDestination_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04880401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AFYPPlayerController_GetGoalDestination_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AFYPPlayerController_GetGoalDestination_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AFYPPlayerController_GetGoalDestination()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFYPPlayerController_GetGoalDestination_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AFYPPlayerController_GoToNextPointOnCustomPath_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFYPPlayerController_GoToNextPointOnCustomPath_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "FYPPlayerController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFYPPlayerController_GoToNextPointOnCustomPath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFYPPlayerController, nullptr, "GoToNextPointOnCustomPath", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AFYPPlayerController_GoToNextPointOnCustomPath_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AFYPPlayerController_GoToNextPointOnCustomPath_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AFYPPlayerController_GoToNextPointOnCustomPath()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFYPPlayerController_GoToNextPointOnCustomPath_Statics::FuncParams);
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
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFYPPlayerController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_FYP,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AFYPPlayerController_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AFYPPlayerController_CustomGoingToNextPoint, "CustomGoingToNextPoint" }, // 296265936
		{ &Z_Construct_UFunction_AFYPPlayerController_CustomJump, "CustomJump" }, // 4003349505
		{ &Z_Construct_UFunction_AFYPPlayerController_FindNavData, "FindNavData" }, // 3145709781
		{ &Z_Construct_UFunction_AFYPPlayerController_FindPath, "FindPath" }, // 4270711578
		{ &Z_Construct_UFunction_AFYPPlayerController_GetGoalDestination, "GetGoalDestination" }, // 947276957
		{ &Z_Construct_UFunction_AFYPPlayerController_GoToNextPointOnCustomPath, "GoToNextPointOnCustomPath" }, // 1805034540
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
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFYPPlayerController_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPlayerController_Statics::NewProp_ShortPressThreshold,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPlayerController_Statics::NewProp_FXCursor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPlayerController_Statics::NewProp_DefaultMappingContext,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPlayerController_Statics::NewProp_SetDestinationClickAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFYPPlayerController_Statics::NewProp_SetDestinationTouchAction,
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
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_Statics::ScriptStructInfo[] = {
		{ FJumpPoint::StaticStruct, Z_Construct_UScriptStruct_FJumpPoint_Statics::NewStructOps, TEXT("JumpPoint"), &Z_Registration_Info_UScriptStruct_JumpPoint, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FJumpPoint), 1750899947U) },
		{ FCustomPathPoint::StaticStruct, Z_Construct_UScriptStruct_FCustomPathPoint_Statics::NewStructOps, TEXT("CustomPathPoint"), &Z_Registration_Info_UScriptStruct_CustomPathPoint, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCustomPathPoint), 2786217025U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AFYPPlayerController, AFYPPlayerController::StaticClass, TEXT("AFYPPlayerController"), &Z_Registration_Info_UClass_AFYPPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFYPPlayerController), 1751074001U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_4153835723(TEXT("/Script/FYP"),
		Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
