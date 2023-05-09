#include "PCH.h"

// Nothing should be modified within this file

// Command hook
BOOL WINAPI HookManager::CommandHook(LPCSTR CommandString, LPARAM lParam)
{
	return ((HookManager*)lParam)->CommandHook(CommandString);
}

// Connection hook
void WINAPI HookManager::ConnectionHook(DWORD EventCode, LPARAM lParam)
{
	((HookManager*)lParam)->ConnectionHook((Emulator::ConnectionState)EventCode);
}

// Device hook
void WINAPI HookManager::DeviceHook(DWORD EventCode, LPARAM lParam)
{
	((HookManager*)lParam)->DeviceHook((Emulator::DeviceState)EventCode);
}

// Message hook
void WINAPI HookManager::MessageHook(BYTE PacketID, WORD PayloadSize, BYTE* Payload, LPARAM lParam)
{
	((HookManager*)lParam)->MessageHook(PacketID, PayloadSize, Payload);
}