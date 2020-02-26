#pragma once

enum class Engine
{
	NotSet,
	Halo1,
	HaloReach,
	MCC,
	Eldorado
};

#define MAKE_FILE_VERSION(a, b, c, d) ((uint64_t(a) << 48) | (uint64_t(b) << 32) | (uint64_t(c) << 16) | (uint64_t(d) << 0))

enum class Build : uint64_t
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

constexpr uintptr_t GetEngineBaseAddress(Engine engine)
{
	switch (engine)
	{
#ifdef _WIN64
	case Engine::HaloReach:
	case Engine::Halo1:
		return 0x180000000;
	case Engine::MCC:
		return 0x140000000;
#else
	case Engine::Eldorado:
		return 0x400000;
#endif
	}
	return ~uintptr_t();
}

constexpr uintptr_t GetEngineTopAddress(Engine engine, Build build)
{
#ifdef _WIN64
	if (engine == Engine::MCC)
	{
		// #TODO: Calculate the top address.
		return 0x14FFFFFFF;
	}
	else
	{
		if (engine == Engine::HaloReach)
		{
			switch (build)
			{
			case Build::MCC_1_887_0_0:
				return 0x184925000;
			case Build::MCC_1_1035_0_0:
				return 0x18450D000;
			case Build::MCC_1_1186_0_0:
				return 0x183985000;
			case Build::MCC_1_1211_0_0:
				return 0x183986000;
			case Build::MCC_1_1246_0_0:
				return 0x18397F000;
			case Build::MCC_1_1270_0_0:
				return 0x18397F000;
			case Build::MCC_1_1305_0_0:
				return 0x18392F000;
			}
		}
		if (build > Build::NotSet)
		{
			// #TODO: Calculate the top address.
			return 0x18FFFFFFF;
		}
}
#else
	if (engine == Engine::Eldorado)
	{
		switch (build)
		{
		case Build::Eldorado_1_106708_cert_ms23:
			return 0x06A0B000;
		}
	}
#endif
	return ~uintptr_t();
}

constexpr const char* GetEngineModuleFileName(Engine engine)
{
	switch (engine)
	{
	case Engine::HaloReach:
		return "haloreach.dll";
	case Engine::Halo1:
		return "halo1.dll";
	case Engine::MCC:
		return "MCC-Win64-Shipping.exe";
	case Engine::Eldorado:
		return "eldorado.exe";
	}
	FATAL_ERROR(L"Unsupported GameVersion");
}

extern bool IsEngineLoaded(Engine engine);
extern void* GetEngineMemoryAddress(Engine engine);

inline char* GetEngineVirtualAddress(Engine engine, uintptr_t virtual_address)
{
	uintptr_t relative_virtual_address = virtual_address - GetEngineBaseAddress(engine);
	char* engine_virtual_address = reinterpret_cast<char*>(GetEngineMemoryAddress(engine));
	char* virtual_address_pointer = engine_virtual_address + relative_virtual_address;
	return virtual_address_pointer;
}
