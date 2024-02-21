// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

#include "FGResourceSinkSubsystem.h"
#include "FGResourceSinkSettings.h"

class FFixClientResourceSinkPointsModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	static void SetupHooks();
};
