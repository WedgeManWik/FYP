// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FYP/MyJumpNavigationComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyJumpNavigationComponent() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_AController_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	FYP_API UClass* Z_Construct_UClass_UMyJumpNavigationComponent();
	FYP_API UClass* Z_Construct_UClass_UMyJumpNavigationComponent_NoRegister();
	FYP_API UScriptStruct* Z_Construct_UScriptStruct_FMyPolyEdge();
	FYP_API UScriptStruct* Z_Construct_UScriptStruct_FPathPoint();
	UPackage* Z_Construct_UPackage__Script_FYP();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PathPoint;
class UScriptStruct* FPathPoint::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PathPoint.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PathPoint.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPathPoint, (UObject*)Z_Construct_UPackage__Script_FYP(), TEXT("PathPoint"));
	}
	return Z_Registration_Info_UScriptStruct_PathPoint.OuterSingleton;
}
template<> FYP_API UScriptStruct* StaticStruct<FPathPoint>()
{
	return FPathPoint::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPathPoint_Statics
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
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IsJump_MetaData[];
#endif
		static void NewProp_IsJump_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsJump;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPathPoint_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "MyJumpNavigationComponent.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPathPoint_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPathPoint>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPathPoint_Statics::NewProp_Location_MetaData[] = {
		{ "Category", "PathPoint" },
		{ "ModuleRelativePath", "MyJumpNavigationComponent.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPathPoint_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FPathPoint, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FPathPoint_Statics::NewProp_Location_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPathPoint_Statics::NewProp_Location_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPathPoint_Statics::NewProp_IsJump_MetaData[] = {
		{ "Category", "PathPoint" },
		{ "ModuleRelativePath", "MyJumpNavigationComponent.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FPathPoint_Statics::NewProp_IsJump_SetBit(void* Obj)
	{
		((FPathPoint*)Obj)->IsJump = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPathPoint_Statics::NewProp_IsJump = { "IsJump", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(FPathPoint), &Z_Construct_UScriptStruct_FPathPoint_Statics::NewProp_IsJump_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FPathPoint_Statics::NewProp_IsJump_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPathPoint_Statics::NewProp_IsJump_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPathPoint_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPathPoint_Statics::NewProp_Location,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPathPoint_Statics::NewProp_IsJump,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPathPoint_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_FYP,
		nullptr,
		&NewStructOps,
		"PathPoint",
		sizeof(FPathPoint),
		alignof(FPathPoint),
		Z_Construct_UScriptStruct_FPathPoint_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPathPoint_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FPathPoint_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPathPoint_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FPathPoint()
	{
		if (!Z_Registration_Info_UScriptStruct_PathPoint.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PathPoint.InnerSingleton, Z_Construct_UScriptStruct_FPathPoint_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PathPoint.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_MyPolyEdge;
class UScriptStruct* FMyPolyEdge::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_MyPolyEdge.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_MyPolyEdge.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMyPolyEdge, (UObject*)Z_Construct_UPackage__Script_FYP(), TEXT("MyPolyEdge"));
	}
	return Z_Registration_Info_UScriptStruct_MyPolyEdge.OuterSingleton;
}
template<> FYP_API UScriptStruct* StaticStruct<FMyPolyEdge>()
{
	return FMyPolyEdge::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FMyPolyEdge_Statics
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
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IsJumpEdge_MetaData[];
#endif
		static void NewProp_IsJumpEdge_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsJumpEdge;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMyPolyEdge_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "MyJumpNavigationComponent.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FMyPolyEdge_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMyPolyEdge>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMyPolyEdge_Statics::NewProp_Left_MetaData[] = {
		{ "Category", "MyPolyEdge" },
		{ "ModuleRelativePath", "MyJumpNavigationComponent.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMyPolyEdge_Statics::NewProp_Left = { "Left", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FMyPolyEdge, Left), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FMyPolyEdge_Statics::NewProp_Left_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMyPolyEdge_Statics::NewProp_Left_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMyPolyEdge_Statics::NewProp_Right_MetaData[] = {
		{ "Category", "MyPolyEdge" },
		{ "ModuleRelativePath", "MyJumpNavigationComponent.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMyPolyEdge_Statics::NewProp_Right = { "Right", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FMyPolyEdge, Right), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FMyPolyEdge_Statics::NewProp_Right_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMyPolyEdge_Statics::NewProp_Right_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMyPolyEdge_Statics::NewProp_IsJumpEdge_MetaData[] = {
		{ "Category", "MyPolyEdge" },
		{ "ModuleRelativePath", "MyJumpNavigationComponent.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FMyPolyEdge_Statics::NewProp_IsJumpEdge_SetBit(void* Obj)
	{
		((FMyPolyEdge*)Obj)->IsJumpEdge = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FMyPolyEdge_Statics::NewProp_IsJumpEdge = { "IsJumpEdge", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(FMyPolyEdge), &Z_Construct_UScriptStruct_FMyPolyEdge_Statics::NewProp_IsJumpEdge_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FMyPolyEdge_Statics::NewProp_IsJumpEdge_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMyPolyEdge_Statics::NewProp_IsJumpEdge_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMyPolyEdge_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyPolyEdge_Statics::NewProp_Left,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyPolyEdge_Statics::NewProp_Right,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyPolyEdge_Statics::NewProp_IsJumpEdge,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMyPolyEdge_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_FYP,
		nullptr,
		&NewStructOps,
		"MyPolyEdge",
		sizeof(FMyPolyEdge),
		alignof(FMyPolyEdge),
		Z_Construct_UScriptStruct_FMyPolyEdge_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMyPolyEdge_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FMyPolyEdge_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMyPolyEdge_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FMyPolyEdge()
	{
		if (!Z_Registration_Info_UScriptStruct_MyPolyEdge.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_MyPolyEdge.InnerSingleton, Z_Construct_UScriptStruct_FMyPolyEdge_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_MyPolyEdge.InnerSingleton;
	}
	DEFINE_FUNCTION(UMyJumpNavigationComponent::execGoToNextPointOnCustomPath)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GoToNextPointOnCustomPath();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMyJumpNavigationComponent::execSwitchPathfindMode)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SwitchPathfindMode();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMyJumpNavigationComponent::execFindPathPortals)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->FindPathPortals();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMyJumpNavigationComponent::execCreateCustomJumpPath)
	{
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Start);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Destination);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CreateCustomJumpPath(Z_Param_Out_Start,Z_Param_Out_Destination);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMyJumpNavigationComponent::execInitialise)
	{
		P_GET_OBJECT(AController,Z_Param_Controller);
		P_GET_OBJECT(APawn,Z_Param_Pawn);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Initialise(Z_Param_Controller,Z_Param_Pawn);
		P_NATIVE_END;
	}
	struct MyJumpNavigationComponent_eventCustomGoingToNextPoint_Parms
	{
		FPathPoint PathPoint;
	};
	static FName NAME_UMyJumpNavigationComponent_CustomGoingToNextPoint = FName(TEXT("CustomGoingToNextPoint"));
	void UMyJumpNavigationComponent::CustomGoingToNextPoint(FPathPoint PathPoint)
	{
		MyJumpNavigationComponent_eventCustomGoingToNextPoint_Parms Parms;
		Parms.PathPoint=PathPoint;
		ProcessEvent(FindFunctionChecked(NAME_UMyJumpNavigationComponent_CustomGoingToNextPoint),&Parms);
	}
	void UMyJumpNavigationComponent::StaticRegisterNativesUMyJumpNavigationComponent()
	{
		UClass* Class = UMyJumpNavigationComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CreateCustomJumpPath", &UMyJumpNavigationComponent::execCreateCustomJumpPath },
			{ "FindPathPortals", &UMyJumpNavigationComponent::execFindPathPortals },
			{ "GoToNextPointOnCustomPath", &UMyJumpNavigationComponent::execGoToNextPointOnCustomPath },
			{ "Initialise", &UMyJumpNavigationComponent::execInitialise },
			{ "SwitchPathfindMode", &UMyJumpNavigationComponent::execSwitchPathfindMode },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UMyJumpNavigationComponent_CreateCustomJumpPath_Statics
	{
		struct MyJumpNavigationComponent_eventCreateCustomJumpPath_Parms
		{
			FVector Start;
			FVector Destination;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Start_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Start;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Destination_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Destination;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyJumpNavigationComponent_CreateCustomJumpPath_Statics::NewProp_Start_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMyJumpNavigationComponent_CreateCustomJumpPath_Statics::NewProp_Start = { "Start", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(MyJumpNavigationComponent_eventCreateCustomJumpPath_Parms, Start), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_UMyJumpNavigationComponent_CreateCustomJumpPath_Statics::NewProp_Start_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyJumpNavigationComponent_CreateCustomJumpPath_Statics::NewProp_Start_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyJumpNavigationComponent_CreateCustomJumpPath_Statics::NewProp_Destination_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMyJumpNavigationComponent_CreateCustomJumpPath_Statics::NewProp_Destination = { "Destination", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(MyJumpNavigationComponent_eventCreateCustomJumpPath_Parms, Destination), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_UMyJumpNavigationComponent_CreateCustomJumpPath_Statics::NewProp_Destination_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyJumpNavigationComponent_CreateCustomJumpPath_Statics::NewProp_Destination_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyJumpNavigationComponent_CreateCustomJumpPath_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyJumpNavigationComponent_CreateCustomJumpPath_Statics::NewProp_Start,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyJumpNavigationComponent_CreateCustomJumpPath_Statics::NewProp_Destination,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyJumpNavigationComponent_CreateCustomJumpPath_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyJumpNavigationComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyJumpNavigationComponent_CreateCustomJumpPath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyJumpNavigationComponent, nullptr, "CreateCustomJumpPath", nullptr, nullptr, sizeof(Z_Construct_UFunction_UMyJumpNavigationComponent_CreateCustomJumpPath_Statics::MyJumpNavigationComponent_eventCreateCustomJumpPath_Parms), Z_Construct_UFunction_UMyJumpNavigationComponent_CreateCustomJumpPath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyJumpNavigationComponent_CreateCustomJumpPath_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMyJumpNavigationComponent_CreateCustomJumpPath_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyJumpNavigationComponent_CreateCustomJumpPath_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMyJumpNavigationComponent_CreateCustomJumpPath()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyJumpNavigationComponent_CreateCustomJumpPath_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMyJumpNavigationComponent_CustomGoingToNextPoint_Statics
	{
		static const UECodeGen_Private::FStructPropertyParams NewProp_PathPoint;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMyJumpNavigationComponent_CustomGoingToNextPoint_Statics::NewProp_PathPoint = { "PathPoint", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(MyJumpNavigationComponent_eventCustomGoingToNextPoint_Parms, PathPoint), Z_Construct_UScriptStruct_FPathPoint, METADATA_PARAMS(nullptr, 0) }; // 1105633815
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyJumpNavigationComponent_CustomGoingToNextPoint_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyJumpNavigationComponent_CustomGoingToNextPoint_Statics::NewProp_PathPoint,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyJumpNavigationComponent_CustomGoingToNextPoint_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyJumpNavigationComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyJumpNavigationComponent_CustomGoingToNextPoint_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyJumpNavigationComponent, nullptr, "CustomGoingToNextPoint", nullptr, nullptr, sizeof(MyJumpNavigationComponent_eventCustomGoingToNextPoint_Parms), Z_Construct_UFunction_UMyJumpNavigationComponent_CustomGoingToNextPoint_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyJumpNavigationComponent_CustomGoingToNextPoint_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMyJumpNavigationComponent_CustomGoingToNextPoint_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyJumpNavigationComponent_CustomGoingToNextPoint_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMyJumpNavigationComponent_CustomGoingToNextPoint()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyJumpNavigationComponent_CustomGoingToNextPoint_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMyJumpNavigationComponent_FindPathPortals_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyJumpNavigationComponent_FindPathPortals_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyJumpNavigationComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyJumpNavigationComponent_FindPathPortals_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyJumpNavigationComponent, nullptr, "FindPathPortals", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMyJumpNavigationComponent_FindPathPortals_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyJumpNavigationComponent_FindPathPortals_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMyJumpNavigationComponent_FindPathPortals()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyJumpNavigationComponent_FindPathPortals_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMyJumpNavigationComponent_GoToNextPointOnCustomPath_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyJumpNavigationComponent_GoToNextPointOnCustomPath_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyJumpNavigationComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyJumpNavigationComponent_GoToNextPointOnCustomPath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyJumpNavigationComponent, nullptr, "GoToNextPointOnCustomPath", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMyJumpNavigationComponent_GoToNextPointOnCustomPath_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyJumpNavigationComponent_GoToNextPointOnCustomPath_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMyJumpNavigationComponent_GoToNextPointOnCustomPath()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyJumpNavigationComponent_GoToNextPointOnCustomPath_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMyJumpNavigationComponent_Initialise_Statics
	{
		struct MyJumpNavigationComponent_eventInitialise_Parms
		{
			AController* Controller;
			APawn* Pawn;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Controller;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Pawn;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMyJumpNavigationComponent_Initialise_Statics::NewProp_Controller = { "Controller", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(MyJumpNavigationComponent_eventInitialise_Parms, Controller), Z_Construct_UClass_AController_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMyJumpNavigationComponent_Initialise_Statics::NewProp_Pawn = { "Pawn", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(MyJumpNavigationComponent_eventInitialise_Parms, Pawn), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyJumpNavigationComponent_Initialise_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyJumpNavigationComponent_Initialise_Statics::NewProp_Controller,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyJumpNavigationComponent_Initialise_Statics::NewProp_Pawn,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyJumpNavigationComponent_Initialise_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyJumpNavigationComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyJumpNavigationComponent_Initialise_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyJumpNavigationComponent, nullptr, "Initialise", nullptr, nullptr, sizeof(Z_Construct_UFunction_UMyJumpNavigationComponent_Initialise_Statics::MyJumpNavigationComponent_eventInitialise_Parms), Z_Construct_UFunction_UMyJumpNavigationComponent_Initialise_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyJumpNavigationComponent_Initialise_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMyJumpNavigationComponent_Initialise_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyJumpNavigationComponent_Initialise_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMyJumpNavigationComponent_Initialise()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyJumpNavigationComponent_Initialise_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMyJumpNavigationComponent_SwitchPathfindMode_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyJumpNavigationComponent_SwitchPathfindMode_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyJumpNavigationComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyJumpNavigationComponent_SwitchPathfindMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyJumpNavigationComponent, nullptr, "SwitchPathfindMode", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMyJumpNavigationComponent_SwitchPathfindMode_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyJumpNavigationComponent_SwitchPathfindMode_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMyJumpNavigationComponent_SwitchPathfindMode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyJumpNavigationComponent_SwitchPathfindMode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMyJumpNavigationComponent);
	UClass* Z_Construct_UClass_UMyJumpNavigationComponent_NoRegister()
	{
		return UMyJumpNavigationComponent::StaticClass();
	}
	struct Z_Construct_UClass_UMyJumpNavigationComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MyController_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_MyController;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MyPawn_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_MyPawn;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMyJumpNavigationComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_FYP,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UMyJumpNavigationComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UMyJumpNavigationComponent_CreateCustomJumpPath, "CreateCustomJumpPath" }, // 2401140805
		{ &Z_Construct_UFunction_UMyJumpNavigationComponent_CustomGoingToNextPoint, "CustomGoingToNextPoint" }, // 4019301181
		{ &Z_Construct_UFunction_UMyJumpNavigationComponent_FindPathPortals, "FindPathPortals" }, // 3509360243
		{ &Z_Construct_UFunction_UMyJumpNavigationComponent_GoToNextPointOnCustomPath, "GoToNextPointOnCustomPath" }, // 1419841438
		{ &Z_Construct_UFunction_UMyJumpNavigationComponent_Initialise, "Initialise" }, // 118681201
		{ &Z_Construct_UFunction_UMyJumpNavigationComponent_SwitchPathfindMode, "SwitchPathfindMode" }, // 2547448917
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyJumpNavigationComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "MyJumpNavigationComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "MyJumpNavigationComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyJumpNavigationComponent_Statics::NewProp_MyController_MetaData[] = {
		{ "Category", "MyJumpNavigationComponent" },
		{ "ModuleRelativePath", "MyJumpNavigationComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UMyJumpNavigationComponent_Statics::NewProp_MyController = { "MyController", nullptr, (EPropertyFlags)0x0024080000020015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UMyJumpNavigationComponent, MyController), Z_Construct_UClass_AController_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UMyJumpNavigationComponent_Statics::NewProp_MyController_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMyJumpNavigationComponent_Statics::NewProp_MyController_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyJumpNavigationComponent_Statics::NewProp_MyPawn_MetaData[] = {
		{ "Category", "MyJumpNavigationComponent" },
		{ "ModuleRelativePath", "MyJumpNavigationComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UMyJumpNavigationComponent_Statics::NewProp_MyPawn = { "MyPawn", nullptr, (EPropertyFlags)0x0024080000020015, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UMyJumpNavigationComponent, MyPawn), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UMyJumpNavigationComponent_Statics::NewProp_MyPawn_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMyJumpNavigationComponent_Statics::NewProp_MyPawn_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMyJumpNavigationComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyJumpNavigationComponent_Statics::NewProp_MyController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyJumpNavigationComponent_Statics::NewProp_MyPawn,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMyJumpNavigationComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyJumpNavigationComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMyJumpNavigationComponent_Statics::ClassParams = {
		&UMyJumpNavigationComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UMyJumpNavigationComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UMyJumpNavigationComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UMyJumpNavigationComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMyJumpNavigationComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMyJumpNavigationComponent()
	{
		if (!Z_Registration_Info_UClass_UMyJumpNavigationComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMyJumpNavigationComponent.OuterSingleton, Z_Construct_UClass_UMyJumpNavigationComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UMyJumpNavigationComponent.OuterSingleton;
	}
	template<> FYP_API UClass* StaticClass<UMyJumpNavigationComponent>()
	{
		return UMyJumpNavigationComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMyJumpNavigationComponent);
	UMyJumpNavigationComponent::~UMyJumpNavigationComponent() {}
	struct Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_MyJumpNavigationComponent_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_MyJumpNavigationComponent_h_Statics::ScriptStructInfo[] = {
		{ FPathPoint::StaticStruct, Z_Construct_UScriptStruct_FPathPoint_Statics::NewStructOps, TEXT("PathPoint"), &Z_Registration_Info_UScriptStruct_PathPoint, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPathPoint), 1105633815U) },
		{ FMyPolyEdge::StaticStruct, Z_Construct_UScriptStruct_FMyPolyEdge_Statics::NewStructOps, TEXT("MyPolyEdge"), &Z_Registration_Info_UScriptStruct_MyPolyEdge, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMyPolyEdge), 3219218819U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_MyJumpNavigationComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UMyJumpNavigationComponent, UMyJumpNavigationComponent::StaticClass, TEXT("UMyJumpNavigationComponent"), &Z_Registration_Info_UClass_UMyJumpNavigationComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMyJumpNavigationComponent), 686992477U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_MyJumpNavigationComponent_h_3585516769(TEXT("/Script/FYP"),
		Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_MyJumpNavigationComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_MyJumpNavigationComponent_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_MyJumpNavigationComponent_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_MyJumpNavigationComponent_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
