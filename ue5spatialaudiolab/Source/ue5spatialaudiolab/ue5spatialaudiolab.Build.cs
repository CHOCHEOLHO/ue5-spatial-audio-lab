// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ue5spatialaudiolab : ModuleRules
{
	public ue5spatialaudiolab(ReadOnlyTargetRules Target) : base(Target)
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
			"ue5spatialaudiolab",
			"ue5spatialaudiolab/Variant_Horror",
			"ue5spatialaudiolab/Variant_Horror/UI",
			"ue5spatialaudiolab/Variant_Shooter",
			"ue5spatialaudiolab/Variant_Shooter/AI",
			"ue5spatialaudiolab/Variant_Shooter/UI",
			"ue5spatialaudiolab/Variant_Shooter/Weapons"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
