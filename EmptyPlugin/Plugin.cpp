#include "PCH.h"

DWORD WINAPI PluginThread(LPVOID Parameter)
{
	// TODO: Reevaluate this loop condition
	while (1) {

		/* Add your code here */

		// Sample code:

		if (API.EventPress(Controller::XB1_RT))

			if (API.GetInputValue(Controller::XB1_LT))
				PluginInstance.WriteFormattedOutput(Emulator::Yellow, "ADS held & Fire pressed!\r\n");
			else
				PluginInstance.WriteFormattedOutput(Emulator::Yellow, "RT pressed; last release was %dms ago!\r\n", API.GetReleaseTime(Controller::XB1_RT));
		
		else if (API.EventRelease(Controller::XB1_RT))
			PluginInstance.WriteFormattedOutput(Emulator::Yellow, "RT released; was held for %dms!\r\n", API.GetPressTime(Controller::XB1_RT));
	}

	return 0;
}

BOOL Plugin::Initialize(void)
{
	// Create the main loop that can process controller input/output
	PluginAPI::Thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)PluginThread, (LPVOID)this, 0, NULL);

	// Confirm the thread was created
	if (PluginAPI::Thread == INVALID_HANDLE_VALUE)
		return FALSE;

	/* Add any initialization code below here (return TRUE if successful, FALSE if not) */

	return TRUE;
}

void Plugin::Terminate(void)
{
	// Close the PluginThread handle
	if (PluginAPI::Thread != INVALID_HANDLE_VALUE)
		CloseHandle(PluginAPI::Thread);

	/* Add any termination code here */

}

// Command Hook
BOOL Plugin::CommandHook(LPCSTR CommandString)
{
	// Process a console command (if it is not an internal command to the host)

	/* Add code here (return TRUE if processed, FALSE if not) */

	return FALSE;
}

// Connection hook
void Plugin::ConnectionHook(Emulator::ConnectionState EventCode)
{
	// Called upon changes in the connection state

	/* Add code here */

	return;
}

// Device Hook
void Plugin::DeviceHook(Emulator::DeviceState EventCode)
{
	// Called when the target device is found or not found to be connected to the system

	/* Add code here */

	return;
}

// Mesasge Hook
void Plugin::MessageHook(BYTE PacketID, WORD PayloadSize, BYTE* Payload)
{
	// Called when a complete packet is received from the device

	/* Add code here */

	return;
}

// Included user function for printing colored & formatted text to console window
// This function does not need to be modified
void Plugin::WriteFormattedOutput(Emulator::OutputColor Color, LPCSTR Format, ...)
{
	API.ResetCursorPosition(); // Reset cursor position
	API.WriteOutputTimestamp(); // Write timestamp
	API.SetOutputColor(Color); // Set output color

	va_list arg_ptr;

	// Print the formatted string to the console
	va_start(arg_ptr, Format);
	vprintf(Format, arg_ptr);
	va_end(arg_ptr);

	API.RefreshUserInput(); // Display the greater-than symbol with any unprocessed user input
}