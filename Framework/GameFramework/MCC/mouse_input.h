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
	static void set_sensitivity(float horizontal_sensitivity, float vertical_sensitivity);
	static ImVec2 get_sensitivity();

	static float get_mouse_x();
	static float get_mouse_y();
	static bool get_mouse_button(e_mouse_input_button button);
	static void set_mode(e_mouse_mode mode);

	static void handle_input_window_message(LPARAM lParam);
	static bool handle_cursor_window_message(LPARAM lParam);
private:
	static void set_clip_mode(e_mouse_mode mode);

	static e_mouse_mode s_current_mode;
	static float s_horizontal_sensitivity;
	static float s_vertical_sensitivity;
	static std::atomic<int32_t> s_x_position_accumulator;
	static std::atomic<int32_t> s_y_position_accumulator;
	static std::atomic<int32_t> s_wheel_accumulator;
	static bool s_left_button_pressed;
	static bool s_right_button_pressed;
	static bool s_middle_button_pressed;
	static bool s_button4_pressed;
	static bool s_button5_pressed;
};

