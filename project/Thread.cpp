#include "Thread.h"

#include <Windows.h>
#include <iostream>
#include "Utils.h"
#include "Values.h"

#include <chrono>

void Thread::UpdateBot()
{
	if (GetAsyncKeyState(VK_F9) && !GetAsyncKeyState(VK_F10))
	{
		if (Values::break_time >= 25)
		{
			Values::break_time -= 25;
			Utils::update_console_text();
			Sleep(100);
		}
	}
	if (GetAsyncKeyState(VK_F10) && !GetAsyncKeyState(VK_F9))
	{
		Values::break_time += 25;
		Utils::update_console_text();
		Sleep(100);
	}

	if (Values::running != GetKeyState(VK_F12))
	{
		Values::running = GetKeyState(VK_F12);
		Utils::update_console_text();
	}

	if (Values::running)
	{
		Utils::mouse_left_click(Values::seeds_point.x, Values::seeds_point.y);
		Sleep(100);
		Utils::mouse_left_click(Values::place_point_2.x, Values::place_point_2.y);
		Sleep(100);
		Utils::mouse_left_click(Values::place_point_1.x, Values::place_point_1.y);
		Sleep(100);
		Utils::mouse_left_click(Values::fist_point.x, Values::fist_point.y);
		while(Values::ms_timer < (Values::break_time / 1000.f))
		{
			Values::ms_timer += 0.03f;
			Utils::mouse_left_click(Values::place_point_1.x, Values::place_point_1.y);
		}
		Values::ms_timer = 0;
		while (Values::ms_timer < (Values::break_time / 1000.f))
		{
			Values::ms_timer += 0.03;
			Utils::mouse_left_click(Values::place_point_2.x, Values::place_point_2.y);
		}
		Values::ms_timer = 0;
	}
}

void Thread::UpdateBindings()
{
	POINT p = Utils::get_mouse_point();
	if (GetAsyncKeyState(VK_F5))
	{
		if (Values::seeds_point.x != p.x || Values::seeds_point.y != p.y)
		{
			system("cls");
			std::cout << "[Block] point set (" << p.x << "," << p.y << ")" << std::endl;
			Values::seeds_point.x = p.x;
			Values::seeds_point.y = p.y;
			Sleep(500);
			Utils::update_console_text();
		}
	}
	else {
		if (GetAsyncKeyState(VK_F6))
		{
			if (Values::fist_point.x != p.x || Values::fist_point.y != p.y)
			{
				system("cls");
				std::cout << "[Hand] point set (" << p.x << "," << p.y << ")" << std::endl;
				Values::fist_point.x = p.x;
				Values::fist_point.y = p.y;
				Sleep(500);
				Utils::update_console_text();
			}
		}
		else {
			if (GetAsyncKeyState(VK_F7))
			{
				if (Values::place_point_1.x != p.x || Values::place_point_1.y != p.y)
				{
					system("cls");
					std::cout << "[Place1] point set (" << p.x << "," << p.y << ")" << std::endl;
					Values::place_point_1.x = p.x;
					Values::place_point_1.y = p.y;
					Sleep(500);
					Utils::update_console_text();
				}
			}
			else {
				if (GetAsyncKeyState(VK_F8))
				{
					if (Values::place_point_2.x != p.x || Values::place_point_2.y != p.y)
					{
						system("cls");
						std::cout << "[Place2] point set (" << p.x << "," << p.y << ")" << std::endl;
						Values::place_point_2.x = p.x;
						Values::place_point_2.y = p.y;
						Sleep(500);
						Utils::update_console_text();
					}
				}
			}
		}
	}
}

void Thread::Update()
{
	UpdateBot();
	UpdateBindings();
}