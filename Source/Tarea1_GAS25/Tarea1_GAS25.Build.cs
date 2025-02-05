// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Tarea1_GAS25 : ModuleRules
{
	public Tarea1_GAS25(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "NavigationSystem", "AIModule", "Niagara", "EnhancedInput", "GameplayAbilities","GameplayTags","GameplayTasks","UMG" });
	}
}
