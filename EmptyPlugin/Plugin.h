#ifndef PLUGIN_H
#define PLUGIN_H
#pragma once

class Plugin : public HookManager
{
protected:

	// Hooks:
	BOOL CommandHook(LPCSTR ConsoleCommand);
	void ConnectionHook(Emulator::ConnectionState EventCode);
	void DeviceHook(Emulator::DeviceState EventCode);
	void MessageHook(BYTE PacketID, WORD PayloadSize, BYTE* Payload);

public:
	// Use these instead of a constructor/destructor
	BOOL Initialize(void); // Return FALSE to abort (if this returns FALSE, Terminate will not be called)
	void Terminate(void); // Perform any termination of the plugin here
	void WriteFormattedOutput(UINT Color, LPCSTR Format, ...); // Formatted text output
};

#endif
