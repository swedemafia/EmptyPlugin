#ifndef EMULATORAPIMANAGER_H
#define EMULATORAPIMANAGER_H
#pragma once

class EmulatorAPIManager
{
	friend BOOL WINAPI PluginMain(PluginAPI::PluginInformation* Information);
	// PluginMain may set the private variables (proc addresses)

private:

	PluginAPI::ProcessConsoleCommandProc	m_ProcessConsoleCommand;
	PluginAPI::RefreshUserInputProc			m_RefreshUserInput;
	PluginAPI::ResetCursorPositionProc		m_ResetCursorPosition;
	PluginAPI::SetOutputColorProc			m_SetOutputColor;
	PluginAPI::WriteOutputStringProc		m_WriteOutputString;
	PluginAPI::WriteOutputTimestampProc		m_WriteOutputTimestamp;
	PluginAPI::GetCpuLoadValueProc			m_GetCpuLoadValue;
	PluginAPI::GetSlotValueProc				m_GetSlotValue;
	PluginAPI::GetConnectedControllerProc	m_GetConnectedController;
	PluginAPI::GetConnectedConsoleProc		m_GetConnectedConsole;
	PluginAPI::GetLedStateProc				m_GetLedState;
	PluginAPI::GetRumbleProc				m_GetRumble;
	PluginAPI::GetBatteryValueProc			m_GetBatteryValue;
	PluginAPI::GetInputValueProc			m_GetInputValue;
	PluginAPI::GetVmSpeedValueProc			m_GetVmSpeedValue;

public:

	BOOL ProcessConsoleCommand(LPCSTR CommandString) {
		return m_ProcessConsoleCommand(CommandString);
	}

	int RefreshUserInput(void) {
		return m_RefreshUserInput();
	}

	BOOL ResetCursorPosition(void) {
		return m_ResetCursorPosition();
	}

	BOOL SetOutputColor(PluginAPI::OutputColor Color) {
		return m_SetOutputColor(Color);
	}

	int WriteOutputString(LPCSTR String) {
		return m_WriteOutputString(String);
	}

	int WriteOutputTimestamp(void) {
		return m_WriteOutputTimestamp();
	}

	WORD GetCpuLoadValue(void) {
		return m_GetCpuLoadValue();
	}

	BYTE GetSlotValue(void) {
		return m_GetSlotValue();
	}

	PluginAPI::ControllerType GetConnectedController(void) {
		return m_GetConnectedController();
	}

	PluginAPI::ConsoleType GetConnectedConsole(void) {
		return m_GetConnectedConsole();
	}

	BYTE GetLedState(BYTE Index) {
		return m_GetLedState(Index);
	}

	BYTE GetRumble(PluginAPI::RumbleValue Rumble) {
		return m_GetRumble(Rumble);
	}

	BYTE GetBatteryValue(void) {
		return m_GetBatteryValue();
	}

	char GetInputValue(BYTE Input) {
		return m_GetInputValue(Input);
	}

	BYTE GetVmSpeedValue(void) {
		return m_GetVmSpeedValue();
	}
};

#endif
