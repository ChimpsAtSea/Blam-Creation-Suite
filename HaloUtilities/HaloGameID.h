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
	return ~uint64_t();
}

constexpr uint64_t GetHaloTopAddress(HaloGameID gameID)
{
	switch (gameID)
	{
	case HaloGameID::HaloReach:
		return 0x184925000;
	}
	return ~uint64_t();
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
