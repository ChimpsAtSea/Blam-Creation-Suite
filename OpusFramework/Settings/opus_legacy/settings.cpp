#include "opusframework-private-pch.h"
#include "settings.h"

bool Settings::ReadBoolValue(SettingsSection section, const char* pName, bool defaultValue /*= false*/)
{
	const char* pSectionName = GetSectionNameString(section);
	return !!GetPrivateProfileIntA(pSectionName, pName, defaultValue, k_pSettingsPath);
}

int Settings::ReadIntegerValue(SettingsSection section, const char* pName, int defaultValue /*= 0*/)
{
	const char* pSectionName = GetSectionNameString(section);
	return GetPrivateProfileIntA(pSectionName, pName, defaultValue, k_pSettingsPath);
}

float Settings::ReadFloatValue(SettingsSection section, const char* pName, float defaultValue /*= 0.0*/)
{
	char floatBuffer[32] = {};
	uint32_t length = ReadStringValue(section, pName, floatBuffer, sizeof(floatBuffer), "");

	if (length)
	{
		float value = static_cast<float>(atof(floatBuffer));
		return value;
	}
	return defaultValue;
}

uint32_t Settings::ReadStringValue(SettingsSection section, const char* pName, char* buffer, uint32_t buffer_size, const char* pDefaultValue /*= nullptr*/)
{
	if (buffer_size > 0)
	{
		const char* pSectionName = GetSectionNameString(section);
		memset(buffer, 0, buffer_size);
		GetPrivateProfileStringA(pSectionName, pName, pDefaultValue, buffer, buffer_size, k_pSettingsPath);
		return static_cast<uint32_t>(strlen(buffer));
	}
	return 0;
}

uint32_t Settings::ReadStringValueW(SettingsSection section, const char* pName, wchar_t* buffer, uint32_t buffer_size, const wchar_t* pDefaultValue /*= nullptr*/)
{
	if (buffer_size > 0)
	{
		const char* pSectionName = GetSectionNameString(section);
		memset(buffer, 0, buffer_size);

		size_t widecharNameBufferSize = (strlen(pName) + 1) * sizeof(wchar_t);
		wchar_t* pWidecharNameBuffer = static_cast<wchar_t*>(alloca(widecharNameBufferSize));
		memset(pWidecharNameBuffer, 0, widecharNameBufferSize);
		_snwprintf(pWidecharNameBuffer, widecharNameBufferSize / sizeof(wchar_t), L"%S", pName);

		size_t widecharSectionNameBufferSize = (strlen(pSectionName) + 1) * sizeof(wchar_t);
		wchar_t* pwidecharSectionNameBuffer = static_cast<wchar_t*>(alloca(widecharSectionNameBufferSize));
		memset(pwidecharSectionNameBuffer, 0, widecharSectionNameBufferSize);
		_snwprintf(pwidecharSectionNameBuffer, widecharSectionNameBufferSize / sizeof(wchar_t), L"%S", pSectionName);

		GetPrivateProfileStringW(pwidecharSectionNameBuffer, pWidecharNameBuffer, pDefaultValue, buffer, buffer_size, k_pWSettingsPath);
		return static_cast<uint32_t>(wcslen(buffer));
	}
	return 0;
}

bool Settings::WriteBoolValue(SettingsSection section, const char* pName, bool value)
{
	const char* pSectionName = GetSectionNameString(section);
	return WritePrivateProfileStringA(pSectionName, pName, value ? "1" : "0", k_pSettingsPath);
}

bool Settings::WriteIntegerValue(SettingsSection section, const char* pName, int value)
{
	const char* pSectionName = GetSectionNameString(section);
	size_t buffer_length = static_cast<int>(logl(UINT_MAX)) + 2;
	char* buffer = static_cast<char*>(alloca(buffer_length));
	memset(buffer, 0, buffer_length);
	_itoa(value, buffer, 10);
	return WritePrivateProfileStringA(pSectionName, pName, buffer, k_pSettingsPath);
}

bool Settings::WriteStringValue(SettingsSection section, const char* pName, const char* pValue)
{
	const char* pSectionName = GetSectionNameString(section);
	return WritePrivateProfileStringA(pSectionName, pName, pValue, k_pSettingsPath);
}

const char* Settings::GetSectionNameString(SettingsSection section)
{
	switch (section)
	{
	case SettingsSection::Game:
		return "Game";
	case SettingsSection::Camera:
		return "Camera";
	case SettingsSection::Player:
		return "Player";
	case SettingsSection::Debug:
		return "Debug";
	case SettingsSection::Launch:
		return "Launch";
	case SettingsSection::Controls:
		return "Controls";
	default:
		FATAL_ERROR(L"Unsupported section");
		return nullptr;
	}
}
