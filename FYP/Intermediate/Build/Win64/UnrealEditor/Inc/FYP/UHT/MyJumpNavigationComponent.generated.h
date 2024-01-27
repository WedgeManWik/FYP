// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MyJumpNavigationComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class AController;
struct FPathPoint;
#ifdef FYP_MyJumpNavigationComponent_generated_h
#error "MyJumpNavigationComponent.generated.h already included, missing '#pragma once' in MyJumpNavigationComponent.h"
#endif
#define FYP_MyJumpNavigationComponent_generated_h

#define FID_GitHub_FYP_FYP_Source_FYP_MyJumpNavigationComponent_h_14_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPathPoint_Statics; \
	FYP_API static class UScriptStruct* StaticStruct();


template<> FYP_API UScriptStruct* StaticStruct<struct FPathPoint>();

#define FID_GitHub_FYP_FYP_Source_FYP_MyJumpNavigationComponent_h_25_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMyPolyEdge_Statics; \
	FYP_API static class UScriptStruct* StaticStruct();


template<> FYP_API UScriptStruct* StaticStruct<struct FMyPolyEdge>();

#define FID_GitHub_FYP_FYP_Source_FYP_MyJumpNavigationComponent_h_45_SPARSE_DATA
#define FID_GitHub_FYP_FYP_Source_FYP_MyJumpNavigationComponent_h_45_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGoToNextPointOnCustomPath); \
	DECLARE_FUNCTION(execSwitchPathfindMode); \
	DECLARE_FUNCTION(execFindPathPortals); \
	DECLARE_FUNCTION(execCreateCustomJumpPath); \
	DECLARE_FUNCTION(execInitialise);


#define FID_GitHub_FYP_FYP_Source_FYP_MyJumpNavigationComponent_h_45_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGoToNextPointOnCustomPath); \
	DECLARE_FUNCTION(execSwitchPathfindMode); \
	DECLARE_FUNCTION(execFindPathPortals); \
	DECLARE_FUNCTION(execCreateCustomJumpPath); \
	DECLARE_FUNCTION(execInitialise);


#define FID_GitHub_FYP_FYP_Source_FYP_MyJumpNavigationComponent_h_45_ACCESSORS
#define FID_GitHub_FYP_FYP_Source_FYP_MyJumpNavigationComponent_h_45_CALLBACK_WRAPPERS
#define FID_GitHub_FYP_FYP_Source_FYP_MyJumpNavigationComponent_h_45_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMyJumpNavigationComponent(); \
	friend struct Z_Construct_UClass_UMyJumpNavigationComponent_Statics; \
public: \
	DECLARE_CLASS(UMyJumpNavigationComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FYP"), NO_API) \
	DECLARE_SERIALIZER(UMyJumpNavigationComponent)


#define FID_GitHub_FYP_FYP_Source_FYP_MyJumpNavigationComponent_h_45_INCLASS \
private: \
	static void StaticRegisterNativesUMyJumpNavigationComponent(); \
	friend struct Z_Construct_UClass_UMyJumpNavigationComponent_Statics; \
public: \
	DECLARE_CLASS(UMyJumpNavigationComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FYP"), NO_API) \
	DECLARE_SERIALIZER(UMyJumpNavigationComponent)


#define FID_GitHub_FYP_FYP_Source_FYP_MyJumpNavigationComponent_h_45_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMyJumpNavigationComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMyJumpNavigationComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMyJumpNavigationComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMyJumpNavigationComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMyJumpNavigationComponent(UMyJumpNavigationComponent&&); \
	NO_API UMyJumpNavigationComponent(const UMyJumpNavigationComponent&); \
public: \
	NO_API virtual ~UMyJumpNavigationComponent();


#define FID_GitHub_FYP_FYP_Source_FYP_MyJumpNavigationComponent_h_45_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMyJumpNavigationComponent(UMyJumpNavigationComponent&&); \
	NO_API UMyJumpNavigationComponent(const UMyJumpNavigationComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMyJumpNavigationComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMyJumpNavigationComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UMyJumpNavigationComponent) \
	NO_API virtual ~UMyJumpNavigationComponent();


#define FID_GitHub_FYP_FYP_Source_FYP_MyJumpNavigationComponent_h_42_PROLOG
#define FID_GitHub_FYP_FYP_Source_FYP_MyJumpNavigationComponent_h_45_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_GitHub_FYP_FYP_Source_FYP_MyJumpNavigationComponent_h_45_SPARSE_DATA \
	FID_GitHub_FYP_FYP_Source_FYP_MyJumpNavigationComponent_h_45_RPC_WRAPPERS \
	FID_GitHub_FYP_FYP_Source_FYP_MyJumpNavigationComponent_h_45_ACCESSORS \
	FID_GitHub_FYP_FYP_Source_FYP_MyJumpNavigationComponent_h_45_CALLBACK_WRAPPERS \
	FID_GitHub_FYP_FYP_Source_FYP_MyJumpNavigationComponent_h_45_INCLASS \
	FID_GitHub_FYP_FYP_Source_FYP_MyJumpNavigationComponent_h_45_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_GitHub_FYP_FYP_Source_FYP_MyJumpNavigationComponent_h_45_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_GitHub_FYP_FYP_Source_FYP_MyJumpNavigationComponent_h_45_SPARSE_DATA \
	FID_GitHub_FYP_FYP_Source_FYP_MyJumpNavigationComponent_h_45_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_GitHub_FYP_FYP_Source_FYP_MyJumpNavigationComponent_h_45_ACCESSORS \
	FID_GitHub_FYP_FYP_Source_FYP_MyJumpNavigationComponent_h_45_CALLBACK_WRAPPERS \
	FID_GitHub_FYP_FYP_Source_FYP_MyJumpNavigationComponent_h_45_INCLASS_NO_PURE_DECLS \
	FID_GitHub_FYP_FYP_Source_FYP_MyJumpNavigationComponent_h_45_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FYP_API UClass* StaticClass<class UMyJumpNavigationComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_GitHub_FYP_FYP_Source_FYP_MyJumpNavigationComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
