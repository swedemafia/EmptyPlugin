#ifndef EMULATORAPIMANAGER_H
#define EMULATORAPIMANAGER_H
#pragma once

class EmulatorAPIManager
{
	friend BOOL WINAPI PluginMain(PluginAPI::PluginInformation* Information);
	// PluginMain may set the private variables (proc addresses)

private:

	// UI:
	PluginAPI::ProcessConsoleCommandProc	m_ProcessConsoleCommand;
	PluginAPI::RefreshUserInputProc			m_RefreshUserInput;
	PluginAPI::ResetCursorPositionProc		m_ResetCursorPosition;
	PluginAPI::SetOutputColorProc			m_SetOutputColor;
	PluginAPI::WriteOutputStringProc		m_WriteOutputString;
	PluginAPI::WriteOutputTimestampProc		m_WriteOutputTimestamp;

	// Actions:
	PluginAPI::EventPressProc				m_EventPress;
	PluginAPI::EventReleaseProc				m_EventRelease;

	// Controller:
	PluginAPI::GetBatteryValueProc			m_GetBatteryValue;
	PluginAPI::GetInputValueProc			m_GetInputValue;
	PluginAPI::GetLastInputValueProc		m_GetLastInputValue;
	PluginAPI::GetOutputValueProc			m_GetOutputValue;
	PluginAPI::GetPs5AdtDataProc			m_GetPs5AdtData;
	PluginAPI::GetPressTimeProc				m_GetPressTime;
	PluginAPI::GetReleaseTimeProc			m_GetReleaseTime;
	PluginAPI::GetRumbleProc				m_GetRumble;

	// Device:
	PluginAPI::GetConnectedConsoleProc		m_GetConnectedConsole;
	PluginAPI::GetConnectedControllerProc	m_GetConnectedController;
	PluginAPI::GetCpuLoadValueProc			m_GetCpuLoadValue;
	PluginAPI::GetLedStateProc				m_GetLedState;
	PluginAPI::GetSlotValueProc				m_GetSlotValue;
	PluginAPI::GetTraceValueProc			m_GetTraceValue;
	PluginAPI::GetVmSpeedValueProc			m_GetVmSpeedValue;

public:

	// UI:
	BOOL ProcessConsoleCommand(LPCSTR CommandString) {
		return m_ProcessConsoleCommand(CommandString);
	}

	int RefreshUserInput(void) {
		return m_RefreshUserInput();
	}

	BOOL ResetCursorPosition(void) {
		return m_ResetCursorPosition();
	}

	BOOL SetOutputColor(Emulator::OutputColor Color) {
		return m_SetOutputColor(Color);
	}

	int WriteOutputString(LPCSTR String) {
		return m_WriteOutputString(String);
	}

	int WriteOutputTimestamp(void) {
		return m_WriteOutputTimestamp();
	}

	// Actions:
	BOOL EventPress(BYTE Identifier) {
		return m_EventPress(Identifier);
	}

	BOOL EventRelease(BYTE Identifier) {
		return m_EventRelease(Identifier);
	}

	// Controller:
	BYTE GetBatteryValue(void) {
		return m_GetBatteryValue();
	}

	char GetInputValue(BYTE Identifier) {
		return m_GetInputValue(Identifier);
	}

	char GetLastInputValue(BYTE Identifier) {
		return m_GetLastInputValue(Identifier);
	}

	char GetOutputValue(BYTE Identifier) {
		return m_GetOutputValue(Identifier);
	}

	BYTE GetPs5AdtData(Controller::Ps5AdtValue Value) {
		return m_GetPs5AdtData(Value);
	}

	DWORD GetPressTime(BYTE Identifier) {
		return m_GetPressTime(Identifier);
	}

	DWORD GetReleaseTime(BYTE Identifier) {
		return m_GetReleaseTime(Identifier);
	}

	BYTE GetRumble(Controller::Rumble Rumble) {
		return m_GetRumble(Rumble);
	}

	// Device:
	Console::Type GetConnectedConsole(void) {
		return m_GetConnectedConsole();
	}

	Controller::Type GetConnectedController(void) {
		return m_GetConnectedController();
	}

	WORD GetCpuLoadValue(void) {
		return m_GetCpuLoadValue();
	}

	BYTE GetLedState(BYTE Index) {
		return m_GetLedState(Index);
	}

	BYTE GetSlotValue(void) {
		return m_GetSlotValue();
	}

	int GetTraceValue(Device::TraceValue Value) {
		return m_GetTraceValue(Value);
	}

	BYTE GetVmSpeedValue(void) {
		return m_GetVmSpeedValue();
	}
};

#endif
