#include <iostream>
#include <Windows.h>


/*
How to create a console application without console?
	1. Choose the application name "QuickShortcut" in solution explorer. 
	2. Using shortcut ALT + ENTER or right click it to open project property page "QuickShortcut Property Page".
	3. Configuration Properties --> Linker --> Systerm --> Subsysterm:
		select: Windows (/SUBSYSTEM:WINDOWS)
	4. Configuration Properties --> Linker --> All Options:
		search: Entry Point, set its value to mainCRTStartup
	* It is noteworthy that don't choose the solution name "Solution 'QuickShortcut'" at step 1,  you would open 
	the solution property page otherwise, which would make you can't find these switches of step 3 and 4.

linker properties: 
	subsystem: windows
	entry: mainCRTStartup
*/

class Shortcuts {
private:
	//Left Windows key (Natural keyboard)
	int virtualKeyCode_LeftWindows = 0x5B;
	int virtualKeyCode_LeftShift = 0xA0;
	int virtualKeyCode_Ctrl = 0x11;
	int virtualKeyCode_Alt = 0x12;
	int virtualKeyCode_C = 0x43;
	int virtualKeyCode_S = 0x53;
	int virtualKeyCode_V = 0x56;

public:
	void SnippingTool() {
		keybd_event(this->virtualKeyCode_LeftWindows, 0, 0, 0);
		keybd_event(this->virtualKeyCode_LeftShift, 0, 0, 0);
		keybd_event(this->virtualKeyCode_S, 0, 0, 0);
		keybd_event(this->virtualKeyCode_LeftWindows, 0, KEYEVENTF_KEYUP, 0);
		keybd_event(this->virtualKeyCode_LeftShift, 0, KEYEVENTF_KEYUP, 0);
		keybd_event(this->virtualKeyCode_S, 0, KEYEVENTF_KEYUP, 0);
	}

	void Copy() {
		keybd_event(this->virtualKeyCode_Ctrl, 0, 0, 0);
		keybd_event(this->virtualKeyCode_C, 0, 0, 0);
		keybd_event(this->virtualKeyCode_Ctrl, 0, KEYEVENTF_KEYUP, 0);
		keybd_event(this->virtualKeyCode_C, 0, KEYEVENTF_KEYUP, 0);
	}

	void Paste() {
		keybd_event(this->virtualKeyCode_Ctrl, 0, 0, 0);
		keybd_event(this->virtualKeyCode_V, 0, 0, 0);
		keybd_event(this->virtualKeyCode_Ctrl, 0, KEYEVENTF_KEYUP, 0);
		keybd_event(this->virtualKeyCode_V, 0, KEYEVENTF_KEYUP, 0);
	}
};


int main()
{
	Shortcuts shortcuts;
	shortcuts.SnippingTool();
}