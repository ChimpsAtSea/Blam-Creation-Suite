#pragma once

enum class EngineVersion
{
	NotSet,
	Halo1,
	HaloReach
};

#define MAKE_FILE_VERSION(a, b, c, d) ((uint64_t(a) << 48) | (uint64_t(b) << 32) | (uint64_t(c) << 16) | (uint64_t(d) << 0))

enum class BuildVersion : uint64_t
{
	NotSet,
	Build_1_887_0_0	 = MAKE_FILE_VERSION(1, 887, 0, 0),
	Build_1_1035_0_0 = MAKE_FILE_VERSION(1, 1035, 0, 0),
	Build_1_1186_0_0 = MAKE_FILE_VERSION(1, 1186, 0, 0),
	Build_1_1211_0_0 = MAKE_FILE_VERSION(1, 1211, 0, 0), 
	Build_1_1246_0_0 = MAKE_FILE_VERSION(1, 1246, 0, 0), 
	Build_1_1270_0_0 = MAKE_FILE_VERSION(1, 1270, 0, 0),
	Build_1_1305_0_0 = MAKE_FILE_VERSION(1, 1305, 0, 0),
	Build_1_1350_0_0 = MAKE_FILE_VERSION(1, 1350, 0, 0)
};

#undef MAKE_FILE_VERSION

constexpr intptr_t GetBuildBaseAddress(BuildVersion buildVersion)
{
	switch (buildVersion)
	{
	case BuildVersion::Build_1_887_0_0:
	case BuildVersion::Build_1_1035_0_0:
	case BuildVersion::Build_1_1186_0_0:
	case BuildVersion::Build_1_1211_0_0:
	case BuildVersion::Build_1_1246_0_0:
	case BuildVersion::Build_1_1270_0_0:
	case BuildVersion::Build_1_1305_0_0:
		return 0x180000000;
	}
	if (buildVersion > BuildVersion::NotSet)
	{
		// #TODO: Get the base address.
		return 0x180000000;
	}
	return ~intptr_t();
}

constexpr intptr_t GetEngineTopAddress(BuildVersion buildVersion)
{
	switch (buildVersion)
	{
	case BuildVersion::Build_1_887_0_0:
		return 0x184925000;
	case BuildVersion::Build_1_1035_0_0:
		return 0x18450D000;
	case BuildVersion::Build_1_1186_0_0:
		return 0x183985000;
	case BuildVersion::Build_1_1211_0_0:
		return 0x183986000;
	case BuildVersion::Build_1_1246_0_0:
		return 0x18397F000;
	case BuildVersion::Build_1_1270_0_0:
		return 0x18397F000;
	case BuildVersion::Build_1_1305_0_0:
		return 0x18392F000;
	}
	if (buildVersion > BuildVersion::NotSet)
	{
		// #TODO: Calculate the top address.
		return 0x18FFFFFFF;
	}
	return ~intptr_t();
}

constexpr const char* GetEngineFilename(EngineVersion engineVersion)
{
	switch (engineVersion)
	{
	case EngineVersion::HaloReach:
		return "haloreach.dll";
	case EngineVersion::Halo1:
		return "halo1.dll";
	}
	FATAL_ERROR(L"Unsupported GameVersion");
}

extern bool IsEngineLoaded(EngineVersion engineVersion);
extern void* GetEngineMemoryAddress(EngineVersion engineVersion);
