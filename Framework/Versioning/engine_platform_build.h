#pragma once

#include "build_helpers.inl"

enum e_engine_type : uint8_t
{
	_engine_type_not_set,
	_engine_type_mcc,
	_engine_type_halo1,
	_engine_type_halo2,
	_engine_type_halo3,
	_engine_type_halo3odst,
	_engine_type_eldorado,
	_engine_type_haloreach,
	_engine_type_halo4,
	_engine_type_gen3_xbox360,
	_engine_type_groundhog,
	_engine_type_halo5,
	k_number_of_engine_types
};

enum e_platform_type : uint8_t
{
	_platform_type_not_set,
	_platform_type_xbox,
	_platform_type_xbox_360,
	_platform_type_xbox_one,
	_platform_type_pc,
	_platform_type_pc_legacy,
	k_number_of_platform_types
};

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
	_build_mcc_1_1716_0_0 = MAKE_FILE_VERSION(1, 1716, 0, 0),
	_build_mcc_1_1767_0_0 = MAKE_FILE_VERSION(1, 1767, 0, 0),
	_build_mcc_1_1778_0_0 = MAKE_FILE_VERSION(1, 1778, 0, 0),
	_build_mcc_1_1792_0_0 = MAKE_FILE_VERSION(1, 1792, 0, 0),
	_build_mcc_1_1829_0_0 = MAKE_FILE_VERSION(1, 1829, 0, 0),
	_build_mcc_1_1864_0_0 = MAKE_FILE_VERSION(1, 1864, 0, 0),
	_build_mcc_1_1871_0_0 = MAKE_FILE_VERSION(1, 1871, 0, 0),
	_build_mcc_1_1896_0_0 = MAKE_FILE_VERSION(1, 1896, 0, 0),
	_build_mcc_1_1930_0_0 = MAKE_FILE_VERSION(1, 1930, 0, 0),
	_build_mcc_1_1955_0_0 = MAKE_FILE_VERSION(1, 1955, 0, 0),
	_build_mcc_1_2028_0_0 = MAKE_FILE_VERSION(1, 2028, 0, 0),
	_build_mcc_1_2094_0_0 = MAKE_FILE_VERSION(1, 2094, 0, 0),
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
#undef MAKE_PRODUCT_VERSION
#undef MAKE_TOOL_VERSION
#undef HASH_VERSION

struct s_engine_platform_build
{
	e_engine_type engine_type;
	e_platform_type platform_type;
	e_build build;
};

class c_engine_platform_build
{
public:
	c_engine_platform_build(e_platform_type platform_type) :
		engine_platform_build{ _engine_type_not_set, platform_type, _build_not_set }
	{

	}

	c_engine_platform_build(e_engine_type engine_type, e_platform_type platform_type, e_build build = _build_not_set) :
		engine_platform_build{ engine_type, platform_type, build }
	{

	}

	c_engine_platform_build(e_engine_type engine_type, e_build build = _build_not_set) :
		engine_platform_build{ engine_type, _platform_type_not_set, build }
	{

	}
	
	s_engine_platform_build engine_platform_build;

	operator const s_engine_platform_build&() const
	{
		return engine_platform_build;
	}
};

extern BCS_RESULT get_engine_type_pretty_string(e_engine_type engine_type, const char** result);
extern BCS_RESULT get_engine_type_folder_string(e_engine_type engine_type, const char** result);
extern BCS_RESULT get_engine_type_source_string(e_engine_type engine_type, const char** result);
extern BCS_RESULT get_engine_type_string(e_engine_type engine_type, const char** result);
extern BCS_RESULT get_platform_type_pretty_string(e_platform_type platform_type, const char** result);
extern BCS_RESULT get_platform_type_string(e_platform_type platform_type, const char** result);
extern BCS_RESULT get_platform_pointer_size(e_platform_type platform_type, uint32_t* pointer_size);
extern BCS_RESULT get_build_pretty_string(e_build build, const char** result);
extern BCS_RESULT get_build_string(e_build build, const char** result);

extern BCS_RESULT get_engine_module_filename(s_engine_platform_build engine_platform_build, const char** result);

extern const char* get_build_configuration_pretty_string();
extern const char* get_build_configuration_string();

extern BCS_RESULT get_engine_top_address(s_engine_platform_build engine_platform_build, uintptr_t* result);
extern BCS_RESULT get_engine_base_address(s_engine_platform_build engine_platform_build, uintptr_t* result);
extern BCS_RESULT get_engine_runtime_base_address(s_engine_platform_build engine_platform_build, void** result);

extern BCS_RESULT get_library_file_version(const char* file_path, uint64_t* file_version);
extern BCS_RESULT get_library_file_version(const wchar_t* file_path, uint64_t* file_version);
extern BCS_RESULT get_library_description(const wchar_t* file_path, wchar_t* buffer, size_t buffer_size);
extern BCS_RESULT get_library_product_name(const wchar_t* file_path, wchar_t* buffer, size_t buffer_size);

extern BCS_RESULT engine_virtual_address_to_pointer(s_engine_platform_build engine_platform_build, uintptr_t virtual_address, void** pointer);
