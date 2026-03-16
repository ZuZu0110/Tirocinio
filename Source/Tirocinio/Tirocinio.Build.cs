// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Tirocinio : ModuleRules
{
	public Tirocinio(ReadOnlyTargetRules Target) : base(Target)
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
			"Slate",
			"HTTP",
			"Json",
			"JsonUtilities"
        });

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"Tirocinio",
			"Tirocinio/Variant_Platforming",
			"Tirocinio/Variant_Platforming/Animation",
			"Tirocinio/Variant_Combat",
			"Tirocinio/Variant_Combat/AI",
			"Tirocinio/Variant_Combat/Animation",
			"Tirocinio/Variant_Combat/Gameplay",
			"Tirocinio/Variant_Combat/Interfaces",
			"Tirocinio/Variant_Combat/UI",
			"Tirocinio/Variant_SideScrolling",
			"Tirocinio/Variant_SideScrolling/AI",
			"Tirocinio/Variant_SideScrolling/Gameplay",
			"Tirocinio/Variant_SideScrolling/Interfaces",
			"Tirocinio/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
