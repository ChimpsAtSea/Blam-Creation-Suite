#pragma once

enum e_engine_type : uint8_t
{
	_engine_type_not_set,
	_engine_type_mcc,
	_engine_type_haloreach,
	_engine_type_halo1,
	_engine_type_halo2,
	_engine_type_halo3,
	_engine_type_halo3odst,
	_engine_type_halo4,
	_engine_type_groundhog,
	_engine_type_eldorado,
	_engine_type_halo5,
};

constexpr const char* engine_type_to_string(e_engine_type engine_type, const char* fallback = nullptr)
{
	switch (engine_type)
	{
	case _engine_type_not_set:		return "_engine_type_not_set";
	case _engine_type_mcc:			return "_engine_type_mcc";
	case _engine_type_haloreach:	return "_engine_type_haloreach";
	case _engine_type_halo1:		return "_engine_type_halo1";
	case _engine_type_halo2:		return "_engine_type_halo2";
	case _engine_type_halo3:		return "_engine_type_halo3";
	case _engine_type_halo3odst:	return "_engine_type_halo3odst";
	case _engine_type_halo4:		return "_engine_type_halo4";
	case _engine_type_groundhog:	return "_engine_type_groundhog";
	case _engine_type_eldorado:		return "_engine_type_eldorado";
	case _engine_type_halo5:		return "_engine_type_halo5";
	}
	return fallback;
}

constexpr const char* engine_type_to_nice_name(e_engine_type engine_type, const char* fallback = nullptr)
{
	switch (engine_type)
	{
	case _engine_type_not_set:		return "Not Set";
	case _engine_type_mcc:			return "Master Chief Collection";
	case _engine_type_haloreach:	return "Halo Reach";
	case _engine_type_halo1:		return "Halo 1";
	case _engine_type_halo2:		return "Halo 2";
	case _engine_type_halo3:		return "Halo 3";
	case _engine_type_halo3odst:	return "Halo 3: ODST";
	case _engine_type_halo4:		return "Halo 4";
	case _engine_type_groundhog:	return "Groundhog";
	case _engine_type_eldorado:		return "Eldorado";
	case _engine_type_halo5:		return "Halo 5 Forge";
	}
	return fallback;
}

constexpr const char* engine_type_to_folder_name(e_engine_type engine_type, const char* fallback = nullptr)
{
	switch (engine_type)
	{
	case _engine_type_haloreach:	return "haloreach";
	case _engine_type_halo1:		return "halo1";
	case _engine_type_halo2:		return "halo2";
	case _engine_type_halo3:		return "halo3";
	case _engine_type_halo3odst:	return "halo3odst";
	case _engine_type_halo4:		return "halo4";
	case _engine_type_groundhog:	return "groundhog";
	}
	return fallback;
}
constexpr const wchar_t* engine_type_to_folder_name_widechar(e_engine_type engine_type, const wchar_t* fallback = nullptr)
{
	switch (engine_type)
	{
	case _engine_type_haloreach:	return L"haloreach";
	case _engine_type_halo1:		return L"halo1";
	case _engine_type_halo2:		return L"halo2";
	case _engine_type_halo3:		return L"halo3";
	case _engine_type_halo3odst:	return L"halo3odst";
	case _engine_type_halo4:		return L"halo4";
	case _engine_type_groundhog:	return L"groundhog";
	}
	return fallback;
}


