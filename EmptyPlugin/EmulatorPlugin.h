#ifndef EMULATORPLUGIN_H
#define EMULATORPLUGIN_H
#pragma once

namespace PluginAPI
{
	enum ConnectionState {
		Connection_Disconnected,
		Connection_Connecting,
		Connection_Connected,
		Connection_ClearBtCommand,
		Connection_CycleSlot,
		Connection_DeviceCleanup,
		Connection_FactoryReset,
		Connection_FlashConfig,
		Connection_FlashGamepack,
		Connection_RefreshDevice,
		Connection_ResetDevice,
		Connection_RunScript,
		Connection_UnloadGpc
	};

	enum DeviceState {
		Device_NotFound,
		Device_Found
	};

	enum OutputColor {
		Blue = 1,
		Green,
		Cyan,
		Red,
		Magenta,
		Brown,
		LightGray,
		DarkGray,
		LightBlue,
		LightGreen,
		LightCyan,
		LightRed,
		LightMagenta,
		Yellow,
		White,
		NumColors
	};

	// Prototypes of callback functions

	// Hooks:
	typedef BOOL(WINAPI* ConnectionHookProc)(DWORD EventCode, LPARAM lParam);
	typedef BOOL(WINAPI* CommandHookProc)(LPCSTR ConsoleCommand, LPARAM lParam);
	typedef BOOL(WINAPI* DeviceHookProc)(DWORD EventCode, LPARAM lParam);
	typedef BOOL(WINAPI* MessageHookProc)(BYTE PacketID, WORD PayloadSize, BYTE* Payload, LPARAM lParam);

	// Prototypes of Zen++ API Functions
	typedef BOOL(WINAPI* ProcessConsoleCommandProc)(LPCSTR CommandString);
	typedef int(WINAPI* RefreshUserInputProc)(void);
	typedef BOOL(WINAPI* ResetCursorPositionProc)(void);
	typedef BOOL(WINAPI* SetOutputColorProc)(OutputColor Color);
	typedef int(WINAPI* WriteOutputTimestampProc)(void);
	typedef int(WINAPI* WriteOutputStringProc)(LPCSTR String);

	// Plugin interface
	struct PluginInformation {
		DWORD Size;

		// Zen++ API functions
		ProcessConsoleCommandProc ProcessConsoleCommand;
		RefreshUserInputProc RefreshUserInput;
		ResetCursorPositionProc ResetCursorPosition;
		SetOutputColorProc SetOutputColor;
		WriteOutputTimestampProc WriteOutputTimestamp;
		WriteOutputStringProc WriteOutputString;

		// Hooks
		ConnectionHookProc ConnectionHook;
		CommandHookProc CommandHook;
		DeviceHookProc DeviceHook;
		MessageHookProc MessageHook;

		LPARAM HookParam;
	};
}

BOOL WINAPI PluginMain(PluginAPI::PluginInformation* Information);
    // Export as "SetInterfaceInformation"

#endif