// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NLA_UE_ProjectCameraManager.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeNLA_UE_ProjectCameraManager() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_APlayerCameraManager();
NLA_UE_PROJECT_API UClass* Z_Construct_UClass_ANLA_UE_ProjectCameraManager();
NLA_UE_PROJECT_API UClass* Z_Construct_UClass_ANLA_UE_ProjectCameraManager_NoRegister();
UPackage* Z_Construct_UPackage__Script_NLA_UE_Project();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ANLA_UE_ProjectCameraManager *********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_ANLA_UE_ProjectCameraManager;
UClass* ANLA_UE_ProjectCameraManager::GetPrivateStaticClass()
{
	using TClass = ANLA_UE_ProjectCameraManager;
	if (!Z_Registration_Info_UClass_ANLA_UE_ProjectCameraManager.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("NLA_UE_ProjectCameraManager"),
			Z_Registration_Info_UClass_ANLA_UE_ProjectCameraManager.InnerSingleton,
			StaticRegisterNativesANLA_UE_ProjectCameraManager,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_ANLA_UE_ProjectCameraManager.InnerSingleton;
}
UClass* Z_Construct_UClass_ANLA_UE_ProjectCameraManager_NoRegister()
{
	return ANLA_UE_ProjectCameraManager::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ANLA_UE_ProjectCameraManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Basic First Person camera manager.\n *  Limits min/max look pitch.\n */" },
#endif
		{ "IncludePath", "NLA_UE_ProjectCameraManager.h" },
		{ "ModuleRelativePath", "NLA_UE_ProjectCameraManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Basic First Person camera manager.\nLimits min/max look pitch." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class ANLA_UE_ProjectCameraManager constinit property declarations *************
// ********** End Class ANLA_UE_ProjectCameraManager constinit property declarations ***************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANLA_UE_ProjectCameraManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_ANLA_UE_ProjectCameraManager_Statics
UObject* (*const Z_Construct_UClass_ANLA_UE_ProjectCameraManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerCameraManager,
	(UObject* (*)())Z_Construct_UPackage__Script_NLA_UE_Project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANLA_UE_ProjectCameraManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ANLA_UE_ProjectCameraManager_Statics::ClassParams = {
	&ANLA_UE_ProjectCameraManager::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANLA_UE_ProjectCameraManager_Statics::Class_MetaDataParams), Z_Construct_UClass_ANLA_UE_ProjectCameraManager_Statics::Class_MetaDataParams)
};
void ANLA_UE_ProjectCameraManager::StaticRegisterNativesANLA_UE_ProjectCameraManager()
{
}
UClass* Z_Construct_UClass_ANLA_UE_ProjectCameraManager()
{
	if (!Z_Registration_Info_UClass_ANLA_UE_ProjectCameraManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ANLA_UE_ProjectCameraManager.OuterSingleton, Z_Construct_UClass_ANLA_UE_ProjectCameraManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ANLA_UE_ProjectCameraManager.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ANLA_UE_ProjectCameraManager);
ANLA_UE_ProjectCameraManager::~ANLA_UE_ProjectCameraManager() {}
// ********** End Class ANLA_UE_ProjectCameraManager ***********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_student_Desktop_UnrealEngine_UE_Portfolio_NLA_UE_Project_Source_NLA_UE_Project_NLA_UE_ProjectCameraManager_h__Script_NLA_UE_Project_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ANLA_UE_ProjectCameraManager, ANLA_UE_ProjectCameraManager::StaticClass, TEXT("ANLA_UE_ProjectCameraManager"), &Z_Registration_Info_UClass_ANLA_UE_ProjectCameraManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ANLA_UE_ProjectCameraManager), 1983636664U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_student_Desktop_UnrealEngine_UE_Portfolio_NLA_UE_Project_Source_NLA_UE_Project_NLA_UE_ProjectCameraManager_h__Script_NLA_UE_Project_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_student_Desktop_UnrealEngine_UE_Portfolio_NLA_UE_Project_Source_NLA_UE_Project_NLA_UE_ProjectCameraManager_h__Script_NLA_UE_Project_3779069557{
	TEXT("/Script/NLA_UE_Project"),
	Z_CompiledInDeferFile_FID_Users_student_Desktop_UnrealEngine_UE_Portfolio_NLA_UE_Project_Source_NLA_UE_Project_NLA_UE_ProjectCameraManager_h__Script_NLA_UE_Project_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_student_Desktop_UnrealEngine_UE_Portfolio_NLA_UE_Project_Source_NLA_UE_Project_NLA_UE_ProjectCameraManager_h__Script_NLA_UE_Project_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
