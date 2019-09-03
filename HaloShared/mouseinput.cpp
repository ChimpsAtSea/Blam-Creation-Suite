#include "haloshared-private-pch.h"

float MouseInput::s_horizontalSensitivity = 1.0f;
float MouseInput::s_verticalSensitivity = 1.0f;
IDirectInput8* MouseInput::m_pDirectInput8;
IDirectInputDevice8* MouseInput::m_pDirectInput8Mouse;
DIMOUSESTATE2 MouseInput::s_mouseState2 = {};
std::atomic<DWORD> MouseInput::s_currentAcquireMode = 0;
DWORD MouseInput::s_targetAcquireMode = 0;

void MouseInput::SetExclusiveMode(bool isExclusive)
{
	if (isExclusive)
	{
		s_targetAcquireMode = DISCL_FOREGROUND | DISCL_EXCLUSIVE;
	}
	else
	{
		s_targetAcquireMode = DISCL_BACKGROUND | DISCL_NONEXCLUSIVE;
	}
}

void MouseInput::Acquire()
{
	if (s_currentAcquireMode != s_targetAcquireMode)
	{
		if (s_currentAcquireMode)
		{
			HRESULT UnacquireResult = m_pDirectInput8Mouse->Unacquire();
			s_currentAcquireMode = 0;
		}

		//// Set the cooperative level of the mouse to share with other programs.
		HWND hWnd = CustomWindow::GetWindowHandle();
		HRESULT SetCooperativeLevelResult = m_pDirectInput8Mouse->SetCooperativeLevel(hWnd, s_targetAcquireMode);
		assert(!FAILED(SetCooperativeLevelResult));

		// Acquire the mouse.
		HRESULT AcquireResult = m_pDirectInput8Mouse->Acquire();
		//assert(!FAILED(AcquireResult)); // it is okay to fail here, as we'll try again each frame

		if (!FAILED(AcquireResult))
		{
			s_currentAcquireMode = s_targetAcquireMode;
		}
		else
		{
			s_currentAcquireMode = 0;
		}
	}
}

void MouseInput::Init(HINSTANCE hInstance)
{
	assert(m_pDirectInput8 == nullptr);
	assert(m_pDirectInput8Mouse == nullptr);

	SetExclusiveMode(true);

	HRESULT DirectInput8CreateResult = DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (LPVOID*)& m_pDirectInput8, NULL);
	assert(!FAILED(DirectInput8CreateResult));

	// Initialize the direct input interface for the mouse.
	HRESULT CreateDeviceResult = m_pDirectInput8->CreateDevice(GUID_SysMouse, &m_pDirectInput8Mouse, NULL);
	assert(!FAILED(CreateDeviceResult));

	// Set the data format for the mouse using the pre-defined mouse data format.
	HRESULT SetDataFormatResult = m_pDirectInput8Mouse->SetDataFormat(&c_dfDIMouse2);
	assert(!FAILED(SetDataFormatResult));

	DIPROPDWORD dipdw;
	dipdw.diph.dwSize = sizeof(DIPROPDWORD);
	dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER);
	dipdw.diph.dwObj = 0;
	dipdw.diph.dwHow = DIPH_DEVICE;
	dipdw.dwData = 64; // Arbitrary buffer size

	HRESULT SetPropertyResult = m_pDirectInput8Mouse->SetProperty(DIPROP_BUFFERSIZE, &dipdw.diph);
	assert(!FAILED(SetPropertyResult));

	Acquire();
}

void MouseInput::SetSensitivity(float horizontalSensitivity, float verticalSensitivity)
{
	s_horizontalSensitivity = __max(horizontalSensitivity, 0.0f);
	s_verticalSensitivity = __max(verticalSensitivity, 0.0f);
}

bool MouseInput::Read()
{
	s_mouseState2 = {};

	if (m_pDirectInput8 == nullptr || m_pDirectInput8Mouse == nullptr)
	{
		return false;
	}

	if (s_currentAcquireMode != 0)
	{
		// Read the mouse device.
		HRESULT GetDeviceStateResult = m_pDirectInput8Mouse->GetDeviceState(sizeof(DIMOUSESTATE2), (LPVOID)& s_mouseState2);
		if (FAILED(GetDeviceStateResult))
		{
			// If the mouse lost focus or was not acquired then try to get control back.
			if ((GetDeviceStateResult == DIERR_INPUTLOST) || (GetDeviceStateResult == DIERR_NOTACQUIRED))
			{
				// try to acquire next frame
				s_currentAcquireMode = 0;
			}
			else
			{
				return false;
			}
		}
	}

	return true;
}

void MouseInput::Deinit()
{
	// Release the mouse.
	assert(m_pDirectInput8Mouse != nullptr);
	m_pDirectInput8Mouse->Unacquire();
	m_pDirectInput8Mouse->Release();
	m_pDirectInput8Mouse = nullptr;

	// Release the main interface to direct input.
	assert(m_pDirectInput8 != nullptr);
	m_pDirectInput8->Release();
	m_pDirectInput8 = nullptr;
}

float MouseInput::GetMouseX()
{
	return float(s_mouseState2.lX) * 0.005f * s_horizontalSensitivity;
}

float MouseInput::GetMouseY()
{
	return float(s_mouseState2.lY) * 0.005f * s_horizontalSensitivity;
}

bool MouseInput::GetMouseButton(MouseInputButton button)
{
	bool buttonPressed = (s_mouseState2.rgbButtons[button] & 0b10000000) != 0;
	return buttonPressed;
}
