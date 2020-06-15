#pragma once

enum e_mouse_input_button
{
	_mouse_input_button_left,
	_mouse_input_button_right,
	_mouse_input_button_middle,
};

enum e_mouse_mode
{
	_mouse_mode_none,
	_mouse_mode_ui,
	_mouse_mode_exclusive
};

class c_mouse_input
{
public:
	c_mouse_input(c_window& window);
	~c_mouse_input();

	void set_sensitivity(float horizontal_sensitivity, float vertical_sensitivity);
	ImVec2 get_sensitivity();

	float get_mouse_x();
	float get_mouse_y();
	bool get_mouse_button(e_mouse_input_button button);
	void set_mode(e_mouse_mode mode);

	void handle_input_window_message(LPARAM lParam);
	bool handle_cursor_window_message(LPARAM lParam);

private:
	void set_clip_mode(e_mouse_mode mode);

	c_window& window;
	e_mouse_mode s_current_mode;
	float s_horizontal_sensitivity;
	float s_vertical_sensitivity;
	std::atomic<int32_t> s_x_position_accumulator;
	std::atomic<int32_t> s_y_position_accumulator;
	std::atomic<int32_t> s_wheel_accumulator;
	bool s_left_button_pressed;
	bool s_right_button_pressed;
	bool s_middle_button_pressed;
	bool s_button4_pressed;
	bool s_button5_pressed;
};

