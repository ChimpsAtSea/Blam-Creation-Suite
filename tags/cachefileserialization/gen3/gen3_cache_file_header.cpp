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
