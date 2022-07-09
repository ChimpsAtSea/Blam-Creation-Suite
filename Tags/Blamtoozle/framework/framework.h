#pragma once

#include "pointer.h"
#include "tag_definition_reader.h"
#include "tag_definition_manager.h"
#include "minidump_tag_definition_reader.h"
#include "field_type.h"
#include "tag_string_list_definition.h"
#include "tag_data_definition.h"
#include "tag_reference_definition.h"
#include "tag_field.h"
#include "tag_group_definition.h"
#include "tag_block_definition.h"
#include "tag_array_definition.h"
#include "tag_data_definition.h"
#include "tag_api_interop_definition.h"
#include "tag_struct_definition.h"
#include "tag_resource_definition.h"
#include "tag_block_index_custom_search_definition.h"

extern void nuke_trailing_extension(char* string, const char* extension);
extern void replace_trailing_extension(char* string, const char* extension, const char* replacement);
extern void cleanup_code_symbol_name(char* buffer);
