#include "opusframework-private-pch.h"

float c_mouse_input::s_horizontal_sensitivity = 1.0f;
float c_mouse_input::s_vertical_sensitivity = 1.0f;
e_mouse_mode c_mouse_input::s_current_mode;
std::atomic<int32_t> c_mouse_input::s_x_position_accumulator = 0;
std::atomic<int32_t> c_mouse_input::s_y_position_accumulator = 0;
std::atomic<int32_t> c_mouse_input::s_wheel_accumulator = 0;
bool c_mouse_input::s_left_button_pressed = false;
bool c_mouse_input::s_right_button_pressed = false;
bool c_mouse_input::s_middle_button_pressed = false;
bool c_mouse_input::s_button4_pressed = false;
bool c_mouse_input::s_button5_pressed = false;

void c_mouse_input::handle_input_window_message(LPARAM lParam)
{
	RAWINPUT raw_input = {};
	UINT raw_input_size = sizeof(raw_input);
	UINT get_raw_input_data_result = GetRawInputData(reinterpret_cast<HRAWINPUT>(lParam), RID_INPUT, &raw_input, &raw_input_size, sizeof(RAWINPUTHEADER));
	ASSERT(get_raw_input_data_result != ~0u);

	if (get_raw_input_data_result)
	{
		switch (raw_input.header.dwType)
		{
		case RIM_TYPEMOUSE:
		{
			RAWMOUSE& rRawMouse = raw_input.data.mouse;
			if (s_current_mode == _mouse_mode_exclusive)
			{
				if (rRawMouse.usFlags == MOUSE_MOVE_RELATIVE)
				{
					int x_position_relative = rRawMouse.lLastX;
					int y_position_relative = rRawMouse.lLastY;
					s_x_position_accumulator += x_position_relative;
					s_y_position_accumulator += y_position_relative;
				}

				if (rRawMouse.usButtonFlags & RI_MOUSE_WHEEL)
				{
					SHORT wheelDelta = static_cast<SHORT>(rRawMouse.usButtonData);
					s_wheel_accumulator += static_cast<int32_t>(wheelDelta);
				}

				if (rRawMouse.usButtonFlags & RI_MOUSE_LEFT_BUTTON_DOWN)
				{
					s_left_button_pressed = true;
				}
				if (rRawMouse.usButtonFlags & RI_MOUSE_LEFT_BUTTON_UP)
				{
					s_left_button_pressed = false;
				}
				if (rRawMouse.usButtonFlags & RI_MOUSE_RIGHT_BUTTON_DOWN)
				{
					s_right_button_pressed = true;
				}
				if (rRawMouse.usButtonFlags & RI_MOUSE_RIGHT_BUTTON_UP)
				{
					s_right_button_pressed = false;
				}
				if (rRawMouse.usButtonFlags & RI_MOUSE_MIDDLE_BUTTON_DOWN)
				{
					s_middle_button_pressed = true;
				}
				if (rRawMouse.usButtonFlags & RI_MOUSE_MIDDLE_BUTTON_UP)
				{
					s_middle_button_pressed = false;
				}
				if (rRawMouse.usButtonFlags & RI_MOUSE_BUTTON_4_DOWN)
				{
					s_button4_pressed = true;
				}
				if (rRawMouse.usButtonFlags & RI_MOUSE_BUTTON_4_UP)
				{
					s_button4_pressed = false;
				}
				if (rRawMouse.usButtonFlags & RI_MOUSE_BUTTON_5_DOWN)
				{
					s_button5_pressed = true;
				}
				if (rRawMouse.usButtonFlags & RI_MOUSE_BUTTON_5_UP)
				{
					s_button5_pressed = false;
				}
			}
		}
		break;
		}
	}
}

bool c_mouse_input::handle_cursor_window_message(LPARAM lParam)
{
	if (LOWORD(lParam) == HTCLIENT)
	{
		static HCURSOR hand_cursor_handle = LoadCursor(NULL, IDC_ARROW);
		switch (s_current_mode)
		{
		case _mouse_mode_exclusive:
			SetCursor(NULL);
			break;
		default:
			SetCursor(hand_cursor_handle);
			break;
		}
		return true;
	}
	return false;
}

void c_mouse_input::set_clip_mode(e_mouse_mode mode)
{
	if (mode == _mouse_mode_exclusive)
	{
		HWND window_handle = c_window_win32::get_window_handle();
		RECT window_rectangle = {};
		GetClientRect(window_handle, &window_rectangle);
		POINT upper_left;
		upper_left.x = window_rectangle.left;
		upper_left.y = window_rectangle.top;
		POINT lower_right;
		lower_right.x = window_rectangle.right;
		lower_right.y = window_rectangle.bottom;
		MapWindowPoints(window_handle, nullptr, &upper_left, 1);
		MapWindowPoints(window_handle, nullptr, &lower_right, 1);
		window_rectangle.left = upper_left.x;
		window_rectangle.top = upper_left.y;
		window_rectangle.right = lower_right.x;
		window_rectangle.bottom = lower_right.y;
		ClipCursor(&window_rectangle);
	}
	else
	{
		ClipCursor(NULL);
	}
}

void c_mouse_input::set_mode(e_mouse_mode mode)
{
	if (s_current_mode != mode)
	{
		s_current_mode = mode;
		set_clip_mode(mode);
	}
}

void c_mouse_input::set_sensitivity(float horizontal_sensitivity, float vertical_sensitivity)
{
	s_horizontal_sensitivity = __max(horizontal_sensitivity, 0.0f);
	s_vertical_sensitivity = __max(vertical_sensitivity, 0.0f);

	if (s_horizontal_sensitivity > 1.0f) s_horizontal_sensitivity = 1.0f;
	if (s_vertical_sensitivity > 1.0f) s_vertical_sensitivity = 1.0f;
	if (s_horizontal_sensitivity < 0.0f) s_horizontal_sensitivity = 0.0f;
	if (s_vertical_sensitivity < 0.0f) s_vertical_sensitivity = 0.0f;
}

ImVec2 c_mouse_input::get_sensitivity()
{
	return ImVec2(s_horizontal_sensitivity, s_vertical_sensitivity);
}

float c_mouse_input::get_mouse_x()
{
	int relative_ticks_x = s_x_position_accumulator.exchange(0);
	return float(relative_ticks_x) * 0.005f * s_horizontal_sensitivity;
}

float c_mouse_input::get_mouse_y()
{
	int relative_ticks_y = s_y_position_accumulator.exchange(0);
	return float(relative_ticks_y) * 0.005f * s_horizontal_sensitivity;
}

bool c_mouse_input::get_mouse_button(e_mouse_input_button button)
{
	switch (button)
	{
	case _mouse_input_button_left:
		return s_left_button_pressed;
	case _mouse_input_button_right:
		return s_right_button_pressed;
	case _mouse_input_button_middle:
		return s_middle_button_pressed;
	}
	return false;
}
