#pragma once

#include <Windows.h>

namespace Utils
{
	POINT get_mouse_point();
	
	void mouse_left_click(int x, int y);

	void update_console_text();
}