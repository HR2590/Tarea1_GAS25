#pragma once

#include "CoreMinimal.h"


DECLARE_LOG_CATEGORY_EXTERN(LogGASUTHUB25, Log, All);

class Tarea1_GAS25Module : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};


