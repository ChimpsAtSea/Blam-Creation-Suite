#pragma once

#include "blofeld.h"
#include "blofeld/constants.h"
#include "types/field_type.h"
#include "types/field_id.h"
#include "types/tag_group.h"
#include "types/tag_struct_definition.h"
#include "types/tag_block_definition.h"
#include "types/tag_array_definition.h"
#include "types/tag_reference_definition.h"
#include "types/tag_interop_definition.h"
#include "types/string_list_definition.h"
#include "types/tag_field.h"

#ifndef BLOFELD_EXCLUDE_STRUCTS
#ifdef BLOFELD_DLL_EXPORT
#include <Platform\platform-exports-pch.h>
#endif
#define s_tag_block_definition BCS_DEBUG_API s_tag_block_definition
#define s_tag_struct_definition BCS_DEBUG_API s_tag_struct_definition
#define s_tag_group BCS_DEBUG_API s_tag_group
#include "blofeld/tag_groups.h"
#include "slipspace/infinite_flight1.h"
#include "slipspace/infinite_flight2.h"
#include "slipspace/infinite.h"
#include "blamlib/halo3_tools.h"
#include "blamlib/halo2_tools.h"
#include "blamlib/halo1_tools.h"
#include "blofeld/tag_structs.h"
#undef s_tag_block_definition
#undef s_tag_struct_definition
#undef s_tag_group
#endif
#include "tag_groups/tag_groups.h"
#include "blofeld/validation.h"

#include "tag_group_info.h"

#include "tag_byteswap.h"
#include "definition_migration.h"
