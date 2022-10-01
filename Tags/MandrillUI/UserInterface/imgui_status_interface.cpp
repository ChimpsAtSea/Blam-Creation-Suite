#include "mandrillui-private-pch.h"

#include <windows.h>

c_imgui_status_interface::c_imgui_status_interface() :
	text_status_bar_state(),
	status("Ready"),
	status_ui_copy("Ready"),
	percentage_status_bar_state(),
	percentage(-1.0f),
	percentage_copy(-1.0f),
	end_time(INFINITY),
	priority(_status_interface_priority_low)
{

}

float c_imgui_status_interface::get_status_bar_percentage()
{
	if (percentage_status_bar_state == 2 && atomic_cmpxchgu32(&percentage_status_bar_state, 1, 2) == 2)
	{
		percentage_copy = percentage;
		atomic_xchgu32(&percentage_status_bar_state, 0);
	}
	return percentage_copy;
}

const char* c_imgui_status_interface::get_status_bar_text()
{
	double remaining_time = end_time - ImGui::GetTime();
	if (remaining_time < 0)
	{
		if (text_status_bar_state == 0 && atomic_cmpxchgu32(&text_status_bar_state, 1, 0) == 0)
		{
			strcpy(status, "Ready");
			end_time = INFINITY;
			priority = _status_interface_priority_low;
			atomic_xchgu32(&text_status_bar_state, 2);
		}
	}
	if (text_status_bar_state == 2 && atomic_cmpxchgu32(&text_status_bar_state, 1, 2) == 2)
	{
		strcpy(status_ui_copy, status);
		atomic_xchgu32(&text_status_bar_state, 0);
	}
	return status_ui_copy;
}

void c_imgui_status_interface::set_status_bar_status(e_status_interface_priority target_priority, float time, const char* _status, ...)
{
	if (target_priority <= priority)
	{
		if (text_status_bar_state == 0 && atomic_cmpxchgu32(&text_status_bar_state, 1, 0) == 0)
		{
			va_list list;
			va_start(list, _status);
			vsnprintf(status, _countof(status), _status, list);
			va_end(list);
			end_time = ImGui::GetTime() + time;
			priority = target_priority;
			atomic_xchgu32(&text_status_bar_state, 2);
		}
	}
}

void c_imgui_status_interface::set_status_bar_load_percentage(float _percentage)
{
	if (percentage_status_bar_state == 0 && atomic_cmpxchgu32(&percentage_status_bar_state, 1, 0) == 0)
	{
		percentage = _percentage;
		atomic_xchgu32(&percentage_status_bar_state, 2);
	}
}

void c_imgui_status_interface::clear_status_bar_load_percentage()
{
	set_status_bar_load_percentage(-1.0f);
}

void c_imgui_status_interface::wait_status_bar_idle()
{
	while (text_status_bar_state != 0);
	while (percentage_status_bar_state != 0);
}

