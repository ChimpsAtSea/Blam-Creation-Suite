#pragma once

class c_imgui_status_interface :
	public c_status_interface
{
public:
	c_imgui_status_interface();

	virtual float get_status_bar_percentage() override;
	virtual const char* get_status_bar_text() override;
	virtual void set_status_bar_status(e_status_interface_priority priority, float time, const char* status, ...) override;
	virtual void set_status_bar_load_percentage(float percentage) override;
	virtual void clear_status_bar_load_percentage()  override;
	virtual void wait_status_bar_idle() override;

protected:
	uint32_t text_status_bar_state;
	char status[128];
	char status_ui_copy[128];
	uint32_t percentage_status_bar_state;
	float percentage;
	float percentage_copy;
	double end_time;
	uint32_t priority;
};
