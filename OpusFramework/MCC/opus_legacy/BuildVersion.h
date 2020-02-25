#pragma once

enum class EngineVersion
{
	NotSet,
	Halo1,
	HaloReach,
	MCC,
	Eldorado
};

#define MAKE_FILE_VERSION(a, b, c, d) ((uint64_t(a) << 48) | (uint64_t(b) << 32) | (uint64_t(c) << 16) | (uint64_t(d) << 0))

enum class BuildVersion : uint64_t
{
	NotSet,
	MCC_1_887_0_0				= MAKE_FILE_VERSION(1, 887, 0, 0),	 
	MCC_1_1035_0_0				= MAKE_FILE_VERSION(1, 1035, 0, 0), 
	MCC_1_1186_0_0				= MAKE_FILE_VERSION(1, 1186, 0, 0), 
	MCC_1_1211_0_0				= MAKE_FILE_VERSION(1, 1211, 0, 0), 
	MCC_1_1246_0_0				= MAKE_FILE_VERSION(1, 1246, 0, 0), 
	MCC_1_1270_0_0				= MAKE_FILE_VERSION(1, 1270, 0, 0), 
	MCC_1_1305_0_0				= MAKE_FILE_VERSION(1, 1305, 0, 0), 
	MCC_1_1350_0_0				= MAKE_FILE_VERSION(1, 1350, 0, 0), 
	MCC_1_1367_0_0				= MAKE_FILE_VERSION(1, 1367, 0, 0),
	Eldorado_1_106708_cert_ms23 = MAKE_FILE_VERSION(1, 106708, 'eldo', 'rado'), // 1.106708 cert_ms23  Mar 20 2015 17:24:42
};

#undef MAKE_FILE_VERSION

constexpr intptr_t GetEngineBaseAddress(EngineVersion engineVersion)
{
	switch (engineVersion)
	{
#ifdef _WIN64
	case EngineVersion::HaloReach:
	case EngineVersion::Halo1:
		return 0x180000000;
	case EngineVersion::MCC:
		return 0x140000000;
#else
	case EngineVersion::Eldorado:
		return 0x400000;
#endif
	}
	return ~intptr_t();
}

constexpr intptr_t GetEngineTopAddress(EngineVersion engineVersion, BuildVersion buildVersion)
{
#ifdef _WIN64
	if (engineVersion == EngineVersion::MCC)
	{
		// #TODO: Calculate the top address.
		return 0x14FFFFFFF;
	}
	else
	{
		if (engineVersion == EngineVersion::HaloReach)
		{
			switch (buildVersion)
			{
			case BuildVersion::MCC_1_887_0_0:
				return 0x184925000;
			case BuildVersion::MCC_1_1035_0_0:
				return 0x18450D000;
			case BuildVersion::MCC_1_1186_0_0:
				return 0x183985000;
			case BuildVersion::MCC_1_1211_0_0:
				return 0x183986000;
			case BuildVersion::MCC_1_1246_0_0:
				return 0x18397F000;
			case BuildVersion::MCC_1_1270_0_0:
				return 0x18397F000;
			case BuildVersion::MCC_1_1305_0_0:
				return 0x18392F000;
			}
		}
		if (buildVersion > BuildVersion::NotSet)
		{
			// #TODO: Calculate the top address.
			return 0x18FFFFFFF;
		}
}
#else
	if (engineVersion == EngineVersion::Eldorado)
	{
		switch (buildVersion)
		{
		case BuildVersion::Eldorado_1_106708_cert_ms23:
			return 0x06A0B000;
		}
	}
#endif
	return ~intptr_t();
}

constexpr const char* GetEngineModuleFileName(EngineVersion engineVersion)
{
	switch (engineVersion)
	{
	case EngineVersion::HaloReach:
		return "haloreach.dll";
	case EngineVersion::Halo1:
		return "halo1.dll";
	case EngineVersion::MCC:
		return "MCC-Win64-Shipping.exe";
	case EngineVersion::Eldorado:
		return "eldorado.exe";
	}
	FATAL_ERROR(L"Unsupported GameVersion");
}

extern bool IsEngineLoaded(EngineVersion engineVersion);
extern void* GetEngineMemoryAddress(EngineVersion engineVersion);
