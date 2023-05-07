#ifndef HOOKMANAGER_H
#define HOOKMANAGER_H
#pragma once

class HookManager
{
	friend BOOL WINAPI PluginMain(PluginAPI::PluginInformation* Information);
		// PluginMain may read/set the private/protected variables/proc addresses

	friend class EmulatorAPIManager;
		// EmulatorAPIManager may call protected virtual functions

private:

	static BOOL WINAPI ConnectionHook(DWORD EventCode, LPARAM lParam);
	static BOOL WINAPI CommandHook(LPCSTR CommandString, LPARAM lParam);
	static BOOL WINAPI DeviceHook(DWORD EventCode, LPARAM lParam);
	static BOOL WINAPI MessageHook(BYTE PacketID, WORD PayloadSize, BYTE* Payload, LPARAM lParam);

protected:

	virtual BOOL ConnectionHook(PluginAPI::ConnectionState EventCode) = 0;
	virtual BOOL CommandHook(LPCSTR CommandString) = 0;
	virtual BOOL DeviceHook(PluginAPI::DeviceState EventCode) = 0;
	virtual BOOL MessageHook(BYTE PacketID, WORD PayloadSize, BYTE* Payload) = 0;
};

#endif
