#pragma once

#ifndef BLOFELD_TAG_DEFINITIONS
#define BLOFELD_TAG_DEFINITIONS 1
#endif

#include <Platform\platform-public-pch.h>
#include <TemplateLibrary\templatelibrary-public-pch.h>
#include <Shared\Blam\blamlib-public-pch.h>
#include <SymbolsRuntime\symbolsruntime-public-pch.h>

#define BLOFELD_DLL_EXPORT
#include "tagdefinitions-public-pch.h"
//#include "blofeld/gen3_xbox360_validation_data.h"

namespace blofeld
{
#define _countof_safe(value) (sizeof(value) / sizeof(value[0]))

#define PERSISTENT_ID_EMPTY { 0, 0, 0, 0 }
#define PERSISTENT_ID_UNKNOWN { UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX }

#define VERSION_RANGE(minimum_version, maximum_version) minimum_version, maximum_version
#define VERSION_MAX(maximum_version) _build_not_set, maximum_version
#define VERSION_MIN(minimum_version) minimum_version, _build_not_set

#define FIELD(type, ...) { type, __FILE__, __LINE__ , ##__VA_ARGS__ }

	struct s_tag_field;
	struct s_tag_group;
	struct s_tag_reference_definition;
	struct s_tag_struct_definition;
	struct s_tag_block_definition;
	struct s_tag_array_definition;
	struct s_string_list_definition;


#define TAG_FIELDS(tag_fields_name) \
s_tag_field CONCAT(tag_fields_name, _fields)[] =

// symbol, pretty_name, struct_name, persistent_identifier, [aligmnment_bits]
#define TAG_STRUCT_V6(symbol, pretty_name, struct_name, runtime_flags, memory_attributes, persistent_identifier, ...) \
extern s_tag_field _##symbol##_fields[]; \
s_tag_struct_definition symbol = s_tag_struct_definition(pretty_name, #symbol, struct_name, __FILE__, __LINE__, runtime_flags, memory_attributes, persistent_identifier, _##symbol##_fields, __VA_ARGS__); \
s_tag_field _##symbol##_fields[] =

#define TAG_STRUCT(symbol, pretty_name, name, struct_name, runtime_flags, memory_attributes, persistent_identifier, ...) \
extern s_tag_field _##symbol##_fields[]; \
s_tag_struct_definition symbol = s_tag_struct_definition(pretty_name, name, struct_name, __FILE__, __LINE__, runtime_flags, memory_attributes, persistent_identifier, _##symbol##_fields, __VA_ARGS__); \
s_tag_field _##symbol##_fields[] =

#define VERSIONED_TAG_STRUCT(symbol, pretty_name, name, struct_name, runtime_flags, memory_attributes, persistent_identifier, ...) \
	TAG_STRUCT(symbol, pretty_name, name, struct_name, SET_MANDRILL_VERSIONING | runtime_flags, memory_attributes, persistent_identifier, __VA_ARGS__)

#define TAG_DATA(symbol, pretty_name, flags, alignment_bits, maximum_size, ...) \
s_tag_data_definition symbol = s_tag_data_definition(#symbol, pretty_name, #symbol, flags, maximum_size, "", __FILE__, __LINE__, alignment_bits );

#define TAG_GROUP_V7(symbol, group_tag, parent_group, parent_group_tag, block) \
s_tag_group symbol = s_tag_group(#symbol, #symbol, #symbol, __FILE__, __LINE__, #group_tag, group_tag, parent_group_tag, block, parent_group);

#define TAG_GROUP(name, symbol, group_tag, version, parent_group, block) \
s_tag_group symbol = s_tag_group(name, name, #symbol, __FILE__, __LINE__, #group_tag, group_tag, version, block, parent_group);

#define TAG_BLOCK_FROM_STRUCT_V7(symbol, name, max_count, struct_definition) \
s_tag_block_definition symbol = s_tag_block_definition(name, name, #symbol, __FILE__, __LINE__, [](s_engine_platform_build engine_platform_build) { using namespace blofeld; return static_cast<unsigned long>(max_count); }, #max_count, struct_definition );

#define TAG_BLOCK_FROM_STRUCT(symbol, display_name, name, max_count, struct_definition) \
s_tag_block_definition symbol = s_tag_block_definition(display_name, name, #symbol, __FILE__, __LINE__, [](s_engine_platform_build engine_platform_build) { using namespace blofeld; return static_cast<unsigned long>(max_count); }, #max_count, struct_definition );

#define TAG_ARRAY_FROM_STRUCT(symbol, pretty_name, count, struct_definition) \
s_tag_array_definition symbol = { #symbol, pretty_name, __FILE__, __LINE__, [](s_engine_platform_build engine_platform_build) { using namespace blofeld; return static_cast<unsigned long>(count); }, #count, struct_definition };

#define TAG_REFERENCE(tag_reference_symbolname, ...) \
s_tag_reference_definition tag_reference_symbolname = s_tag_reference_definition(#tag_reference_symbolname, #tag_reference_symbolname, #tag_reference_symbolname, __VA_ARGS__)

#define TAG_REFERENCE_GROUP(tag_reference_symbolname, ...) \
extern uint32_t CONCAT(tag_reference_symbolname, _tag_groups)[]; \
s_tag_reference_definition tag_reference_symbolname = s_tag_reference_definition(#tag_reference_symbolname, #tag_reference_symbolname, #tag_reference_symbolname, INVALID_TAG, CONCAT(tag_reference_symbolname, _tag_groups), __VA_ARGS__); \
uint32_t CONCAT(tag_reference_symbolname, _tag_groups)[] =

#define STRINGS(name) \
blofeld::s_string_entry name##_strings[] = 

#define STRING_LIST(string_list_symbol, strings, count, ...) \
blofeld::s_string_list_definition string_list_symbol = { #string_list_symbol, #string_list_symbol, __FILE__, __LINE__, strings, count, __VA_ARGS__ }

#define TAG_INTEROP(symbol, tag_interop_name, tag_interop_structure, persistent_identifier) \
s_tag_interop_definition symbol = { #symbol, tag_interop_name, __FILE__, __LINE__, tag_interop_structure, persistent_identifier }

#define TAG_RESOURCE(symbol, tag_resource_name, tag_resource_structure) \
s_tag_resource_definition symbol = { #symbol, tag_resource_name, __FILE__, __LINE__, tag_resource_structure }

#define BLOCK_INDEX_CUSTOM_SEARCH_DEFINITION(symbol, block_index_custom_search_name) \
s_block_index_custom_search_definition symbol = { #symbol, block_index_custom_search_name, __FILE__, __LINE__ }

}
