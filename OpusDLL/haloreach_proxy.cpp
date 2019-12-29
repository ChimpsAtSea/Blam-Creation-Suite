#include "opus-private-pch.h"

typedef __int64(__fastcall CreateDataAccessFunc)(_QWORD* a1);
CreateDataAccessFunc* CreateDataAccessPtr = nullptr;
extern "C" __declspec(dllexport) __int64 __fastcall CreateDataAccess(_QWORD * a1)
{
	return CreateDataAccessPtr(a1);
}

typedef __int64(__fastcall CreateGameEngineFunc)(_QWORD* a1);
CreateGameEngineFunc* CreateGameEnginePtr = nullptr;
extern "C" __declspec(dllexport) __int64 __fastcall CreateGameEngine(_QWORD * a1)
{
	return CreateGameEnginePtr(a1);
}

typedef errno_t(__fastcall SetLibrarySettingsFunc)(wchar_t* Src);
SetLibrarySettingsFunc* SetLibrarySettingsPtr = nullptr;
extern "C" __declspec(dllexport) errno_t __fastcall SetLibrarySettings(wchar_t* Src)
{
	return SetLibrarySettingsPtr(Src);
}

HMODULE HaloReachDLL; // haloreach.dll

void init_haloreach()
{
	HaloReachDLL = LoadLibraryA("haloreach.dll");
	assert(HaloReachDLL);

	CreateDataAccessPtr = (CreateDataAccessFunc*)GetProcAddress(HaloReachDLL, "CreateDataAccess");
	CreateGameEnginePtr = (CreateGameEngineFunc*)GetProcAddress(HaloReachDLL, "CreateGameEngine");
	SetLibrarySettingsPtr = (SetLibrarySettingsFunc*)GetProcAddress(HaloReachDLL, "SetLibrarySettings");

	assert(CreateDataAccessPtr);
	assert(CreateGameEnginePtr);
	assert(SetLibrarySettingsPtr);
}

void deinit_haloreach()
{
	assert(CreateDataAccessPtr);
	assert(CreateGameEnginePtr);
	assert(SetLibrarySettingsPtr);

	CreateDataAccessPtr = nullptr;
	CreateGameEnginePtr = nullptr;
	SetLibrarySettingsPtr = nullptr;

	BOOL freeLibraryResult = FreeLibrary(HaloReachDLL);
	assert(freeLibraryResult);
}