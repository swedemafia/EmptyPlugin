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

};

#endif
