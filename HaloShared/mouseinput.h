#pragma once

enum class MouseInputButton
{
	Left,
	Right,
	Middle,
};

enum class MouseMode
{
	None,
	UI,
	Exclusive
};

class MouseInput
{
public:
	static void SetSensitivity(float horizontalSensitivity, float verticalSensitivity);

	static float GetMouseX();
	static float GetMouseY();
	static bool GetMouseButton(MouseInputButton button);
	static void SetMode(MouseMode mode);

	static void InputWindowMessage(LPARAM lParam);
	static bool SetCursorWindowMessage(LPARAM lParam);
private:
	static MouseMode s_currentMode;
	static float s_horizontalSensitivity;
	static float s_verticalSensitivity;
	static std::atomic<uint32_t> s_xPositionAccumulator;
	static std::atomic<uint32_t> s_yPositionAccumulator;
	static std::atomic<int32_t> s_wheelAccumulator;
	static bool s_leftButtonPressed;
	static bool s_rightButtonPressed;
	static bool s_middleButtonPressed;
	static bool s_button4Pressed;
	static bool s_button5Pressed;
};

