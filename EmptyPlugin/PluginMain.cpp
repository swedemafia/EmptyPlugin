#include "PCH.h"

// Global objects
EmulatorAPIManager API;
Plugin PluginInstance;

static BOOL Initialized;

BOOL APIENTRY DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpvReserved)
{
	switch (dwReason) {
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hInstance);
		break;

	case DLL_PROCESS_DETACH:

		if (Initialized)
			PluginInstance.Terminate();

		break;

	default:
		__assume(0);  // No other cases exist due to DisableThreadLibraryCalls
	}

	return TRUE;
}

BOOL WINAPI PluginMain(PluginAPI::PluginInformation* Information)
{

	// Verify the parameter is the correct size
	if (Information->Size != sizeof(PluginAPI::PluginInformation))
		return FALSE;

	ZeroMemory(&API, sizeof(API));

	// Set addresses
	API.m_ProcessConsoleCommand = Information->ProcessConsoleCommand;
	API.m_RefreshUserInput = Information->RefreshUserInput;
	API.m_ResetCursorPosition = Information->ResetCursorPosition;
	API.m_SetOutputColor = Information->SetOutputColor;
	API.m_WriteOutputString = Information->WriteOutputString;
	API.m_WriteOutputTimestamp = Information->WriteOutputTimestamp;

	// Set hook addresses
	Information->ConnectionHook = &HookManager::ConnectionHook;
	Information->CommandHook = &HookManager::CommandHook;
	Information->DeviceHook = &HookManager::DeviceHook;
	Information->MessageHook = &HookManager::MessageHook;

	Information->HookParam = (LPARAM)&PluginInstance;

	return Initialized = PluginInstance.Initialize();
}