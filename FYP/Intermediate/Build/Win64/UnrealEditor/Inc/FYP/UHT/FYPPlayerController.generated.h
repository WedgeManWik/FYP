// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "FYPPlayerController.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class ARecastNavMesh;
struct FJumpPoint;
#ifdef FYP_FYPPlayerController_generated_h
#error "FYPPlayerController.generated.h already included, missing '#pragma once' in FYPPlayerController.h"
#endif
#define FYP_FYPPlayerController_generated_h

#define FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_17_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FJumpPoint_Statics; \
	FYP_API static class UScriptStruct* StaticStruct();


template<> FYP_API UScriptStruct* StaticStruct<struct FJumpPoint>();

#define FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_28_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMyPolyEdge_Statics; \
	FYP_API static class UScriptStruct* StaticStruct();


template<> FYP_API UScriptStruct* StaticStruct<struct FMyPolyEdge>();

#define FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_48_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMyPoly_Statics; \
	FYP_API static class UScriptStruct* StaticStruct();


template<> FYP_API UScriptStruct* StaticStruct<struct FMyPoly>();

#define FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_59_SPARSE_DATA
#define FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_59_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetGoalDestination); \
	DECLARE_FUNCTION(execGoToNextPointOnCustomPath); \
	DECLARE_FUNCTION(execFindPath);


#define FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_59_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetGoalDestination); \
	DECLARE_FUNCTION(execGoToNextPointOnCustomPath); \
	DECLARE_FUNCTION(execFindPath);


#define FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_59_ACCESSORS
#define FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_59_CALLBACK_WRAPPERS
#define FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_59_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFYPPlayerController(); \
	friend struct Z_Construct_UClass_AFYPPlayerController_Statics; \
public: \
	DECLARE_CLASS(AFYPPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FYP"), NO_API) \
	DECLARE_SERIALIZER(AFYPPlayerController)


#define FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_59_INCLASS \
private: \
	static void StaticRegisterNativesAFYPPlayerController(); \
	friend struct Z_Construct_UClass_AFYPPlayerController_Statics; \
public: \
	DECLARE_CLASS(AFYPPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FYP"), NO_API) \
	DECLARE_SERIALIZER(AFYPPlayerController)


#define FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_59_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFYPPlayerController(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFYPPlayerController) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFYPPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFYPPlayerController); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFYPPlayerController(AFYPPlayerController&&); \
	NO_API AFYPPlayerController(const AFYPPlayerController&); \
public: \
	NO_API virtual ~AFYPPlayerController();


#define FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_59_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFYPPlayerController(AFYPPlayerController&&); \
	NO_API AFYPPlayerController(const AFYPPlayerController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFYPPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFYPPlayerController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFYPPlayerController) \
	NO_API virtual ~AFYPPlayerController();


#define FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_56_PROLOG
#define FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_59_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_59_SPARSE_DATA \
	FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_59_RPC_WRAPPERS \
	FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_59_ACCESSORS \
	FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_59_CALLBACK_WRAPPERS \
	FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_59_INCLASS \
	FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_59_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_59_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_59_SPARSE_DATA \
	FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_59_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_59_ACCESSORS \
	FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_59_CALLBACK_WRAPPERS \
	FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_59_INCLASS_NO_PURE_DECLS \
	FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h_59_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FYP_API UClass* StaticClass<class AFYPPlayerController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_GitHub_FYP_FYP_Source_FYP_FYPPlayerController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
