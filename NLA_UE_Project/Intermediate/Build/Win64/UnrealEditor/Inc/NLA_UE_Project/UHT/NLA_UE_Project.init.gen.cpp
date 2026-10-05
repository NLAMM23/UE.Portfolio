// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNLA_UE_Project_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	NLA_UE_PROJECT_API UFunction* Z_Construct_UDelegateFunction_NLA_UE_Project_BulletCountUpdatedDelegate__DelegateSignature();
	NLA_UE_PROJECT_API UFunction* Z_Construct_UDelegateFunction_NLA_UE_Project_DamagedDelegate__DelegateSignature();
	NLA_UE_PROJECT_API UFunction* Z_Construct_UDelegateFunction_NLA_UE_Project_PawnDeathDelegate__DelegateSignature();
	NLA_UE_PROJECT_API UFunction* Z_Construct_UDelegateFunction_NLA_UE_Project_SprintStateChangedDelegate__DelegateSignature();
	NLA_UE_PROJECT_API UFunction* Z_Construct_UDelegateFunction_NLA_UE_Project_UpdateSprintMeterDelegate__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_NLA_UE_Project;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_NLA_UE_Project()
	{
		if (!Z_Registration_Info_UPackage__Script_NLA_UE_Project.OuterSingleton)
		{
		static UObject* (*const SingletonFuncArray[])() = {
			(UObject* (*)())Z_Construct_UDelegateFunction_NLA_UE_Project_BulletCountUpdatedDelegate__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_NLA_UE_Project_DamagedDelegate__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_NLA_UE_Project_PawnDeathDelegate__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_NLA_UE_Project_SprintStateChangedDelegate__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_NLA_UE_Project_UpdateSprintMeterDelegate__DelegateSignature,
		};
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/NLA_UE_Project",
			SingletonFuncArray,
			UE_ARRAY_COUNT(SingletonFuncArray),
			PKG_CompiledIn | 0x00000000,
			0x318BFDF5,
			0x94946BDB,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_NLA_UE_Project.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_NLA_UE_Project.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_NLA_UE_Project(Z_Construct_UPackage__Script_NLA_UE_Project, TEXT("/Script/NLA_UE_Project"), Z_Registration_Info_UPackage__Script_NLA_UE_Project, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x318BFDF5, 0x94946BDB));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
