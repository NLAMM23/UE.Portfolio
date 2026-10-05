// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NLA_UE_ProjectGameMode.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeNLA_UE_ProjectGameMode() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
NLA_UE_PROJECT_API UClass* Z_Construct_UClass_ANLA_UE_ProjectGameMode();
NLA_UE_PROJECT_API UClass* Z_Construct_UClass_ANLA_UE_ProjectGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_NLA_UE_Project();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ANLA_UE_ProjectGameMode **************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_ANLA_UE_ProjectGameMode;
UClass* ANLA_UE_ProjectGameMode::GetPrivateStaticClass()
{
	using TClass = ANLA_UE_ProjectGameMode;
	if (!Z_Registration_Info_UClass_ANLA_UE_ProjectGameMode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("NLA_UE_ProjectGameMode"),
			Z_Registration_Info_UClass_ANLA_UE_ProjectGameMode.InnerSingleton,
			StaticRegisterNativesANLA_UE_ProjectGameMode,
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
	return Z_Registration_Info_UClass_ANLA_UE_ProjectGameMode.InnerSingleton;
}
UClass* Z_Construct_UClass_ANLA_UE_ProjectGameMode_NoRegister()
{
	return ANLA_UE_ProjectGameMode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ANLA_UE_ProjectGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Simple GameMode for a first person game\n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "NLA_UE_ProjectGameMode.h" },
		{ "ModuleRelativePath", "NLA_UE_ProjectGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Simple GameMode for a first person game" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class ANLA_UE_ProjectGameMode constinit property declarations ******************
// ********** End Class ANLA_UE_ProjectGameMode constinit property declarations ********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANLA_UE_ProjectGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_ANLA_UE_ProjectGameMode_Statics
UObject* (*const Z_Construct_UClass_ANLA_UE_ProjectGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_NLA_UE_Project,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANLA_UE_ProjectGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ANLA_UE_ProjectGameMode_Statics::ClassParams = {
	&ANLA_UE_ProjectGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008002ADu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANLA_UE_ProjectGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ANLA_UE_ProjectGameMode_Statics::Class_MetaDataParams)
};
void ANLA_UE_ProjectGameMode::StaticRegisterNativesANLA_UE_ProjectGameMode()
{
}
UClass* Z_Construct_UClass_ANLA_UE_ProjectGameMode()
{
	if (!Z_Registration_Info_UClass_ANLA_UE_ProjectGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ANLA_UE_ProjectGameMode.OuterSingleton, Z_Construct_UClass_ANLA_UE_ProjectGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ANLA_UE_ProjectGameMode.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ANLA_UE_ProjectGameMode);
ANLA_UE_ProjectGameMode::~ANLA_UE_ProjectGameMode() {}
// ********** End Class ANLA_UE_ProjectGameMode ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_student_Desktop_UnrealEngine_UE_Portfolio_NLA_UE_Project_Source_NLA_UE_Project_NLA_UE_ProjectGameMode_h__Script_NLA_UE_Project_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ANLA_UE_ProjectGameMode, ANLA_UE_ProjectGameMode::StaticClass, TEXT("ANLA_UE_ProjectGameMode"), &Z_Registration_Info_UClass_ANLA_UE_ProjectGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ANLA_UE_ProjectGameMode), 3544435706U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_student_Desktop_UnrealEngine_UE_Portfolio_NLA_UE_Project_Source_NLA_UE_Project_NLA_UE_ProjectGameMode_h__Script_NLA_UE_Project_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_student_Desktop_UnrealEngine_UE_Portfolio_NLA_UE_Project_Source_NLA_UE_Project_NLA_UE_ProjectGameMode_h__Script_NLA_UE_Project_3209174446{
	TEXT("/Script/NLA_UE_Project"),
	Z_CompiledInDeferFile_FID_Users_student_Desktop_UnrealEngine_UE_Portfolio_NLA_UE_Project_Source_NLA_UE_Project_NLA_UE_ProjectGameMode_h__Script_NLA_UE_Project_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_student_Desktop_UnrealEngine_UE_Portfolio_NLA_UE_Project_Source_NLA_UE_Project_NLA_UE_ProjectGameMode_h__Script_NLA_UE_Project_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
