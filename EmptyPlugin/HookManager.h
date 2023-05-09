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

	static BOOL WINAPI CommandHook(LPCSTR CommandString, LPARAM lParam);
	static void WINAPI ConnectionHook(DWORD EventCode, LPARAM lParam);
	static void WINAPI DeviceHook(DWORD EventCode, LPARAM lParam);
	static void WINAPI MessageHook(BYTE PacketID, WORD PayloadSize, BYTE* Payload, LPARAM lParam);

protected:

	virtual BOOL CommandHook(LPCSTR CommandString) = 0;
	virtual void ConnectionHook(Emulator::ConnectionState EventCode) = 0;
	virtual void DeviceHook(Emulator::DeviceState EventCode) = 0;
	virtual void MessageHook(BYTE PacketID, WORD PayloadSize, BYTE* Payload) = 0;
};

#endif
