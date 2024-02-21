#include "FixClientResourceSinkPoints.h"

#include "SML/Public/Patching/NativeHookManager.h"

#define LOCTEXT_NAMESPACE "FFixClientResourceSinkPointsModule"

void FFixClientResourceSinkPointsModule::StartupModule()
{
#if !WITH_EDITOR
	SetupHooks();
#endif // !WITH_EDITOR
}

void FFixClientResourceSinkPointsModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

void Hook_SinkBeginPlay(AFGResourceSinkSubsystem* self) {
	if (not self->HasAuthority()) {
		self->SetupPointData(EResourceSinkTrack::RST_Default, UFGResourceSinkSettings::GetPointsDataTable());
		self->SetupPointData(EResourceSinkTrack::RST_Exploration, UFGResourceSinkSettings::GetExplorationPointsDataTable());
	}
}

void FFixClientResourceSinkPointsModule::SetupHooks() {
	SUBSCRIBE_UOBJECT_METHOD_AFTER(AFGResourceSinkSubsystem, BeginPlay, &Hook_SinkBeginPlay);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FFixClientResourceSinkPointsModule, FixClientResourceSinkPoints)
