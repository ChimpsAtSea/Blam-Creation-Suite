#include "mandrillui-private-pch.h"

#include <windows.h>
unsigned long status_bar_state;

c_imgui_status_interface::c_imgui_status_interface() :
	status("Ready"),
	status_ui_copy("Ready"),
	end_time(INFINITY),
	priority(_status_interface_priority_low)
{

}

const char* c_imgui_status_interface::get_status_bar_text()
{
	double remaining_time = end_time - ImGui::GetTime();
	if (remaining_time < 0)
	{
		if (status_bar_state == 0 && InterlockedCompareExchange(&status_bar_state, 1, 0) == 0)
		{
			strcpy(status, "Ready");
			end_time = INFINITY;
			priority = _status_interface_priority_low;
			InterlockedExchange(&status_bar_state, 2);
		}
	}
	if (status_bar_state == 2 && InterlockedCompareExchange(&status_bar_state, 1, 2) == 2)
	{
		strcpy(status_ui_copy, status);
		InterlockedExchange(&status_bar_state, 0);
	}
	return status_ui_copy;
}

void c_imgui_status_interface::set_status_bar_status(e_status_interface_priority target_priority, float time, const char* _status, ...)
{
	if (target_priority <= priority)
	{
		if (status_bar_state == 0 && InterlockedCompareExchange(&status_bar_state, 1, 0) == 0)
		{
			va_list list;
			va_start(list, _status);
			vsnprintf(status, _countof(status), _status, list);
			va_end(list);
			end_time = ImGui::GetTime() + time;
			priority = target_priority;
			InterlockedExchange(&status_bar_state, 2);
		}
	}
}

void c_imgui_status_interface::wait_status_bar_idle()
{
	while (status_bar_state != 0);
}

