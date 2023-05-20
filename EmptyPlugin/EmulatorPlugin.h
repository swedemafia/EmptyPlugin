#ifndef EMULATORPLUGIN_H
#define EMULATORPLUGIN_H
#pragma once

namespace Console
{
	enum Type {
		None,
		Ps3,
		Xb360,
		Ps4,
		Xb1,
		Switch,
		Ps5,
		Wheel = 8,
	};
}

namespace Controller
{
	enum Rumble {
		RumbleA,
		RumbleB,
		RumbleRT,
		RumbleLT
	};

	enum Type {
		None,
		Ps3 = 16,
		Xb360 = 32,
		Wii = 48,
		WiiN,
		WiiPro,
		SwitchPro,
		SwitchCon,
		WiiuPro,
		Ps4 = 64,
		Ps5,
		Xb1 = 80,
		Df = 100,
		DfPro = 104,
		Dfgt = 106,
		G25 = 105,
		G27 = 107,
		G29 = 112,
		G920H = 98,
		G920X = 128,
		KEYBMOUSE = 144
	};

	enum XboxOne {
		XB1_XBOX,
		XB1_VIEW,
		XB1_MENU,
		XB1_RB,
		XB1_RT,
		XB1_RS,
		XB1_LB,
		XB1_LT,
		XB1_LS,
		XB1_RX,
		XB1_RY,
		XB1_LX,
		XB1_LY,
		XB1_UP,
		XB1_DOWN,
		XB1_LEFT,
		XB1_RIGHT,
		XB1_Y,
		XB1_B,
		XB1_A,
		XB1_X,
		XB1_SHARE,
		XB1_SYNC = 27,
		XB1_PR1,
		XB1_PR2,
		XB1_PL1,
		XB1_PL2
	};
}

namespace Device
{
	enum TraceValue {
		TRACE_1 = 0,
		TRACE_2,
		TRACE_3,
		TRACE_4,
		TRACE_5,
		TRACE_6
	};
}

namespace Emulator
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
}

namespace PluginAPI
{
	// Prototypes of callback functions

	// Hooks:
	typedef BOOL(WINAPI* CommandHookProc)(LPCSTR ConsoleCommand, LPARAM lParam);
	typedef void(WINAPI* ConnectionHookProc)(DWORD EventCode, LPARAM lParam);
	typedef void(WINAPI* DeviceHookProc)(DWORD EventCode, LPARAM lParam);
	typedef void(WINAPI* MessageHookProc)(BYTE PacketID, WORD PayloadSize, BYTE* Payload, LPARAM lParam);

	// Prototypes of Zen++ API Functions
	
	// UI:
	typedef BOOL(WINAPI* ProcessConsoleCommandProc)(LPCSTR CommandString);
	typedef int(WINAPI* RefreshUserInputProc)(void);
	typedef BOOL(WINAPI* ResetCursorPositionProc)(void);
	typedef BOOL(WINAPI* SetOutputColorProc)(Emulator::OutputColor Color);
	typedef int(WINAPI* WriteOutputTimestampProc)(void);
	typedef int(WINAPI* WriteOutputStringProc)(LPCSTR String);

	// Actions:
	typedef BOOL(WINAPI* EventPressProc)(BYTE Identifier);
	typedef BOOL(WINAPI* EventReleaseProc)(BYTE Identifier);

	// Controller:
	typedef BYTE(WINAPI* GetBatteryValueProc)(void);
	typedef char(WINAPI* GetInputValueProc)(BYTE Identifier);
	typedef char(WINAPI* GetLastInputValueProc)(BYTE Identifier);
	typedef char(WINAPI* GetOutputValueProc)(BYTE Identifier);
	typedef DWORD(WINAPI* GetPressTimeProc)(BYTE Identifier);
	typedef DWORD(WINAPI* GetReleaseTimeProc)(BYTE Identifier);
	typedef BYTE(WINAPI* GetRumbleProc)(Controller::Rumble Rumble);
	typedef DWORD(WINAPI* GetTraceValueProc)(Device::TraceValue Value);

	// Device:
	typedef Console::Type(WINAPI* GetConnectedConsoleProc)(void);
	typedef Controller::Type(WINAPI* GetConnectedControllerProc)(void);
	typedef WORD(WINAPI* GetCpuLoadValueProc)(void);
	typedef BYTE(WINAPI* GetLedStateProc)(BYTE Index);
	typedef BYTE(WINAPI* GetSlotValueProc)(void);
	typedef BYTE(WINAPI* GetVmSpeedValueProc)(void);

	// Plugin interface
	struct PluginInformation {
		DWORD Size;

		// Zen++ API functions
		// UI:
		ProcessConsoleCommandProc	ProcessConsoleCommand;
		RefreshUserInputProc		RefreshUserInput;
		ResetCursorPositionProc		ResetCursorPosition;
		SetOutputColorProc			SetOutputColor;
		WriteOutputTimestampProc	WriteOutputTimestamp;
		WriteOutputStringProc		WriteOutputString;

		// Actions:
		EventPressProc				EventPress;
		EventReleaseProc			EventRelease;
		
		// Controller:
		GetBatteryValueProc			GetBatteryValue;
		GetInputValueProc			GetInputValue;
		GetLastInputValueProc		GetLastInputValue;
		GetOutputValueProc			GetOutputValue;
		GetPressTimeProc			GetPressTime;
		GetReleaseTimeProc			GetReleaseTime;
		GetRumbleProc				GetRumble;

		// Device:
		GetConnectedConsoleProc		GetConnectedConsole;
		GetConnectedControllerProc	GetConnectedController;
		GetCpuLoadValueProc			GetCpuLoadValue;
		GetLedStateProc				GetLedState;
		GetSlotValueProc			GetSlotValue;
		GetTraceValueProc			GetTraceValue;
		GetVmSpeedValueProc			GetVmSpeedValue;

		// Hooks
		ConnectionHookProc			ConnectionHook;
		CommandHookProc				CommandHook;
		DeviceHookProc				DeviceHook;
		MessageHookProc				MessageHook;
		LPARAM						HookParam;
	};

	// Handles:
	static HANDLE Thread;
}


BOOL WINAPI PluginMain(PluginAPI::PluginInformation* Information);
    // Export as "SetInterfaceInformation"

DWORD WINAPI PluginThread(LPVOID Parameter);
	// Main thread for the plugin

#endif