#pragma once

#define MAKE_FILE_VERSION(a, b, c, d) ((uint64_t(a) << 48) | (uint64_t(b) << 32) | (uint64_t(c) << 16) | (uint64_t(d) << 0))
#define MAKE_PRODUCT_VERSION(a, b, c) ((uint64_t(a) << 48) | (uint64_t(b) << 32) | (uint64_t(c) << 0))
#define MAKE_TOOL_VERSION(a, b, c, d, file_description, product_name) (MAKE_FILE_VERSION(a, b, c, d) ^ (file_description##product_name##_xxh64))
#define HASH_VERSION(a) (a)

enum e_build : uint64_t
{
	_build_not_set,
	_build_mcc_1_824_0_0 = MAKE_FILE_VERSION(1, 824, 0, 0),
	_build_mcc_1_887_0_0 = MAKE_FILE_VERSION(1, 887, 0, 0),
	_build_mcc_1_1035_0_0 = MAKE_FILE_VERSION(1, 1035, 0, 0),
	_build_mcc_1_1186_0_0 = MAKE_FILE_VERSION(1, 1186, 0, 0),
	_build_mcc_1_1211_0_0 = MAKE_FILE_VERSION(1, 1211, 0, 0),
	_build_mcc_1_1246_0_0 = MAKE_FILE_VERSION(1, 1246, 0, 0),
	_build_mcc_1_1270_0_0 = MAKE_FILE_VERSION(1, 1270, 0, 0),
	_build_mcc_1_1305_0_0 = MAKE_FILE_VERSION(1, 1305, 0, 0),
	_build_mcc_1_1350_0_0 = MAKE_FILE_VERSION(1, 1350, 0, 0),
	_build_mcc_1_1367_0_0 = MAKE_FILE_VERSION(1, 1367, 0, 0),
	_build_mcc_1_1377_0_0 = MAKE_FILE_VERSION(1, 1377, 0, 0),
	_build_mcc_1_1384_0_0 = MAKE_FILE_VERSION(1, 1384, 0, 0),
	_build_mcc_1_1387_0_0 = MAKE_FILE_VERSION(1, 1387, 0, 0),
	_build_mcc_1_1389_0_0 = MAKE_FILE_VERSION(1, 1389, 0, 0),
	_build_mcc_1_1477_0_0 = MAKE_FILE_VERSION(1, 1477, 0, 0),
	_build_mcc_1_1499_0_0 = MAKE_FILE_VERSION(1, 1499, 0, 0),
	_build_mcc_1_1520_0_0 = MAKE_FILE_VERSION(1, 1520, 0, 0),
	_build_mcc_1_1570_0_0 = MAKE_FILE_VERSION(1, 1570, 0, 0),
	_build_mcc_1_1619_0_0 = MAKE_FILE_VERSION(1, 1619, 0, 0),
	_build_mcc_1_1629_0_0 = MAKE_FILE_VERSION(1, 1629, 0, 0),
	_build_mcc_1_1658_0_0 = MAKE_FILE_VERSION(1, 1658, 0, 0),
	_build_mcc_1_1698_0_0 = MAKE_FILE_VERSION(1, 1698, 0, 0),
	_build_eldorado_1_106708_cert_ms23 = MAKE_PRODUCT_VERSION(0, 1, 106708), // 1.106708 cert_ms23  Mar 20 2015 17:24:42
	_build_eldorado_1_155080_cert_ms23 = MAKE_PRODUCT_VERSION(0, 1, 155080), // #TODO: If these are required for boot we must find a way to accurately find the version from the binary
	_build_eldorado_1_171227_cert_ms23 = MAKE_PRODUCT_VERSION(0, 1, 171227), // #TODO: If these are required for boot we must find a way to accurately find the version from the binary
	_build_eldorado_1_177150_cert_ms23 = MAKE_PRODUCT_VERSION(0, 1, 177150), // #TODO: If these are required for boot we must find a way to accurately find the version from the binary
	_build_eldorado_1_235640_cert_ms25 = MAKE_PRODUCT_VERSION(0, 1, 235640), // #TODO: If these are required for boot we must find a way to accurately find the version from the binary
	_build_eldorado_1_301003_cert_MS26_new = MAKE_PRODUCT_VERSION(0, 1, 301003),
	_build_eldorado_1_327043_cert_ms26 = MAKE_PRODUCT_VERSION(0, 1, 327043),
	_build_eldorado_1_332089_Live = MAKE_PRODUCT_VERSION(4, 1, 332089),
	_build_eldorado_1_373869_Live = MAKE_PRODUCT_VERSION(8, 1, 373869),
	_build_eldorado_1_416138_Live = MAKE_PRODUCT_VERSION(9, 1, 416138),
	_build_eldorado_1_430653_Live = MAKE_PRODUCT_VERSION(10, 1, 430653),
	_build_eldorado_1_454665_Live = MAKE_PRODUCT_VERSION(10, 1, 454665),
	_build_eldorado_1_479394_Live = MAKE_PRODUCT_VERSION(10, 1, 479394),
	_build_eldorado_1_498295_Live = MAKE_PRODUCT_VERSION(11, 1, 498295),
	_build_eldorado_1_530945_Live = MAKE_PRODUCT_VERSION(11, 1, 530945),
	_build_eldorado_1_533032_Live = MAKE_PRODUCT_VERSION(11, 1, 533032),
	_build_eldorado_1_554482_Live = MAKE_PRODUCT_VERSION(11, 1, 554482),
	_build_eldorado_1_571698_Live = MAKE_PRODUCT_VERSION(11, 1, 571698),
	_build_eldorado_1_604673_Live = MAKE_PRODUCT_VERSION(11, 1, 604673),
	_build_eldorado_1_700255_cert_ms30_oct19 = MAKE_PRODUCT_VERSION(12, 1, 700255),
	_build_halo1_guerilla = MAKE_TOOL_VERSION(1, 0, 0, 609, "Guerilla MFC Application", "Guerilla Application"),
	_build_halo2_guerilla = MAKE_TOOL_VERSION(1, 0, 0, 0, "Tag Editor", "Halo 2 for Windows Vista"),
	_build_halo5_forge_1_114_4592_2 = HASH_VERSION(0xc64ebca380e26cdd),
	_build_halo5_forge_1_194_6192_2 = HASH_VERSION(0xf1bafafca2ec154b),
	_build_midnight_tag_test_untracked_november_13_2013 = HASH_VERSION(0x4ecd85f51db2868a)
};

#undef MAKE_FILE_VERSION

template<typename string_type, bool pretty_string>
constexpr string_type get_enum_string(e_build build)
{
	enum_string_ex(string_type, pretty_string, build, _build_not_set, "Not set");
	enum_string_ex(string_type, pretty_string, build, _build_mcc_1_824_0_0, "MCC 1.824.0.0");
	enum_string_ex(string_type, pretty_string, build, _build_mcc_1_887_0_0, "MCC 1.887.0.0");
	enum_string_ex(string_type, pretty_string, build, _build_mcc_1_1035_0_0, "MCC 1.1035.0.0");
	enum_string_ex(string_type, pretty_string, build, _build_mcc_1_1186_0_0, "MCC 1.1186.0.0");
	enum_string_ex(string_type, pretty_string, build, _build_mcc_1_1211_0_0, "MCC 1.1211.0.0");
	enum_string_ex(string_type, pretty_string, build, _build_mcc_1_1246_0_0, "MCC 1.1246.0.0");
	enum_string_ex(string_type, pretty_string, build, _build_mcc_1_1270_0_0, "MCC 1.1270.0.0");
	enum_string_ex(string_type, pretty_string, build, _build_mcc_1_1305_0_0, "MCC 1.1305.0.0");
	enum_string_ex(string_type, pretty_string, build, _build_mcc_1_1350_0_0, "MCC 1.1350.0.0");
	enum_string_ex(string_type, pretty_string, build, _build_mcc_1_1367_0_0, "MCC 1.1367.0.0");
	enum_string_ex(string_type, pretty_string, build, _build_mcc_1_1377_0_0, "MCC 1.1377.0.0");
	enum_string_ex(string_type, pretty_string, build, _build_mcc_1_1384_0_0, "MCC 1.1384.0.0");
	enum_string_ex(string_type, pretty_string, build, _build_mcc_1_1387_0_0, "MCC 1.1387.0.0");
	enum_string_ex(string_type, pretty_string, build, _build_mcc_1_1389_0_0, "MCC 1.1389.0.0");
	enum_string_ex(string_type, pretty_string, build, _build_mcc_1_1477_0_0, "MCC 1.1477.0.0");
	enum_string_ex(string_type, pretty_string, build, _build_mcc_1_1499_0_0, "MCC 1.1499.0.0");
	enum_string_ex(string_type, pretty_string, build, _build_mcc_1_1520_0_0, "MCC 1.1520.0.0");
	enum_string_ex(string_type, pretty_string, build, _build_mcc_1_1570_0_0, "MCC 1.1570.0.0");
	enum_string_ex(string_type, pretty_string, build, _build_mcc_1_1619_0_0, "MCC 1.1619.0.0");
	enum_string_ex(string_type, pretty_string, build, _build_mcc_1_1629_0_0, "MCC 1.1629.0.0");
	enum_string_ex(string_type, pretty_string, build, _build_mcc_1_1658_0_0, "MCC 1.1658.0.0");
	enum_string_ex(string_type, pretty_string, build, _build_mcc_1_1698_0_0, "MCC 1.1698.0.0");
	enum_string_ex(string_type, pretty_string, build, _build_eldorado_1_106708_cert_ms23, "Eldorado 1.106708 cert_ms23");
	enum_string_ex(string_type, pretty_string, build, _build_eldorado_1_155080_cert_ms23, "Eldorado 1.155080 cert_ms23");
	enum_string_ex(string_type, pretty_string, build, _build_eldorado_1_171227_cert_ms23, "Eldorado 1.171227 cert_ms23");
	enum_string_ex(string_type, pretty_string, build, _build_eldorado_1_177150_cert_ms23, "Eldorado 1.177150 cert_ms23");
	enum_string_ex(string_type, pretty_string, build, _build_eldorado_1_235640_cert_ms25, "Eldorado 1.235640 cert_ms25");
	enum_string_ex(string_type, pretty_string, build, _build_eldorado_1_301003_cert_MS26_new, "Eldorado 1.301003 cert_MS26_new");
	enum_string_ex(string_type, pretty_string, build, _build_eldorado_1_327043_cert_ms26, "Eldorado 1.327043 cert_ms26");
	enum_string_ex(string_type, pretty_string, build, _build_eldorado_1_332089_Live, "Eldorado 1.332089 Live");
	enum_string_ex(string_type, pretty_string, build, _build_eldorado_1_373869_Live, "Eldorado 1.373869 Live");
	enum_string_ex(string_type, pretty_string, build, _build_eldorado_1_416138_Live, "Eldorado 1.416138 Live");
	enum_string_ex(string_type, pretty_string, build, _build_eldorado_1_430653_Live, "Eldorado 1.430653 Live");
	enum_string_ex(string_type, pretty_string, build, _build_eldorado_1_454665_Live, "Eldorado 1.454665 Live");
	enum_string_ex(string_type, pretty_string, build, _build_eldorado_1_479394_Live, "Eldorado 1.479394 Live");
	enum_string_ex(string_type, pretty_string, build, _build_eldorado_1_498295_Live, "Eldorado 1.498295 Live");
	enum_string_ex(string_type, pretty_string, build, _build_eldorado_1_530945_Live, "Eldorado 1.530945 Live");
	enum_string_ex(string_type, pretty_string, build, _build_eldorado_1_533032_Live, "Eldorado 1.533032 Live");
	enum_string_ex(string_type, pretty_string, build, _build_eldorado_1_554482_Live, "Eldorado 1.554482 Live");
	enum_string_ex(string_type, pretty_string, build, _build_eldorado_1_571698_Live, "Eldorado 1.571698 Live");
	enum_string_ex(string_type, pretty_string, build, _build_eldorado_1_604673_Live, "Eldorado 1.604673 Live");
	enum_string_ex(string_type, pretty_string, build, _build_eldorado_1_700255_cert_ms30_oct19, "Eldorado 1.700255 cert_ms30_oct19");
	enum_string_ex(string_type, pretty_string, build, _build_halo1_guerilla, "Halo 1 Guerilla");
	enum_string_ex(string_type, pretty_string, build, _build_halo2_guerilla, "Halo 2 Guerilla");
	enum_string_ex(string_type, pretty_string, build, _build_halo5_forge_1_114_4592_2, "Halo 5 Forge 1.114.4592.2_x64__8wekyb3d8bbwe");
	enum_string_ex(string_type, pretty_string, build, _build_midnight_tag_test_untracked_november_13_2013, "Halo 4 midnight tag test xenon untracked Nov 13 2013 11:14:44");
	return nullptr;
}

template<typename string_type, bool pretty_string>
constexpr string_type build_to_string(e_engine_type engine_type, e_build build)
{
	string_type result = get_enum_string<string_type, pretty_string>(build);
	if (result)
	{
		return result;
	}
	// #TODO: Create a list of unknown builds but try to format something sensible
	return auto_string_ex(string_type, pretty_string, "unknown build", "Unknown Build");
}

template<typename string_type, bool pretty_string>
constexpr string_type build_configuration_string()
{
#ifdef _DEBUG
	return auto_string_ex(string_type, pretty_string, "debug", "Debug");
#else
	return auto_string_ex(string_type, pretty_string, "release", "Release");
#endif
}

constexpr uintptr_t get_engine_base_address(e_engine_type engine_type)
{
	switch (engine_type)
	{
#ifdef _WIN64
	case _engine_type_haloreach:
	case _engine_type_halo1:
	case _engine_type_halo2:
	case _engine_type_halo3:
	case _engine_type_halo3odst:
	case _engine_type_halo4:
	case _engine_type_groundhog:
		return 0x180000000;
	case _engine_type_halo5:
	case _engine_type_mcc:
		return 0x140000000;
#else
	case _engine_type_eldorado:
		return 0x400000;
#endif
	}
	return ~uintptr_t();
}

constexpr uintptr_t get_engine_top_address(e_engine_type engine_type, e_build build)
{
#ifdef _WIN64
	if (engine_type == _engine_type_mcc || engine_type == _engine_type_halo5)
	{
		// #TODO: Calculate the top address.
		return 0x14FFFFFFF;
	}
	else
	{
		if (engine_type == _engine_type_haloreach)
		{
			switch (build)
			{
			case _build_mcc_1_887_0_0:
				return 0x184925000;
			case _build_mcc_1_1035_0_0:
				return 0x18450D000;
			case _build_mcc_1_1186_0_0:
				return 0x183985000;
			case _build_mcc_1_1211_0_0:
				return 0x183986000;
			case _build_mcc_1_1246_0_0:
				return 0x18397F000;
			case _build_mcc_1_1270_0_0:
				return 0x18397F000;
			case _build_mcc_1_1305_0_0:
				return 0x18392F000;
			}
		}
		if (build > _build_not_set)
		{
			// #TODO: Calculate the top address.
			return 0x18FFFFFFF;
		}
	}
#else
	if (engine_type == _engine_type_eldorado)
	{
		switch (build)
		{
		case _build_eldorado_1_106708_cert_ms23:
			return 0x06A0B000;
		}
	}
#endif
	return ~uintptr_t();
}

constexpr const char* get_engine_module_filename(e_engine_type engine_type)
{
	switch (engine_type)
	{
	case _engine_type_mcc:
		return "MCC-Win64-Shipping.exe";
	case _engine_type_haloreach:
		return "haloreach.dll";
	case _engine_type_halo1:
		return "halo1.dll";
	case _engine_type_halo2:
		return "halo2.dll";
	case _engine_type_halo3:
		return "halo3.dll";
	case _engine_type_halo3odst:
		return "halo3odst.dll";
	case _engine_type_halo4:
		return "halo4.dll";
	case _engine_type_groundhog:
		return "groundhog.dll";
	case _engine_type_eldorado:
		return "eldorado.exe";
	case _engine_type_halo5:
		return "halo5forge.exe";
	}
	FATAL_ERROR(L"Unsupported GameVersion");
}

extern bool is_engine_loaded(e_engine_type engine_type);
extern void* get_engine_memory_address(e_engine_type engine_type);
extern uint64_t get_library_file_version(const char* file_path);
extern uint64_t get_library_file_version(const wchar_t* file_path);
extern std::wstring get_library_description(const wchar_t* file_path);
extern std::wstring get_library_product_name(const wchar_t* file_path);

inline char* engine_virtual_address_to_pointer(e_engine_type engine_type, uintptr_t virtual_address)
{
	uintptr_t relative_virtual_address = virtual_address - get_engine_base_address(engine_type);
	char* engine_virtual_address = reinterpret_cast<char*>(get_engine_memory_address(engine_type));
	char* virtual_address_pointer = engine_virtual_address + relative_virtual_address;
	return virtual_address_pointer;
}
