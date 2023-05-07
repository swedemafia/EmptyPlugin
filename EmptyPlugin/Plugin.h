#ifndef PLUGIN_H
#define PLUGIN_H
#pragma once

class Plugin : public HookManager
{
protected:

	// Hooks:
	BOOL ConnectionHook(PluginAPI::ConnectionState EventCode);
	BOOL CommandHook(LPCSTR ConsoleCommand);
	BOOL DeviceHook(PluginAPI::DeviceState EventCode);
	BOOL MessageHook(BYTE PacketID, WORD PayloadSize, BYTE* Payload);

public:
	// Use these instead of a constructor/destructor
	BOOL Initialize(void); // Return FALSE to abort (if this returns FALSE, Terminate will not be called)
	void Terminate(void); // Perform any termination of the plugin here
};

#endif
