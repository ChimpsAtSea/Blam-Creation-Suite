#include "mandrillui-private-pch.h"

#include <mutex>
static std::mutex mutex; // #TODO: replace

c_imgui_status_interface::c_imgui_status_interface() :
	status("Ready"),
	status_ui_copy("Ready"),
	end_time(INFINITY),
	priority(_status_interface_priority_low)
{

}

const char* c_imgui_status_interface::get_status_bar_text()
{
	mutex.lock();
	double remaining_time = end_time - ImGui::GetTime();
	if (remaining_time < 0)
	{
		status = "Ready";
		end_time = INFINITY;
		priority = _status_interface_priority_low;
	}
	status_ui_copy = status;
	mutex.unlock();
	return status_ui_copy;
}

void c_imgui_status_interface::set_status_bar_status(e_status_interface_priority priority, float time, const char* _status, ...)
{
	if (priority <= priority)
	{
		mutex.lock();
		va_list list;
		va_start(list, _status);
		status.vformat(_status, list);
		va_end(list);
		end_time = ImGui::GetTime() + time;
		priority = priority;
		mutex.unlock();
	}
}
