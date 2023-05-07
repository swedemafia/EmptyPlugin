#include "PCH.h"

// Connection hook
BOOL Plugin::ConnectionHook(PluginAPI::ConnectionState EventCode)
{
	// Called upon changes in the connection state

	// Add code here
	
	// Sample code
	if (EventCode == PluginAPI::Connection_Connected) {

		API.ResetCursorPosition();
		API.WriteOutputTimestamp();
		API.SetOutputColor(PluginAPI::LightCyan);
		API.WriteOutputString("The plugin has been notified that the device is now connected!\r\n");
		API.RefreshUserInput();

		return TRUE;
	}

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

	// Sample code
	if (EventCode == PluginAPI::Device_NotFound) {
		API.ResetCursorPosition();
		API.WriteOutputTimestamp();
		API.SetOutputColor(PluginAPI::LightMagenta);
		API.WriteOutputString("Plugin has been informed that no device is connected to the system!\r\n");
		API.RefreshUserInput();
		return TRUE;
	}

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
	// Add any initialization code here
	return TRUE;
}

void Plugin::Terminate(void)
{
	// Add any termination code here
}