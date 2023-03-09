#pragma once

typedef uint64_t t_build_id;

enum e_engine_type : unsigned char
{
	_engine_type_not_set,
	_engine_type_mcc,
	_engine_type_halo1,
	_engine_type_stubbs,
	_engine_type_halo2,
	_engine_type_halo3,
	_engine_type_halo3odst,
	_engine_type_eldorado,
	_engine_type_haloreach,
	_engine_type_halo4,
	_engine_type_groundhog,
	_engine_type_halo5,
	_engine_type_haloinfinite,
	k_number_of_engine_types
};

enum e_platform_type : unsigned char
{
	_platform_type_not_set,
	_platform_type_xbox,
	_platform_type_xbox_360,
	_platform_type_xbox_one,
	_platform_type_pc_32bit,
	_platform_type_pc_64bit,
	k_number_of_platform_types
};

enum e_build : unsigned short
{
	_build_not_set [[maybe_unused]],
	_build_halo1_xbox [[maybe_unused]],
	_build_halo1_beta_01_05_22_0268 [[maybe_unused]],
	_build_halo1_demo [[maybe_unused]],
	_build_halo1_pc_retail [[maybe_unused]],
	_build_halo1_custom_edition [[maybe_unused]],
	_build_halo1_anniversary_xbox360 [[maybe_unused]],
	_build_halo1_anniversary_mcc [[maybe_unused]],
	_build_stubbs [[maybe_unused]],
	_build_mcc_1_824_0_0 [[maybe_unused]],
	_build_mcc_1_887_0_0 [[maybe_unused]],
	_build_mcc_1_1035_0_0 [[maybe_unused]],
	_build_mcc_1_1186_0_0 [[maybe_unused]],
	_build_mcc_1_1211_0_0 [[maybe_unused]],
	_build_mcc_1_1246_0_0 [[maybe_unused]],
	_build_mcc_1_1270_0_0 [[maybe_unused]],
	_build_mcc_1_1305_0_0 [[maybe_unused]],
	_build_mcc_1_1350_0_0 [[maybe_unused]],
	_build_mcc_1_1367_0_0 [[maybe_unused]],
	_build_mcc_1_1377_0_0 [[maybe_unused]],
	_build_mcc_1_1384_0_0 [[maybe_unused]],
	_build_mcc_1_1387_0_0 [[maybe_unused]],
	_build_mcc_1_1389_0_0 [[maybe_unused]],
	_build_mcc_1_1477_0_0 [[maybe_unused]],
	_build_mcc_1_1499_0_0 [[maybe_unused]],
	_build_mcc_1_1520_0_0 [[maybe_unused]],
	_build_mcc_1_1570_0_0 [[maybe_unused]],
	_build_mcc_1_1619_0_0 [[maybe_unused]],
	_build_mcc_1_1629_0_0 [[maybe_unused]],
	_build_mcc_1_1658_0_0 [[maybe_unused]],
	_build_mcc_1_1698_0_0 [[maybe_unused]],
	_build_mcc_1_1716_0_0 [[maybe_unused]],
	_build_mcc_1_1767_0_0 [[maybe_unused]],
	_build_mcc_1_1778_0_0 [[maybe_unused]],
	_build_mcc_1_1792_0_0 [[maybe_unused]],
	_build_mcc_1_1829_0_0 [[maybe_unused]],
	_build_mcc_1_1864_0_0 [[maybe_unused]],
	_build_mcc_1_1871_0_0 [[maybe_unused]],
	_build_mcc_1_1896_0_0 [[maybe_unused]],
	_build_mcc_1_1930_0_0 [[maybe_unused]],
	_build_mcc_1_1955_0_0 [[maybe_unused]],
	_build_mcc_1_2028_0_0 [[maybe_unused]],
	_build_mcc_1_2094_0_0 [[maybe_unused]],
	_build_eldorado_1_106708_cert_ms23 [[maybe_unused]],
	_build_eldorado_1_155080_cert_ms23 [[maybe_unused]],
	_build_eldorado_1_171227_cert_ms23 [[maybe_unused]],
	_build_eldorado_1_177150_cert_ms23 [[maybe_unused]],
	_build_eldorado_1_235640_cert_ms25 [[maybe_unused]],
	_build_eldorado_1_301003_cert_MS26_new [[maybe_unused]],
	_build_eldorado_1_327043_cert_ms26 [[maybe_unused]],
	_build_eldorado_1_332089_Live [[maybe_unused]],
	_build_eldorado_1_373869_Live [[maybe_unused]],
	_build_eldorado_1_416138_Live [[maybe_unused]],
	_build_eldorado_1_430653_Live [[maybe_unused]],
	_build_eldorado_1_454665_Live [[maybe_unused]],
	_build_eldorado_1_479394_Live [[maybe_unused]],
	_build_eldorado_1_498295_Live [[maybe_unused]],
	_build_eldorado_1_530945_Live [[maybe_unused]],
	_build_eldorado_1_533032_Live [[maybe_unused]],
	_build_eldorado_1_554482_Live [[maybe_unused]],
	_build_eldorado_1_571698_Live [[maybe_unused]],
	_build_eldorado_1_604673_Live [[maybe_unused]],
	_build_eldorado_1_700255_cert_ms30_oct19 [[maybe_unused]],
	_build_halo1_guerilla [[maybe_unused]],
	_build_halo2_guerilla [[maybe_unused]],
	_build_halo3_guerilla [[maybe_unused]],
	_build_haloreach_tags [[maybe_unused]],
	_build_halo5_forge_1_114_4592_2 [[maybe_unused]],
	_build_halo5_forge_1_194_6192_2 [[maybe_unused]],
	_build_midnight_tag_test_untracked_november_13_2013 [[maybe_unused]],
	_build_infinite_FLT002INT_199229_21_07_20_0001 [[maybe_unused]],
	_build_infinite_HIFLTA_202700_21_09_06_0001 [[maybe_unused]],
	_build_infinite_HIREL_209048_21_12_09_1546 [[maybe_unused]],
	k_number_of_build_types [[maybe_unused]]
};

enum t_engine_platform_build : unsigned long;

struct s_engine_platform_build
{
	e_engine_type engine_type;
	e_platform_type platform_type;
	e_build build;

	explicit constexpr operator t_engine_platform_build() const
	{
		using t_underlying = __underlying_type(t_engine_platform_build);

		t_underlying result = engine_type;
		result |= static_cast<t_underlying>(platform_type) << (sizeof(engine_type) * 8);
		result |= static_cast<t_underlying>(build) << ((sizeof(engine_type) + sizeof(platform_type)) * 8);

		return static_cast<t_engine_platform_build>(result);
	}

	BCS_SHARED operator bool() const;
	BCS_SHARED bool operator ==(const s_engine_platform_build& value) const;
	BCS_SHARED bool operator !=(const s_engine_platform_build& value) const;
	BCS_SHARED bool operator <(const s_engine_platform_build& value) const;
	BCS_SHARED bool operator >(const s_engine_platform_build& value) const;
	BCS_SHARED bool operator <=(const s_engine_platform_build& value) const;
	BCS_SHARED bool operator >=(const s_engine_platform_build& value) const;
};

#define t_engine_platform_build(...) t_engine_platform_build(s_engine_platform_build __VA_ARGS__)

class c_engine_platform_build :
	public s_engine_platform_build
{
public:
	c_engine_platform_build(e_platform_type platform_type) :
		s_engine_platform_build{ _engine_type_not_set, platform_type, _build_not_set }
	{

	}

	c_engine_platform_build(e_engine_type engine_type, e_platform_type platform_type, e_build build = _build_not_set) :
		s_engine_platform_build{ engine_type, platform_type, build }
	{

	}

	c_engine_platform_build(e_engine_type engine_type, e_build build = _build_not_set) :
		s_engine_platform_build{ engine_type, _platform_type_not_set, build }
	{

	}
};

BCS_SHARED extern BCS_RESULT get_engine_type_pretty_string(e_engine_type engine_type, const char*& engine_pretty_string);
BCS_SHARED extern BCS_RESULT get_engine_type_namespace(e_engine_type engine_type, const char*& result);
BCS_SHARED extern BCS_RESULT get_engine_type_string(e_engine_type engine_type, const char*& result);

BCS_SHARED extern BCS_RESULT engine_pretty_string_to_engine_type(const char* engine_pretty_string, e_engine_type& engine_type);
BCS_SHARED extern BCS_RESULT engine_namespace_to_engine_type(const char* engine_namespace, e_engine_type& engine_type);
BCS_SHARED extern BCS_RESULT engine_string_to_engine_type(const char* engine_string, e_engine_type& engine_type);

BCS_SHARED extern bool get_platform_is_big_endian(s_engine_platform_build engine_platform_build);
BCS_SHARED extern bool get_platform_is_big_endian(e_platform_type platform_type);

BCS_SHARED extern BCS_RESULT get_platform_type_pretty_string(e_platform_type platform_type, const char*& platform_pretty_string);
BCS_SHARED extern BCS_RESULT get_platform_type_namespace(e_platform_type platform_type, const char*& platform_namespace);
BCS_SHARED extern BCS_RESULT get_platform_type_string(e_platform_type platform_type, const char*& platform_string);

BCS_SHARED extern BCS_RESULT platform_pretty_string_to_platform_type(const char* platform_pretty_string, e_platform_type& platform_type);
BCS_SHARED extern BCS_RESULT platform_namespace_to_platform_type(const char* platform_namespace, e_platform_type& platform_type);
BCS_SHARED extern BCS_RESULT platform_string_to_platform_type(const char* platform_string, e_platform_type& platform_type);

BCS_SHARED extern BCS_RESULT get_platform_pointer_size(e_platform_type platform_type, uint32_t* pointer_size);
BCS_SHARED extern BCS_RESULT get_build_pretty_string(e_build build, const char** result);
BCS_SHARED extern BCS_RESULT get_build_string(e_build build, const char** result);

BCS_SHARED extern BCS_RESULT get_engine_module_filename(s_engine_platform_build engine_platform_build, const char** result);

BCS_SHARED extern const char* get_build_configuration_pretty_string();
BCS_SHARED extern const char* get_build_configuration_string();

BCS_SHARED extern BCS_RESULT get_engine_top_address(s_engine_platform_build engine_platform_build, uintptr_t* result);
BCS_SHARED extern BCS_RESULT get_engine_base_address(s_engine_platform_build engine_platform_build, uintptr_t* result);
BCS_SHARED extern BCS_RESULT get_engine_runtime_base_address(s_engine_platform_build engine_platform_build, void** result);

BCS_SHARED extern BCS_RESULT get_library_file_version(const char* file_path, uint64_t* file_version);
BCS_SHARED extern BCS_RESULT get_library_file_version(const wchar_t* file_path, uint64_t* file_version);
BCS_SHARED extern BCS_RESULT get_library_description(const wchar_t* file_path, wchar_t* buffer, size_t buffer_size);
BCS_SHARED extern BCS_RESULT get_library_product_name(const wchar_t* file_path, wchar_t* buffer, size_t buffer_size);

BCS_SHARED extern BCS_RESULT engine_virtual_address_to_pointer(s_engine_platform_build engine_platform_build, uintptr_t virtual_address, void** pointer);
