#pragma once

#include "blofeld.h"
#include "blamlib_string_parser.h"
#include "blofeld/constants.h"
#include "types/field_type.h"
#include "types/tag_group.h"
#include "types/tag_struct_definition.h"
#include "types/tag_block_definition.h"
#include "types/tag_array_definition.h"
#include "types/tag_reference_definition.h"
#include "types/tag_interop_definition.h"
#include "types/string_list_definition.h"
#include "types/tag_field.h"

#ifndef BLOFELD_EXCLUDE_STRUCTS
#include "blofeld/tag_groups.h"
#include "blofeld/halo1.h"
#include "blofeld/tag_structs.h"
#endif
#include "blofeld/validation.h"

#include "tag_group_info.h"

#include "tag_byteswap.h"
