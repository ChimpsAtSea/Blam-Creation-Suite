#include "haloshared-private-pch.h"
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

uint32_t Settings::ReadStringValue(SettingsSection section, const char* pName, char* pBuffer, uint32_t bufferSize, const char* pDefaultValue /*= nullptr*/)
{
	if (bufferSize > 0)
	{
		const char* pSectionName = GetSectionNameString(section);
		memset(pBuffer, 0, bufferSize);
		GetPrivateProfileStringA(pSectionName, pName, pDefaultValue, pBuffer, bufferSize, k_pSettingsPath);
		return static_cast<uint32_t>(strlen(pBuffer));
	}
	return 0;
}

uint32_t Settings::ReadStringValueW(SettingsSection section, const char* pName, wchar_t* pBuffer, uint32_t bufferSize, const wchar_t* pDefaultValue /*= nullptr*/)
{
	if (bufferSize > 0)
	{
		const char* pSectionName = GetSectionNameString(section);
		memset(pBuffer, 0, bufferSize);

		size_t widecharNameBufferSize = (strlen(pName) + 1) * sizeof(wchar_t);
		wchar_t* pWidecharNameBuffer = static_cast<wchar_t*>(alloca(widecharNameBufferSize));
		memset(pWidecharNameBuffer, 0, widecharNameBufferSize);
		_snwprintf(pWidecharNameBuffer, widecharNameBufferSize / sizeof(wchar_t), L"%S", pName);

		size_t widecharSectionNameBufferSize = (strlen(pSectionName) + 1) * sizeof(wchar_t);
		wchar_t* pwidecharSectionNameBuffer = static_cast<wchar_t*>(alloca(widecharSectionNameBufferSize));
		memset(pwidecharSectionNameBuffer, 0, widecharSectionNameBufferSize);
		_snwprintf(pwidecharSectionNameBuffer, widecharSectionNameBufferSize / sizeof(wchar_t), L"%S", pSectionName);

		GetPrivateProfileStringW(pwidecharSectionNameBuffer, pWidecharNameBuffer, pDefaultValue, pBuffer, bufferSize, k_pWSettingsPath);
		return static_cast<uint32_t>(wcslen(pBuffer));
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
	size_t bufferLength = static_cast<int>(logl(UINT_MAX)) + 2;
	char* pBuffer = static_cast<char*>(alloca(bufferLength));
	memset(pBuffer, 0, bufferLength);
	_itoa(value, pBuffer, 10);
	return WritePrivateProfileStringA(pSectionName, pName, pBuffer, k_pSettingsPath);
}

bool Settings::WriteStringValue(SettingsSection section, const char* pName, char* pValue)
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
		FATAL_ERROR("Unsupported section");
		return nullptr;
	}
}
