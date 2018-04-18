#include <Windows.h>
#include <iostream>

#include "Values.h"
#include "Thread.h"
#include "Utils.h"

int main()
{
	SetConsoleTitle(L"AutoFarmer | Made by SendPacket");
	std::cout << "Welcome to the AutoFarmer!" << std::endl;
	std::cout << "Loading..." << std::endl;
	Sleep(1000);

	Values::break_time = 25;

	while (!Values::window_hwnd)
	{
		system("cls");
		std::cout << "Searching window..." << std::endl;
		Values::window_hwnd = FindWindowA(NULL, "Growtopia");
		Sleep(100);
	}

	if (Values::window_hwnd)
	{
		Utils::update_console_text();
		while (true)
		{
			Thread::Update();
		}
	}

	std::cout << "exit" << std::endl;

	Sleep(1000);

	return 0;
}