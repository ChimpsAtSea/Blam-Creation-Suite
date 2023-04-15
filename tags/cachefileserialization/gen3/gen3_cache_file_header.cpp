#include "cachefileserialization-private-pch.h"

#if \
defined(BCS_BUILD_HIGH_LEVEL_HALO3) || \
defined(BCS_BUILD_HIGH_LEVEL_HALO3ODST) || \
defined(BCS_BUILD_HIGH_LEVEL_ELDORADO) || \
defined(BCS_BUILD_HIGH_LEVEL_HALOREACH) || \
defined(BCS_BUILD_HIGH_LEVEL_HALO4) || \
defined(BCS_BUILD_HIGH_LEVEL_GROUNDHOG)

template<> BCS_SHARED void byteswap_inplace(gen3::s_cache_file_section_file_bounds& value)
{
	byteswap_inplace(value.offset);
	byteswap_inplace(value.size);
}

template<> BCS_SHARED void byteswap_inplace(gen3::s_cache_file_insertion_point_resource_usage& value)
{
	// #TODO
}

#endif

namespace gen3
{
	BCS_SHARED BCS_RESULT gen3_scenario_type_to_base_scenario_type(e_scenario_type gen3_scenario_type, ::e_scenario_type& base_scenario_type)
	{
		switch (gen3_scenario_type)
		{
		case gen3::_scenario_type_none:
			base_scenario_type = ::_scenario_type_none;
			return BCS_S_OK;
		case gen3::_scenario_type_campaign:
			base_scenario_type = ::_scenario_type_campaign;
			return BCS_S_OK;
		case gen3::_scenario_type_multiplayer:
			base_scenario_type = ::_scenario_type_multiplayer;
			return BCS_S_OK;
		case gen3::_scenario_type_mainmenu:
			base_scenario_type = ::_scenario_type_mainmenu;
			return BCS_S_OK;
		case gen3::_scenario_type_shared:
			base_scenario_type = ::_scenario_type_shared;
			return BCS_S_OK;
		case gen3::_scenario_type_shared_campaign:
			base_scenario_type = ::_scenario_type_shared_campaign;
			return BCS_S_OK;
		case gen3::_scenario_type_shared_multiplayer:
			base_scenario_type = ::_scenario_type_shared_multiplayer;
			return BCS_S_OK;
		}
		return BCS_E_UNSUPPORTED;
	}

	BCS_SHARED BCS_RESULT base_scenario_type_to_gen3_scenario_type(::e_scenario_type base_scenario_type, e_scenario_type& gen3_scenario_type)
	{
		switch (base_scenario_type)
		{
		case ::_scenario_type_none:
			gen3_scenario_type = gen3::_scenario_type_none;
			return BCS_S_OK;
		case ::_scenario_type_campaign:
			gen3_scenario_type = gen3::_scenario_type_campaign;
			return BCS_S_OK;
		case ::_scenario_type_multiplayer:
			gen3_scenario_type = gen3::_scenario_type_multiplayer;
			return BCS_S_OK;
		case ::_scenario_type_mainmenu:
			gen3_scenario_type = gen3::_scenario_type_mainmenu;
			return BCS_S_OK;
		case ::_scenario_type_shared:
			gen3_scenario_type = gen3::_scenario_type_shared;
			return BCS_S_OK;
		case ::_scenario_type_shared_campaign:
			gen3_scenario_type = gen3::_scenario_type_shared_campaign;
			return BCS_S_OK;
		case ::_scenario_type_shared_multiplayer:
			gen3_scenario_type = gen3::_scenario_type_shared_multiplayer;
			return BCS_S_OK;
		}
		return BCS_E_UNSUPPORTED;
	}

	BCS_SHARED BCS_RESULT gen3_scenario_load_type_to_base_scenario_load_type(e_scenario_load_type gen3_scenario_load_type, ::e_scenario_load_type& base_scenario_load_type)
	{
		switch (gen3_scenario_load_type)
		{
		case gen3::_scenario_load_none:
			base_scenario_load_type = ::_scenario_load_none;
			return BCS_S_OK;
		case gen3::_scenario_load_default:
			base_scenario_load_type = ::_scenario_load_default;
			return BCS_S_OK;
		case gen3::_scenario_load_shared:
			base_scenario_load_type = ::_scenario_load_shared;
			return BCS_S_OK;
		case gen3::_scenario_load_shared_campaign:
			base_scenario_load_type = ::_scenario_load_shared_campaign;
			return BCS_S_OK;
		case gen3::_scenario_load_shared_multiplayer:
			base_scenario_load_type = ::_scenario_load_shared_multiplayer;
			return BCS_S_OK;
		}
		return BCS_E_UNSUPPORTED;
	}

	BCS_SHARED BCS_RESULT base_scenario_load_type_to_gen3_scenario_load_type(::e_scenario_load_type base_scenario_load_type, e_scenario_load_type& gen3_scenario_load_type)
	{
		switch (base_scenario_load_type)
		{
		case ::_scenario_load_none:
			gen3_scenario_load_type = gen3::_scenario_load_none;
			return BCS_S_OK;
		case ::_scenario_load_default:
			gen3_scenario_load_type = gen3::_scenario_load_default;
			return BCS_S_OK;
		case ::_scenario_load_shared:
			gen3_scenario_load_type = gen3::_scenario_load_shared;
			return BCS_S_OK;
		case ::_scenario_load_shared_campaign:
			gen3_scenario_load_type = gen3::_scenario_load_shared_campaign;
			return BCS_S_OK;
		case ::_scenario_load_shared_multiplayer:
			gen3_scenario_load_type = gen3::_scenario_load_shared_multiplayer;
			return BCS_S_OK;
		}
		return BCS_E_UNSUPPORTED;
	}

	BCS_SHARED BCS_RESULT gen3_cache_file_shared_file_type_to_base_cache_file_shared_file_type(e_cache_file_shared_file_type gen3_cache_file_shared_file_type, ::e_cache_file_shared_file_type& base_cache_file_shared_file_type)
	{
		switch (gen3_cache_file_shared_file_type)
		{
		case gen3::_shared_file_type_none:
			base_cache_file_shared_file_type = ::_shared_file_type_none;
			return BCS_S_OK;
		case gen3::_shared_file_type_unknown0:
			base_cache_file_shared_file_type = ::_shared_file_type_unknown0;
			return BCS_S_OK;
		case gen3::_shared_file_type_unknown1:
			base_cache_file_shared_file_type = ::_shared_file_type_unknown1;
			return BCS_S_OK;
		case gen3::_shared_file_type_unknown2:
			base_cache_file_shared_file_type = ::_shared_file_type_unknown2;
			return BCS_S_OK;
		}
		return BCS_E_UNSUPPORTED;
	}

	BCS_SHARED BCS_RESULT base_cache_file_shared_file_type_to_gen3_cache_file_shared_file_type(::e_cache_file_shared_file_type base_cache_file_shared_file_type, e_cache_file_shared_file_type& gen3_cache_file_shared_file_type)
	{
		switch (base_cache_file_shared_file_type)
		{
		case ::_shared_file_type_none:
			gen3_cache_file_shared_file_type = gen3::_shared_file_type_none;
			return BCS_S_OK;
		case ::_shared_file_type_unknown0:
			gen3_cache_file_shared_file_type = gen3::_shared_file_type_unknown0;
			return BCS_S_OK;
		case ::_shared_file_type_unknown1:
			gen3_cache_file_shared_file_type = gen3::_shared_file_type_unknown1;
			return BCS_S_OK;
		case ::_shared_file_type_unknown2:
			gen3_cache_file_shared_file_type = gen3::_shared_file_type_unknown2;
			return BCS_S_OK;
		}
		return BCS_E_UNSUPPORTED;
	}

}
