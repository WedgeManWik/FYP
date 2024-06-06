// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FYP/NavInterface.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNavInterface() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	FYP_API UClass* Z_Construct_UClass_UNavInterface();
	FYP_API UClass* Z_Construct_UClass_UNavInterface_NoRegister();
	UPackage* Z_Construct_UPackage__Script_FYP();
// End Cross Module References
	DEFINE_FUNCTION(INavInterface::execCollidedWithNavLink)
	{
		P_GET_STRUCT_REF(FVector,Z_Param_Out_LowerLocation);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_UpperLocation);
		P_GET_UBOOL_REF(Z_Param_Out_IsLower);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->CollidedWithNavLink_Implementation(Z_Param_Out_LowerLocation,Z_Param_Out_UpperLocation,Z_Param_Out_IsLower);
		P_NATIVE_END;
	}
	struct NavInterface_eventCollidedWithNavLink_Parms
	{
		FVector LowerLocation;
		FVector UpperLocation;
		bool IsLower;
		bool ReturnValue;

		/** Constructor, initializes return property only **/
		NavInterface_eventCollidedWithNavLink_Parms()
			: ReturnValue(false)
		{
		}
	};
	bool INavInterface::CollidedWithNavLink(FVector& LowerLocation, FVector& UpperLocation, bool& IsLower)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_CollidedWithNavLink instead.");
		NavInterface_eventCollidedWithNavLink_Parms Parms;
		return Parms.ReturnValue;
	}
	void UNavInterface::StaticRegisterNativesUNavInterface()
	{
		UClass* Class = UNavInterface::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CollidedWithNavLink", &INavInterface::execCollidedWithNavLink },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UNavInterface_CollidedWithNavLink_Statics
	{
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
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UNavInterface_CollidedWithNavLink_Statics::NewProp_LowerLocation = { "LowerLocation", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(NavInterface_eventCollidedWithNavLink_Parms, LowerLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UNavInterface_CollidedWithNavLink_Statics::NewProp_UpperLocation = { "UpperLocation", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(NavInterface_eventCollidedWithNavLink_Parms, UpperLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UNavInterface_CollidedWithNavLink_Statics::NewProp_IsLower_SetBit(void* Obj)
	{
		((NavInterface_eventCollidedWithNavLink_Parms*)Obj)->IsLower = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UNavInterface_CollidedWithNavLink_Statics::NewProp_IsLower = { "IsLower", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(NavInterface_eventCollidedWithNavLink_Parms), &Z_Construct_UFunction_UNavInterface_CollidedWithNavLink_Statics::NewProp_IsLower_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UNavInterface_CollidedWithNavLink_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((NavInterface_eventCollidedWithNavLink_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UNavInterface_CollidedWithNavLink_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(NavInterface_eventCollidedWithNavLink_Parms), &Z_Construct_UFunction_UNavInterface_CollidedWithNavLink_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UNavInterface_CollidedWithNavLink_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNavInterface_CollidedWithNavLink_Statics::NewProp_LowerLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNavInterface_CollidedWithNavLink_Statics::NewProp_UpperLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNavInterface_CollidedWithNavLink_Statics::NewProp_IsLower,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNavInterface_CollidedWithNavLink_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UNavInterface_CollidedWithNavLink_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "NavInterface.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UNavInterface_CollidedWithNavLink_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UNavInterface, nullptr, "CollidedWithNavLink", nullptr, nullptr, sizeof(NavInterface_eventCollidedWithNavLink_Parms), Z_Construct_UFunction_UNavInterface_CollidedWithNavLink_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UNavInterface_CollidedWithNavLink_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0CC20C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UNavInterface_CollidedWithNavLink_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UNavInterface_CollidedWithNavLink_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UNavInterface_CollidedWithNavLink()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UNavInterface_CollidedWithNavLink_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UNavInterface);
	UClass* Z_Construct_UClass_UNavInterface_NoRegister()
	{
		return UNavInterface::StaticClass();
	}
	struct Z_Construct_UClass_UNavInterface_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UNavInterface_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_FYP,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UNavInterface_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UNavInterface_CollidedWithNavLink, "CollidedWithNavLink" }, // 1619530179
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNavInterface_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "NavInterface.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UNavInterface_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<INavInterface>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UNavInterface_Statics::ClassParams = {
		&UNavInterface::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x000840A1u,
		METADATA_PARAMS(Z_Construct_UClass_UNavInterface_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UNavInterface_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UNavInterface()
	{
		if (!Z_Registration_Info_UClass_UNavInterface.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UNavInterface.OuterSingleton, Z_Construct_UClass_UNavInterface_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UNavInterface.OuterSingleton;
	}
	template<> FYP_API UClass* StaticClass<UNavInterface>()
	{
		return UNavInterface::StaticClass();
	}
	UNavInterface::UNavInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNavInterface);
	UNavInterface::~UNavInterface() {}
	static FName NAME_UNavInterface_CollidedWithNavLink = FName(TEXT("CollidedWithNavLink"));
	bool INavInterface::Execute_CollidedWithNavLink(UObject* O, FVector& LowerLocation, FVector& UpperLocation, bool& IsLower)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UNavInterface::StaticClass()));
		NavInterface_eventCollidedWithNavLink_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UNavInterface_CollidedWithNavLink);
		if (Func)
		{
			Parms.LowerLocation=LowerLocation;
			Parms.UpperLocation=UpperLocation;
			Parms.IsLower=IsLower;
			O->ProcessEvent(Func, &Parms);
			LowerLocation=Parms.LowerLocation;
			UpperLocation=Parms.UpperLocation;
			IsLower=Parms.IsLower;
		}
		else if (auto I = (INavInterface*)(O->GetNativeInterfaceAddress(UNavInterface::StaticClass())))
		{
			Parms.ReturnValue = I->CollidedWithNavLink_Implementation(LowerLocation,UpperLocation,IsLower);
		}
		return Parms.ReturnValue;
	}
	struct Z_CompiledInDeferFile_FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_NavInterface_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_NavInterface_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UNavInterface, UNavInterface::StaticClass, TEXT("UNavInterface"), &Z_Registration_Info_UClass_UNavInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UNavInterface), 2841791141U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_NavInterface_h_1720398267(TEXT("/Script/FYP"),
		Z_CompiledInDeferFile_FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_NavInterface_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_NavInterface_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
