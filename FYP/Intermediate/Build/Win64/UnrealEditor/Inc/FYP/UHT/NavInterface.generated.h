// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "NavInterface.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FYP_NavInterface_generated_h
#error "NavInterface.generated.h already included, missing '#pragma once' in NavInterface.h"
#endif
#define FYP_NavInterface_generated_h

#define FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_NavInterface_h_13_SPARSE_DATA
#define FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_NavInterface_h_13_RPC_WRAPPERS \
	virtual bool CollidedWithNavLink_Implementation(FVector& LowerLocation, FVector& UpperLocation, bool& IsLower) { return false; }; \
 \
	DECLARE_FUNCTION(execCollidedWithNavLink);


#define FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_NavInterface_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool CollidedWithNavLink_Implementation(FVector& LowerLocation, FVector& UpperLocation, bool& IsLower) { return false; }; \
 \
	DECLARE_FUNCTION(execCollidedWithNavLink);


#define FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_NavInterface_h_13_ACCESSORS
#define FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_NavInterface_h_13_CALLBACK_WRAPPERS
#define FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_NavInterface_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	FYP_API UNavInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UNavInterface) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(FYP_API, UNavInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UNavInterface); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	FYP_API UNavInterface(UNavInterface&&); \
	FYP_API UNavInterface(const UNavInterface&); \
public: \
	FYP_API virtual ~UNavInterface();


#define FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_NavInterface_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	FYP_API UNavInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	FYP_API UNavInterface(UNavInterface&&); \
	FYP_API UNavInterface(const UNavInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(FYP_API, UNavInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UNavInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UNavInterface) \
	FYP_API virtual ~UNavInterface();


#define FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_NavInterface_h_13_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUNavInterface(); \
	friend struct Z_Construct_UClass_UNavInterface_Statics; \
public: \
	DECLARE_CLASS(UNavInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/FYP"), FYP_API) \
	DECLARE_SERIALIZER(UNavInterface)


#define FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_NavInterface_h_13_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_NavInterface_h_13_GENERATED_UINTERFACE_BODY() \
	FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_NavInterface_h_13_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_NavInterface_h_13_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_NavInterface_h_13_GENERATED_UINTERFACE_BODY() \
	FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_NavInterface_h_13_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_NavInterface_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~INavInterface() {} \
public: \
	typedef UNavInterface UClassType; \
	typedef INavInterface ThisClass; \
	static bool Execute_CollidedWithNavLink(UObject* O, FVector& LowerLocation, FVector& UpperLocation, bool& IsLower); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_NavInterface_h_13_INCLASS_IINTERFACE \
protected: \
	virtual ~INavInterface() {} \
public: \
	typedef UNavInterface UClassType; \
	typedef INavInterface ThisClass; \
	static bool Execute_CollidedWithNavLink(UObject* O, FVector& LowerLocation, FVector& UpperLocation, bool& IsLower); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_NavInterface_h_10_PROLOG
#define FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_NavInterface_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_NavInterface_h_13_SPARSE_DATA \
	FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_NavInterface_h_13_RPC_WRAPPERS \
	FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_NavInterface_h_13_ACCESSORS \
	FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_NavInterface_h_13_CALLBACK_WRAPPERS \
	FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_NavInterface_h_13_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_NavInterface_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_NavInterface_h_13_SPARSE_DATA \
	FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_NavInterface_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_NavInterface_h_13_ACCESSORS \
	FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_NavInterface_h_13_CALLBACK_WRAPPERS \
	FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_NavInterface_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FYP_API UClass* StaticClass<class UNavInterface>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_j012100l_Documents_GitHub_FYP_FYP_Source_FYP_NavInterface_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
