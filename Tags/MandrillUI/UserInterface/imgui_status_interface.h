#pragma once

class c_imgui_status_interface :
	public c_status_interface
{
public:
	c_imgui_status_interface();

	virtual const char* get_status_bar_text() override;
	virtual void set_status_bar_status(e_status_interface_priority priority, float time, const char* status, ...) override;

protected:
	c_fixed_string_128 status;
	c_fixed_string_128 status_ui_copy;
	double end_time;
	unsigned long priority;
};
