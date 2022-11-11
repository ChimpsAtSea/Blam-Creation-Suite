#pragma once

#include "base\cache_file_header.h"
#include "base\cache_file_api.h"
#include "base\cache_file_reader.h"
#include "base\cache_cluster.h"
#include "base\debug_reader.h"
#include "base\localization_reader.h"
#include "base\resource_reader.h"
#include "base\tag_reader.h"
#include "base\tag_group.h"
#include "base\tag_instance.h"
#include "base\api_interop.h"

#include "halo1\halo1_cache_file_header.h"
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_1
#include "halo1\halo1_tag_group_hierarchy.h"
#include "halo1\halo1_cache_file_reader.h"
#include "halo1\halo1_cache_cluster.h"
#include "halo1\halo1_debug_reader.h"
#include "halo1\halo1_localization_reader.h"
#include "halo1\halo1_resource_reader.h"
#include "halo1\halo1_tag_reader.h"
#include "halo1\halo1_tag_group.h"
#include "halo1\halo1_tag_instance.h"
#endif

#ifdef BCS_BUILD_HIGH_LEVEL_HALO_3
#include "halo3\halo3_codec.h"
#include "halo3\halo3_api_interop.h"
#include "halo3\halo3_cache_file_reader.h"
#include "halo3\halo3_cache_cluster.h"
#include "halo3\halo3_debug_reader.h"
#include "halo3\halo3_localization_reader.h"
#include "halo3\halo3_resource_reader.h"
#include "halo3\halo3_tag_reader.h"
#include "halo3\halo3_tag_group.h"
#include "halo3\halo3_tag_instance.h"
#endif

#ifdef BCS_BUILD_HIGH_LEVEL_HALO_4
/*
#include "halo4\halo4_codec.h"
#include "halo4\halo4_resource_container.h"
#include "halo4\halo4_api_interop.h"
#include "halo4\halo4_tag_group_hierarchy.h"
#include "halo4\halo4_cache_file_header.h"
#include "halo4\halo4_cache_file_reader.h"
#include "halo4\halo4_cache_cluster.h"
#include "halo4\halo4_debug_reader.h"
#include "halo4\halo4_localization_reader.h"
#include "halo4\halo4_resource_reader.h"
#include "halo4\halo4_tag_reader.h"
#include "halo4\halo4_tag_group.h"
#include "halo4\halo4_tag_instance.h"
*/
#endif

#include "infinite\infinite_cache_file_header.h"
#ifdef BCS_BUILD_HIGH_LEVEL_HALO_INFINITE
#include "infinite\infinite_cache_file_reader.h"
#include "infinite\infinite_cache_cluster.h"
#include "infinite\infinite_debug_reader.h"
#include "infinite\infinite_localization_reader.h"
#include "infinite\infinite_resource_reader.h"
#include "infinite\infinite_tag_reader.h"
#include "infinite\infinite_tag_group.h"
#include "infinite\infinite_tag_instance.h"
#include "infinite\infinite_ucs_reader.h"
#include "infinite\infinite_generic_module_file_entry.h"
#include "infinite\infinite_file_entry_block_map.h"
#endif
