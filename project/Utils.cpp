#include "Utils.h"
#include "Values.h"

#include <iostream>

POINT Utils::get_mouse_point()
{
	POINT p;
	GetCursorPos(&p);
	ScreenToClient(Values::window_hwnd, &p);
	return p;
}

void Utils::mouse_left_click(int x, int y)
{
	SendMessage(Values::window_hwnd, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(x, y));
	SendMessage(Values::window_hwnd, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(x, y));
}

void Utils::update_console_text()
{
	system("cls");
	std::cout << "F5: Set the position of the item that you want to place." << std::endl;
	std::cout << "F6: Set the position of the hand." << std::endl;
	std::cout << "F7: Set the first position where the item is going to be placed." << std::endl;
	std::cout << "F8: Set the second position where the item is going to be placed." << std::endl;
	std::cout << "F9: Decrease break time." << std::endl;
	std::cout << "F10: Increase break time." << std::endl;
	std::cout << "F12: Enable or disable the AutoFarmer." << std::endl;
	std::cout << "BreakTime: " << Values::break_time << std::endl;
	std::cout << "AutoFarmer: " << (Values::running ? "ON" : "OFF") << std::endl;
}