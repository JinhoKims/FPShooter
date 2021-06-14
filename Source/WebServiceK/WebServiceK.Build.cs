// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class WebServiceK : ModuleRules
{
    public WebServiceK(ReadOnlyTargetRules Target) : base(Target)
    {
        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine" });
    }
}
