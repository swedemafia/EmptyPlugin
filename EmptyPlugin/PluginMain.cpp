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
	
	// UI:
	API.m_ProcessConsoleCommand		= Information->ProcessConsoleCommand;
	API.m_RefreshUserInput			= Information->RefreshUserInput;
	API.m_ResetCursorPosition		= Information->ResetCursorPosition;
	API.m_SetOutputColor			= Information->SetOutputColor;
	API.m_WriteOutputString			= Information->WriteOutputString;
	API.m_WriteOutputTimestamp		= Information->WriteOutputTimestamp;

	// Input:
	API.m_GetCpuLoadValue			= Information->GetCpuLoadValue;
	API.m_GetSlotValue				= Information->GetSlotValue;
	API.m_GetConnectedController	= Information->GetConnectedController;
	API.m_GetConnectedConsole		= Information->GetConnectedConsole;
	API.m_GetLedState				= Information->GetLedState;
	API.m_GetRumble					= Information->GetRumble;
	API.m_GetBatteryValue			= Information->GetBatteryValue;
	API.m_GetInputValue				= Information->GetInputValue;
	API.m_GetVmSpeedValue			= Information->GetVmSpeedValue;

	// Set hook addresses
	Information->ConnectionHook = &HookManager::ConnectionHook;
	Information->CommandHook = &HookManager::CommandHook;
	Information->DeviceHook = &HookManager::DeviceHook;
	Information->MessageHook = &HookManager::MessageHook;

	Information->HookParam = (LPARAM)&PluginInstance;

	return Initialized = PluginInstance.Initialize();
}

DWORD WINAPI PluginThread(LPVOID Parameter)
{
	// Add code here
	return 0;
}