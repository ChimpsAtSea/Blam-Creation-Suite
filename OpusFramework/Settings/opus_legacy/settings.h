#pragma once

enum class SettingsSection
{
	Game,
	Camera,
	Player,
	Debug,
	Launch,
	Controls
};

class Settings
{
public:
	static constexpr char k_pSettingsPath[MAX_PATH] = ".\\Settings.ini";
	static constexpr wchar_t k_pWSettingsPath[MAX_PATH] = L".\\Settings.ini";

	static bool ReadBoolValue(SettingsSection section, const char* pName, bool defaultValue = false);
	static int ReadIntegerValue(SettingsSection section, const char* pName, int defaultValue = 0);
	static float ReadFloatValue(SettingsSection section, const char* pName, float defaultValue = 0.0);
	static uint32_t ReadStringValue(SettingsSection section, const char* pName, char* pBuffer, uint32_t bufferSize, const char* pDefaultValue = nullptr);
	static uint32_t ReadStringValueW(SettingsSection section, const char* pName, wchar_t* pBuffer, uint32_t bufferSize, const wchar_t* pDefaultValue = nullptr);

	static bool WriteBoolValue(SettingsSection section, const char* pName, bool value);
	static bool WriteIntegerValue(SettingsSection section, const char* pName, int value);
	static bool WriteStringValue(SettingsSection section, const char* pName, const char* pValue);

	static const char* GetSectionNameString(SettingsSection section);
};

