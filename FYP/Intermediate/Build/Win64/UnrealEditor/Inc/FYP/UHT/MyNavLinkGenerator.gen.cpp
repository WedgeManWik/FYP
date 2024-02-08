// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FYP/MyNavLinkGenerator.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyNavLinkGenerator() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	FYP_API UClass* Z_Construct_UClass_AMyNavLinkGenerator();
	FYP_API UClass* Z_Construct_UClass_AMyNavLinkGenerator_NoRegister();
	NAVIGATIONSYSTEM_API UClass* Z_Construct_UClass_ARecastNavMesh_NoRegister();
	UPackage* Z_Construct_UPackage__Script_FYP();
// End Cross Module References
	DEFINE_FUNCTION(AMyNavLinkGenerator::execGenerateNavMeshLinks)
	{
		P_GET_OBJECT(ARecastNavMesh,Z_Param_Nav);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GenerateNavMeshLinks(Z_Param_Nav);
		P_NATIVE_END;
	}
	struct MyNavLinkGenerator_eventSpawnPotentialNavLink_Parms
	{
		FVector Location;
		FVector Direction;
	};
	struct MyNavLinkGenerator_eventTraceJumpAtCorner_Parms
	{
		FVector Location;
		FVector Direction1;
		FVector Direction2;
	};
	struct MyNavLinkGenerator_eventTraceJumpAtEdge_Parms
	{
		FVector Start;
		FVector End;
		FVector Direction;
	};
	static FName NAME_AMyNavLinkGenerator_SpawnPotentialNavLink = FName(TEXT("SpawnPotentialNavLink"));
	void AMyNavLinkGenerator::SpawnPotentialNavLink(FVector Location, FVector Direction)
	{
		MyNavLinkGenerator_eventSpawnPotentialNavLink_Parms Parms;
		Parms.Location=Location;
		Parms.Direction=Direction;
		ProcessEvent(FindFunctionChecked(NAME_AMyNavLinkGenerator_SpawnPotentialNavLink),&Parms);
	}
	static FName NAME_AMyNavLinkGenerator_TraceJumpAtCorner = FName(TEXT("TraceJumpAtCorner"));
	void AMyNavLinkGenerator::TraceJumpAtCorner(FVector Location, FVector Direction1, FVector Direction2)
	{
		MyNavLinkGenerator_eventTraceJumpAtCorner_Parms Parms;
		Parms.Location=Location;
		Parms.Direction1=Direction1;
		Parms.Direction2=Direction2;
		ProcessEvent(FindFunctionChecked(NAME_AMyNavLinkGenerator_TraceJumpAtCorner),&Parms);
	}
	static FName NAME_AMyNavLinkGenerator_TraceJumpAtEdge = FName(TEXT("TraceJumpAtEdge"));
	void AMyNavLinkGenerator::TraceJumpAtEdge(FVector Start, FVector End, FVector Direction)
	{
		MyNavLinkGenerator_eventTraceJumpAtEdge_Parms Parms;
		Parms.Start=Start;
		Parms.End=End;
		Parms.Direction=Direction;
		ProcessEvent(FindFunctionChecked(NAME_AMyNavLinkGenerator_TraceJumpAtEdge),&Parms);
	}
	void AMyNavLinkGenerator::StaticRegisterNativesAMyNavLinkGenerator()
	{
		UClass* Class = AMyNavLinkGenerator::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GenerateNavMeshLinks", &AMyNavLinkGenerator::execGenerateNavMeshLinks },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMyNavLinkGenerator_GenerateNavMeshLinks_Statics
	{
		struct MyNavLinkGenerator_eventGenerateNavMeshLinks_Parms
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMyNavLinkGenerator_GenerateNavMeshLinks_Statics::NewProp_Nav = { "Nav", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(MyNavLinkGenerator_eventGenerateNavMeshLinks_Parms, Nav), Z_Construct_UClass_ARecastNavMesh_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyNavLinkGenerator_GenerateNavMeshLinks_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyNavLinkGenerator_GenerateNavMeshLinks_Statics::NewProp_Nav,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyNavLinkGenerator_GenerateNavMeshLinks_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyNavLinkGenerator.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyNavLinkGenerator_GenerateNavMeshLinks_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyNavLinkGenerator, nullptr, "GenerateNavMeshLinks", nullptr, nullptr, sizeof(Z_Construct_UFunction_AMyNavLinkGenerator_GenerateNavMeshLinks_Statics::MyNavLinkGenerator_eventGenerateNavMeshLinks_Parms), Z_Construct_UFunction_AMyNavLinkGenerator_GenerateNavMeshLinks_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyNavLinkGenerator_GenerateNavMeshLinks_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyNavLinkGenerator_GenerateNavMeshLinks_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyNavLinkGenerator_GenerateNavMeshLinks_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyNavLinkGenerator_GenerateNavMeshLinks()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyNavLinkGenerator_GenerateNavMeshLinks_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyNavLinkGenerator_SpawnPotentialNavLink_Statics
	{
		static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Direction;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMyNavLinkGenerator_SpawnPotentialNavLink_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(MyNavLinkGenerator_eventSpawnPotentialNavLink_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMyNavLinkGenerator_SpawnPotentialNavLink_Statics::NewProp_Direction = { "Direction", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(MyNavLinkGenerator_eventSpawnPotentialNavLink_Parms, Direction), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyNavLinkGenerator_SpawnPotentialNavLink_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyNavLinkGenerator_SpawnPotentialNavLink_Statics::NewProp_Location,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyNavLinkGenerator_SpawnPotentialNavLink_Statics::NewProp_Direction,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyNavLinkGenerator_SpawnPotentialNavLink_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyNavLinkGenerator.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyNavLinkGenerator_SpawnPotentialNavLink_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyNavLinkGenerator, nullptr, "SpawnPotentialNavLink", nullptr, nullptr, sizeof(MyNavLinkGenerator_eventSpawnPotentialNavLink_Parms), Z_Construct_UFunction_AMyNavLinkGenerator_SpawnPotentialNavLink_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyNavLinkGenerator_SpawnPotentialNavLink_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08820800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyNavLinkGenerator_SpawnPotentialNavLink_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyNavLinkGenerator_SpawnPotentialNavLink_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyNavLinkGenerator_SpawnPotentialNavLink()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyNavLinkGenerator_SpawnPotentialNavLink_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyNavLinkGenerator_TraceJumpAtCorner_Statics
	{
		static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Direction1;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Direction2;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMyNavLinkGenerator_TraceJumpAtCorner_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(MyNavLinkGenerator_eventTraceJumpAtCorner_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMyNavLinkGenerator_TraceJumpAtCorner_Statics::NewProp_Direction1 = { "Direction1", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(MyNavLinkGenerator_eventTraceJumpAtCorner_Parms, Direction1), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMyNavLinkGenerator_TraceJumpAtCorner_Statics::NewProp_Direction2 = { "Direction2", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(MyNavLinkGenerator_eventTraceJumpAtCorner_Parms, Direction2), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyNavLinkGenerator_TraceJumpAtCorner_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyNavLinkGenerator_TraceJumpAtCorner_Statics::NewProp_Location,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyNavLinkGenerator_TraceJumpAtCorner_Statics::NewProp_Direction1,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyNavLinkGenerator_TraceJumpAtCorner_Statics::NewProp_Direction2,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyNavLinkGenerator_TraceJumpAtCorner_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyNavLinkGenerator.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyNavLinkGenerator_TraceJumpAtCorner_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyNavLinkGenerator, nullptr, "TraceJumpAtCorner", nullptr, nullptr, sizeof(MyNavLinkGenerator_eventTraceJumpAtCorner_Parms), Z_Construct_UFunction_AMyNavLinkGenerator_TraceJumpAtCorner_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyNavLinkGenerator_TraceJumpAtCorner_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08820800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyNavLinkGenerator_TraceJumpAtCorner_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyNavLinkGenerator_TraceJumpAtCorner_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyNavLinkGenerator_TraceJumpAtCorner()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyNavLinkGenerator_TraceJumpAtCorner_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyNavLinkGenerator_TraceJumpAtEdge_Statics
	{
		static const UECodeGen_Private::FStructPropertyParams NewProp_Start;
		static const UECodeGen_Private::FStructPropertyParams NewProp_End;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Direction;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMyNavLinkGenerator_TraceJumpAtEdge_Statics::NewProp_Start = { "Start", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(MyNavLinkGenerator_eventTraceJumpAtEdge_Parms, Start), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMyNavLinkGenerator_TraceJumpAtEdge_Statics::NewProp_End = { "End", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(MyNavLinkGenerator_eventTraceJumpAtEdge_Parms, End), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMyNavLinkGenerator_TraceJumpAtEdge_Statics::NewProp_Direction = { "Direction", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(MyNavLinkGenerator_eventTraceJumpAtEdge_Parms, Direction), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyNavLinkGenerator_TraceJumpAtEdge_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyNavLinkGenerator_TraceJumpAtEdge_Statics::NewProp_Start,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyNavLinkGenerator_TraceJumpAtEdge_Statics::NewProp_End,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyNavLinkGenerator_TraceJumpAtEdge_Statics::NewProp_Direction,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyNavLinkGenerator_TraceJumpAtEdge_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyNavLinkGenerator.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyNavLinkGenerator_TraceJumpAtEdge_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyNavLinkGenerator, nullptr, "TraceJumpAtEdge", nullptr, nullptr, sizeof(MyNavLinkGenerator_eventTraceJumpAtEdge_Parms), Z_Construct_UFunction_AMyNavLinkGenerator_TraceJumpAtEdge_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyNavLinkGenerator_TraceJumpAtEdge_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08820800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyNavLinkGenerator_TraceJumpAtEdge_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyNavLinkGenerator_TraceJumpAtEdge_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyNavLinkGenerator_TraceJumpAtEdge()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyNavLinkGenerator_TraceJumpAtEdge_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMyNavLinkGenerator);
	UClass* Z_Construct_UClass_AMyNavLinkGenerator_NoRegister()
	{
		return AMyNavLinkGenerator::StaticClass();
	}
	struct Z_Construct_UClass_AMyNavLinkGenerator_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMyNavLinkGenerator_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_FYP,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AMyNavLinkGenerator_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMyNavLinkGenerator_GenerateNavMeshLinks, "GenerateNavMeshLinks" }, // 2969330143
		{ &Z_Construct_UFunction_AMyNavLinkGenerator_SpawnPotentialNavLink, "SpawnPotentialNavLink" }, // 3968958744
		{ &Z_Construct_UFunction_AMyNavLinkGenerator_TraceJumpAtCorner, "TraceJumpAtCorner" }, // 3512385467
		{ &Z_Construct_UFunction_AMyNavLinkGenerator_TraceJumpAtEdge, "TraceJumpAtEdge" }, // 3370944777
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyNavLinkGenerator_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MyNavLinkGenerator.h" },
		{ "ModuleRelativePath", "MyNavLinkGenerator.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMyNavLinkGenerator_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyNavLinkGenerator>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AMyNavLinkGenerator_Statics::ClassParams = {
		&AMyNavLinkGenerator::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AMyNavLinkGenerator_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMyNavLinkGenerator_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMyNavLinkGenerator()
	{
		if (!Z_Registration_Info_UClass_AMyNavLinkGenerator.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMyNavLinkGenerator.OuterSingleton, Z_Construct_UClass_AMyNavLinkGenerator_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AMyNavLinkGenerator.OuterSingleton;
	}
	template<> FYP_API UClass* StaticClass<AMyNavLinkGenerator>()
	{
		return AMyNavLinkGenerator::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMyNavLinkGenerator);
	AMyNavLinkGenerator::~AMyNavLinkGenerator() {}
	struct Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_MyNavLinkGenerator_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_MyNavLinkGenerator_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AMyNavLinkGenerator, AMyNavLinkGenerator::StaticClass, TEXT("AMyNavLinkGenerator"), &Z_Registration_Info_UClass_AMyNavLinkGenerator, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMyNavLinkGenerator), 2580918588U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_MyNavLinkGenerator_h_213419599(TEXT("/Script/FYP"),
		Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_MyNavLinkGenerator_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GitHub_FYP_FYP_Source_FYP_MyNavLinkGenerator_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
