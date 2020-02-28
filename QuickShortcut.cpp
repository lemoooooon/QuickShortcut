#include <iostream>
#include <Windows.h>


/*
How to create a console application without console?
	1. Select the application name "QuickShortcut" in solution explorer. 
	2. Using shortcut ALT + ENTER or right click it to open project property page "QuickShortcut Property Page".
	3. Configuration Properties --> Linker --> Systerm --> Subsysterm:
		select: Windows (/SUBSYSTEM:WINDOWS)
	4. Configuration Properties --> Linker --> All Options:
		search: Entry Point, set its value to mainCRTStartup
	* It is noteworthy that don't select the solution name "Solution 'QuickShortcut'" at step 1,  you would open 
	the solution property page otherwise, which would make you can't find these switches of step 3 and 4.
#pragma comment( linker, "/subsystem:windows /entry:mainCRTStartup" )
*/


int main()
{
	keybd_event(91, 0, 0, 0);
	keybd_event(16, 0, 0, 0);
	keybd_event(83, 0, 0, 0);
	keybd_event(91, 0, KEYEVENTF_KEYUP, 0);
	keybd_event(16, 0, KEYEVENTF_KEYUP, 0);
	keybd_event(83, 0, KEYEVENTF_KEYUP, 0);
}