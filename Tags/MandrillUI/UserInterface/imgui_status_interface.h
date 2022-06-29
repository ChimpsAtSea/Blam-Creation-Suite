#pragma once

class c_imgui_status_interface :
	public c_status_interface
{
public:
	c_imgui_status_interface();

	virtual const char* get_status_bar_text() override;
	virtual void set_status_bar_status(e_status_interface_priority priority, float time, const char* status, ...) override;
	virtual void wait_status_bar_idle() override;

protected:
	char status[128];
	char status_ui_copy[128];
	double end_time;
	unsigned long priority;
};
