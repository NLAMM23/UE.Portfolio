// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NLA_UE_Project : ModuleRules
{
	public NLA_UE_Project(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"NLA_UE_Project",
			"NLA_UE_Project/Variant_Horror",
			"NLA_UE_Project/Variant_Horror/UI",
			"NLA_UE_Project/Variant_Shooter",
			"NLA_UE_Project/Variant_Shooter/AI",
			"NLA_UE_Project/Variant_Shooter/UI",
			"NLA_UE_Project/Variant_Shooter/Weapons"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
