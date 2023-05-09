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

	enum RumbleValue {
		RumbleA,
		RumbleB,
		RumbleRT,
		RumbleLT
	};

	enum ConsoleType {
		Console_None,
		Console_Ps3,
		Console_Xb360,
		Console_Ps4,
		Console_Xb1,
		Console_Switch,
		Console_Ps5,
		Console_Wheel = 8,
	};

	enum ControllerType {
		Controller_None,
		Controller_Ps3 = 16,
		Controller_Xb360 = 32,
		Controller_Wii = 48,
		Controller_WiiN,
		Controller_WiiPro,
		Controller_SwitchPro,
		Controller_SwitchCon,
		Controller_WiiuPro,
		Controller_Ps4 = 64,
		Controller_Ps5,
		Controller_Xb1 = 80,
		Controller_Df = 100,
		Controller_DfPro = 104,
		Controller_Dfgt = 106,
		Controller_G25 = 105,
		Controller_G27 = 107,
		Controller_G29 = 112,
		Controller_G920H = 98,
		Controller_G920X = 128,
		Controller_KEYBMOUSE = 144
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

	typedef WORD(WINAPI* GetCpuLoadValueProc)(void);
	typedef BYTE(WINAPI* GetSlotValueProc)(void);
	typedef ControllerType(WINAPI* GetConnectedControllerProc)(void);
	typedef ConsoleType(WINAPI* GetConnectedConsoleProc)(void);
	typedef BYTE(WINAPI* GetLedStateProc)(BYTE Index);
	typedef BYTE(WINAPI* GetRumbleProc)(RumbleValue Rumble);
	typedef BYTE(WINAPI* GetBatteryValueProc)(void);
	typedef char(WINAPI* GetInputValueProc)(BYTE Input);
	typedef BYTE(WINAPI* GetVmSpeedValueProc)(void);

	// Plugin interface
	struct PluginInformation {
		DWORD Size;

		// Zen++ API functions
		ProcessConsoleCommandProc	ProcessConsoleCommand;
		RefreshUserInputProc		RefreshUserInput;
		ResetCursorPositionProc		ResetCursorPosition;
		SetOutputColorProc			SetOutputColor;
		WriteOutputTimestampProc	WriteOutputTimestamp;
		WriteOutputStringProc		WriteOutputString;
		GetCpuLoadValueProc			GetCpuLoadValue;
		GetSlotValueProc			GetSlotValue;
		GetConnectedControllerProc	GetConnectedController;
		GetConnectedConsoleProc		GetConnectedConsole;
		GetLedStateProc				GetLedState;
		GetRumbleProc				GetRumble;
		GetBatteryValueProc			GetBatteryValue;
		GetInputValueProc			GetInputValue;
		GetVmSpeedValueProc			GetVmSpeedValue;


		// Hooks
		ConnectionHookProc ConnectionHook;
		CommandHookProc CommandHook;
		DeviceHookProc DeviceHook;
		MessageHookProc MessageHook;

		LPARAM HookParam;
	};

	// Handles:
	static HANDLE Thread;
}

DWORD WINAPI PluginThread(LPVOID Parameter);
	// Main thread for the plugin

BOOL WINAPI PluginMain(PluginAPI::PluginInformation* Information);
    // Export as "SetInterfaceInformation"

#endif