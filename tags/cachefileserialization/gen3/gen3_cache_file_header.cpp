#include "cachefileserialization-private-pch.h"

#if \
defined(BCS_BUILD_HIGH_LEVEL_HALO_3) || \
defined(BCS_BUILD_HIGH_LEVEL_HALO_3_ODST) || \
defined(BCS_BUILD_HIGH_LEVEL_ELDORADO) || \
defined(BCS_BUILD_HIGH_LEVEL_HALO_REACH) || \
defined(BCS_BUILD_HIGH_LEVEL_HALO_4) || \
defined(BCS_BUILD_HIGH_LEVEL_GROUNDHOG)

template<> BCS_SHARED void byteswap_inplace(gen3::s_cache_file_section_file_bounds& value)
{
	byteswap_inplace(value.offset);
	byteswap_inplace(value.size);
}

template<> BCS_SHARED void byteswap_inplace(gen3::s_network_http_request_hash& value)
{

}

template<> BCS_SHARED void byteswap_inplace(gen3::s_rsa_signature& value)
{

}

template<> BCS_SHARED void byteswap_inplace(gen3::s_file_last_modification_date& value)
{
	byteswap_inplace(value.filetime_low);
	byteswap_inplace(value.filetime_high);
}

template<> BCS_SHARED void byteswap_inplace(gen3::s_cache_file_insertion_point_resource_usage& value)
{
	// #TODO
}

#endif
