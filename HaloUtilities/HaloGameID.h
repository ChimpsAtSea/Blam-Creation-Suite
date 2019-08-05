#pragma once

enum class HaloGameID
{
	NotSet,
	HaloReach,
};

constexpr uint64_t GetHaloBaseAddress(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach:
		return 0x180000000;
	}
	FATAL_ERROR("Unsupported HaloGameID");
}

constexpr const char* GetHaloExecutableString(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach:
		return "haloreach.dll";
	}
	FATAL_ERROR("Unsupported HaloGameID");
}

extern bool IsHaloExecutableLoaded(HaloGameID gameID);
extern void* GetHaloExecutable(HaloGameID gameID);
