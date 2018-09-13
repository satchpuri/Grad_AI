// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef AIPROJECT_CustomCamera_generated_h
#error "CustomCamera.generated.h already included, missing '#pragma once' in CustomCamera.h"
#endif
#define AIPROJECT_CustomCamera_generated_h

#define AIProject_Source_AIProject_Public_CustomCamera_h_12_RPC_WRAPPERS
#define AIProject_Source_AIProject_Public_CustomCamera_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define AIProject_Source_AIProject_Public_CustomCamera_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACustomCamera(); \
	friend AIPROJECT_API class UClass* Z_Construct_UClass_ACustomCamera(); \
public: \
	DECLARE_CLASS(ACustomCamera, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/AIProject"), NO_API) \
	DECLARE_SERIALIZER(ACustomCamera) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define AIProject_Source_AIProject_Public_CustomCamera_h_12_INCLASS \
private: \
	static void StaticRegisterNativesACustomCamera(); \
	friend AIPROJECT_API class UClass* Z_Construct_UClass_ACustomCamera(); \
public: \
	DECLARE_CLASS(ACustomCamera, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/AIProject"), NO_API) \
	DECLARE_SERIALIZER(ACustomCamera) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define AIProject_Source_AIProject_Public_CustomCamera_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACustomCamera(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACustomCamera) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACustomCamera); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACustomCamera); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACustomCamera(ACustomCamera&&); \
	NO_API ACustomCamera(const ACustomCamera&); \
public:


#define AIProject_Source_AIProject_Public_CustomCamera_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACustomCamera(ACustomCamera&&); \
	NO_API ACustomCamera(const ACustomCamera&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACustomCamera); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACustomCamera); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACustomCamera)


#define AIProject_Source_AIProject_Public_CustomCamera_h_12_PRIVATE_PROPERTY_OFFSET
#define AIProject_Source_AIProject_Public_CustomCamera_h_9_PROLOG
#define AIProject_Source_AIProject_Public_CustomCamera_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AIProject_Source_AIProject_Public_CustomCamera_h_12_PRIVATE_PROPERTY_OFFSET \
	AIProject_Source_AIProject_Public_CustomCamera_h_12_RPC_WRAPPERS \
	AIProject_Source_AIProject_Public_CustomCamera_h_12_INCLASS \
	AIProject_Source_AIProject_Public_CustomCamera_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AIProject_Source_AIProject_Public_CustomCamera_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AIProject_Source_AIProject_Public_CustomCamera_h_12_PRIVATE_PROPERTY_OFFSET \
	AIProject_Source_AIProject_Public_CustomCamera_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	AIProject_Source_AIProject_Public_CustomCamera_h_12_INCLASS_NO_PURE_DECLS \
	AIProject_Source_AIProject_Public_CustomCamera_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AIProject_Source_AIProject_Public_CustomCamera_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
