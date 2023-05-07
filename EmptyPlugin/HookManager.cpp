#include "PCH.h"

// Connection hook
BOOL WINAPI HookManager::ConnectionHook(DWORD EventCode, LPARAM lParam)
{
	return ((HookManager*)lParam)->ConnectionHook((PluginAPI::ConnectionState)EventCode);
}

// Command hook
BOOL WINAPI HookManager::CommandHook(LPCSTR CommandString, LPARAM lParam)
{
	return ((HookManager*)lParam)->CommandHook(CommandString);
}

// Device hook
BOOL WINAPI HookManager::DeviceHook(DWORD EventCode, LPARAM lParam)
{
	return ((HookManager*)lParam)->DeviceHook((PluginAPI::DeviceState)EventCode);
}

// Message hook
BOOL WINAPI HookManager::MessageHook(BYTE PacketID, WORD PayloadSize, BYTE* Payload, LPARAM lParam)
{
	return ((HookManager*)lParam)->MessageHook(PacketID, PayloadSize, Payload);
}