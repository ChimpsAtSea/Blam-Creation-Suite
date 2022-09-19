#pragma once

#include "blofeld.h"
#include "types/tag_versioning.h"
#include "types/field_type.h"
#include "types/field_id.h"
#include "types/field_set.h"
#include "types/tag_reference_flags.h"
#include "types/memory_attributes.h"
#include "types/persistent_identifier.h"
#include "types/tag_group.h"
#include "types/tag_data_definition.h"
#include "types/tag_struct_definition.h"
#include "types/tag_block_definition.h"
#include "types/tag_array_definition.h"
#include "types/tag_reference_definition.h"
#include "types/tag_resource_definition.h"
#include "types/tag_interop_definition.h"
#include "types/block_index_custom_search_definition.h"
#include "types/string_list_definition.h"
#include "types/tag_field.h"

#ifndef BLOFELD_EXCLUDE_STRUCTS
#ifdef BLOFELD_DLL_EXPORT
#include <Platform\platform-exports-pch.h>
#endif
#define extern extern BCS_DEBUG_API

#include "slipspace/infinite_flight1.h"
#include "slipspace/infinite_flight2.h"
#include "slipspace/infinite_release.h"
#include "slipspace/infinite.h"

// #TODO: Fix this
namespace blofeld { namespace infinite { namespace pc64 { using namespace blofeld::infinite; } } }

#include "blamlib/halo1-tools-pc64.h"
#include "blamlib/halo2-tools-pc64.h"
#include "blamlib/halo3odst-tools-pc64.h"
#include "blamlib/halo3-tools-pc64.h"
#include "blamlib/halo4-tagtest-xbox360.h"
#include "blamlib/haloreach-tagtest-xbox360.h"

#undef extern
#endif
#include "tag_groups/tag_groups.h"

#include "tag_groups/halo1-tools-pc64-groups.h"
#include "tag_groups/halo2-tools-pc64-groups.h"
#include "tag_groups/halo3odst-tools-pc64-groups.h"
#include "tag_groups/halo3-tools-pc64-groups.h"
#include "tag_groups/halo4-tagtest-xbox360-groups.h"
#include "tag_groups/haloreach-tagtest-xbox360-groups.h"

#include "blamlib_byteswap.h"
#include "definition_migration.h"
#include "tag_struct_definition_view.h"
