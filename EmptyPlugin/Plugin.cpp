#include "PCH.h"

// Connection hook
BOOL Plugin::ConnectionHook(PluginAPI::ConnectionState EventCode)
{
	// Called upon changes in the connection state

	// Add code here
	return FALSE;
}

// Command Hook
BOOL Plugin::CommandHook(LPCSTR CommandString)
{ 
	// Process a console command (if it is not an internal command to the host)

	// Add code here (return TRUE if processed, FALSE if not)
	return FALSE;
}

// Device Hook
BOOL Plugin::DeviceHook(PluginAPI::DeviceState EventCode)
{
	// Called when the target device is found or not found to be connected to the system

	// Add code here
	return FALSE;
}

// Mesasge Hook
BOOL Plugin::MessageHook(BYTE PacketID, WORD PayloadSize, BYTE* Payload)
{
	// Called when a complete packet is received from the device

	// Add code here
	return FALSE;
}

BOOL Plugin::Initialize(void)
{
	PluginAPI::Thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)PluginThread, NULL, 0, NULL);

	// Confirm the thread was created
	if (PluginAPI::Thread == INVALID_HANDLE_VALUE) {
		return FALSE;
	}

	// Add any initialization code here
	return TRUE;
}

void Plugin::Terminate(void)
{
	// Close the PluginThread handle
	if (PluginAPI::Thread != INVALID_HANDLE_VALUE)
		CloseHandle(PluginAPI::Thread);

	// Add any termination code here
}