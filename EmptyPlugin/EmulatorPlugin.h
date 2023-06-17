#ifndef EMULATORPLUGIN_H
#define EMULATORPLUGIN_H
#pragma once

#define BLACK 0
#define WHITE RGB(0xFF, 0xFF, 0xFF)
#define GRAY RGB(0x7B, 0x7B, 0x7B)
#define BLUE RGB(0x00, 0xFF, 0xFF)
#define GREEN RGB(0x00, 0xFF, 0x00)
#define RED RGB(0xFF, 0x00, 0x00)
#define YELLOW RGB(0xFF, 0xFF, 0x00)
#define PURPLE RGB(0xFF, 0x00, 0xFF)
#define BLUEGREEN RGB(0x00, 0x7B, 0x7B)
#define MIDBLUE RGB(0x00, 0x00, 0xFF)
#define DARKBLUE RGB(0x00, 0x00, 0x7F)
#define DARKGREEN RGB(0x10, 0xAF, 0x10)
#define DARKYELLOW RGB(0x7F, 0x7F, 0x00)
#define DARKRED RGB(0x7F, 0x00, 0x00)
#define DARKPURPLE RGB(0x7F, 0x00, 0x7F)
#define LIGHTBLUE RGB(0x00, 0x6F, 0xFF)

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

	enum PS5_ADT_MODES {
		PS5_ADT_NR,
		PS5_ADT_CR,
		PS5_ADT_SR,
		PS5_ADT_EF1 = 4,
		PS5_ADT_EF2 = 32,
		PS5_ADT_OFF = 5,
		PS5_ADT_NO_RES1 = 33,
		PS5_ADT_NO_RES2 = 37,
		PS5_ADT_HAS_RES1 = 34,
		PS5_ADT_HAS_RES2 = 38
	};
	
	enum Ps5AdtValue {
		RightModeValue,
		RightStartValue,
		RightForce1Value,
		RightForce2Value,
		RightStrengthLowValue,
		RightStrengthMidValue,
		RightStrengthHighValue,
		RightUnknown1Value,
		RightUnknown2Value,
		RightFreqValue,
		RightUnknown3Value,
		LeftModeValue,
		LeftStartValue,
		LeftForce1Value,
		LeftForce2Value,
		LeftStrengthLowValue,
		LeftStrengthMidValue,
		LeftStrengthHighValue,
		LeftUnknown1Value,
		LeftUnknown2Value,
		LeftFreqValue,
		LeftUnknown3Value
	};

	enum NintendoSwitch {
		SWI_HOME,
		SWI_MINUS,
		SWI_PLUS,
		SWI_R,
		SWI_ZR,
		SWI_R3,
		SWI_L,
		SWI_ZL,
		SWI_L3,
		SWI_RX,
		SWI_RY,
		SWI_LX,
		SWI_LY,
		SWI_UP,
		SWI_DOWN,
		SWI_LEFT,
		SWI_RIGHT,
		SWI_X,
		SWI_A,
		SWI_B,
		SWI_Y,
		SWI_ACCX,
		SWI_ACCY,
		SWI_ACCZ,
		SWI_GYROX,
		SWI_GYROY,
		SWI_GYROZ,
		SWI_CAPTURE
	};

	enum PlayStation3 {
		PS3_PS,
		PS3_SELECT,
		PS3_START,
		PS3_R1,
		PS3_R2,
		PS3_R3,
		PS3_L1,
		PS3_L2,
		PS3_L3,
		PS3_RX,
		PS3_RY,
		PS3_LX,
		PS3_LY,
		PS3_UP,
		PS3_DOWN,
		PS3_LEFT,
		PS3_RIGHT,
		PS3_TRIANGLE,
		PS3_CIRCLE,
		PS3_CROSS,
		PS3_SQUARE,
		PS3_ACCX,
		PS3_ACCY,
		PS3_ACCZ,
		PS3_GYRO
	};

	enum PlayStation4 {
		PS4_PS,
		PS4_SHARE,
		PS4_OPTIONS,
		PS4_R1,
		PS4_R2,
		PS4_R3,
		PS4_L1,
		PS4_L2,
		PS4_L3,
		PS4_RX,
		PS4_RY,
		PS4_LX,
		PS4_LY,
		PS4_UP,
		PS4_DOWN,
		PS4_LEFT,
		PS4_RIGHT,
		PS4_TRIANGLE,
		PS4_CIRCLE,
		PS4_CROSS,
		PS4_SQURE,
		PS4_ACCX,
		PS4_ACCY,
		PS4_ACCZ,
		PS4_GYROX,
		PS4_GYROY,
		PS4_GYROZ,
		PS4_TOUCH,
		PS4_FINGER1X,
		PS4_FINGER1Y,
		PS4_FINGER1,
		PS4_FINGER2X,
		PS4_FINGER2Y,
		PS4_FINGER2
	};

	enum PlayStation5 {
		PS5_PS,
		PS5_SHARE,
		PS5_OPTIONS,
		PS5_R1,
		PS5_R2,
		PS5_R3,
		PS5_L1,
		PS5_L2,
		PS5_L3,
		PS5_RX,
		PS5_RY,
		PS5_LX,
		PS5_LY,
		PS5_UP,
		PS5_DOWN,
		PS5_LEFT,
		PS5_RIGHT,
		PS5_TRIANGLE,
		PS5_CIRCLE,
		PS5_CROSS,
		PS5_SQURE,
		PS5_ACCX,
		PS5_ACCY,
		PS5_ACCZ,
		PS5_GYROX,
		PS5_GYROY,
		PS5_GYROZ,
		PS5_TOUCH,
		PS5_FINGER1X,
		PS5_FINGER1Y,
		PS5_FINGER1,
		PS5_FINGER2X,
		PS5_FINGER2Y,
		PS5_FINGER2
	};

	enum Xbox360 {
		XB360_XBOX,
		XB360_BACK,
		XB360_START,
		XB360_RB,
		XB360_RT,
		XB360_RS,
		XB360_LB,
		XB360_LT,
		XB360_LS,
		XB360_RX,
		XB360_RY,
		XB360_LX,
		XB360_LY,
		XB360_UP,
		XB360_DOWN,
		XB360_LEFT,
		XB360_RIGHT,
		XB360_Y,
		XB360_B,
		XB360_A,
		XB360_X
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
		XB1_PR1 = 34,
		XB1_PR2,
		XB1_PL1,
		XB1_PL2
	};
}

namespace Device
{
	enum TraceValue {
		TRACE_1,
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
		Connection_PS4Speciality,
		Connection_RefreshDevice,
		Connection_RemotePlay,
		Connection_ResetDevice,
		Connection_RunScript,
		Connection_UnloadGpc
	};

	enum DeviceState {
		Device_NotFound,
		Device_Found
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
	typedef int(WINAPI* WriteOutputTimestampProc)(void);
	typedef void(WINAPI* WriteOutputStringProc)(UINT Color, LPCSTR FormattedString);

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
	typedef int(WINAPI* GetTraceValueProc)(Device::TraceValue Value);
	typedef BYTE(WINAPI* GetPs5AdtDataProc)(Controller::Ps5AdtValue Value);

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
		GetPs5AdtDataProc			GetPs5AdtData;

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