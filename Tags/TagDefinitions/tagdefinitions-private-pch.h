#pragma once

#ifndef BLOFELD_TAG_DEFINITIONS
#define BLOFELD_TAG_DEFINITIONS 1
#endif

#include <Platform\platform-public-pch.h>
#include <Shared\Blam\blamlib-public-pch.h>
#include <TemplateLibrary\templatelibrary-public-pch.h>
#include <SymbolsRuntime\symbolsruntime-public-pch.h>

#define BLOFELD_DLL_EXPORT
#include "tagdefinitions-public-pch.h"
//#include "blofeld/gen3_xbox360_validation_data.h"

#include "tagdefinitions_tracked_memory.h"

namespace blofeld
{
#define _countof_safe(value) (sizeof(value) / sizeof(value[0]))

#define PERSISTENT_ID_UNKNOWN { 0, 0, 0, 0 }

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

#define V5_TAG_STRUCT_FIELDS_FORWARD(tag_fields_name) \
extern s_tag_field CONCAT(tag_fields_name, _fields)[];

#define V5_TAG_STRUCT_SUFFIX_FIELDS_FORWARD(tag_fields_name) \
extern s_tag_field CONCAT(tag_fields_name, _fields)[];

#define V5_TAG_STRUCT_FORWARD(tag_struct_name) \
extern s_tag_struct_definition CONCAT(tag_struct_name, _struct_definition);

#define V5_TAG_BLOCK_FORWARD(tag_block_name) \
extern s_tag_block_definition tag_block_name;

#define V5_TAG_GROUP_FORWARD(tag_group_name) \
extern s_tag_group CONCAT(tag_group_name, _group);

#define TAG_FIELDS(tag_fields_name) \
s_tag_field CONCAT(tag_fields_name, _fields)[] =

// symbol, pretty_name, struct_name, persistent_identifier, [aligmnment_bits]
#define TAG_STRUCT_V6(symbol, pretty_name, struct_name, runtime_flags, memory_attributes, persistent_identifier, ...) \
extern s_tag_field symbol##_fields[]; \
s_tag_struct_definition symbol = s_tag_struct_definition(pretty_name, #symbol, struct_name, __FILE__, __LINE__, runtime_flags, memory_attributes, persistent_identifier, symbol##_fields, __VA_ARGS__); \
s_tag_field symbol##_fields[] =

#define TAG_STRUCT(symbol, pretty_name, name, struct_name, runtime_flags, memory_attributes, persistent_identifier, ...) \
extern s_tag_field symbol##_fields[]; \
s_tag_struct_definition symbol = s_tag_struct_definition(pretty_name, name, struct_name, __FILE__, __LINE__, runtime_flags, memory_attributes, persistent_identifier, symbol##_fields, __VA_ARGS__); \
s_tag_field symbol##_fields[] =

// symbol, pretty_name, max_count, struct_name, persistent_identifier, [aligmnment_bits]
#define TAG_BLOCK(symbol, pretty_name, max_count, struct_name, runtime_flags, memory_attributes, persistent_identifier, ...) \
extern s_tag_field symbol##_struct_definition_fields[]; \
s_tag_struct_definition symbol##_struct_definition = s_tag_struct_definition(#symbol "_struct_definition", #symbol "_struct_definition", struct_name, __FILE__, __LINE__, runtime_flags, memory_attributes, persistent_identifier, symbol##_struct_definition_fields, __VA_ARGS__); \
s_tag_block_definition symbol = s_tag_block_definition(pretty_name, pretty_name, #symbol, __FILE__, __LINE__, [](s_engine_platform_build engine_platform_build) { using namespace blofeld; return static_cast<unsigned long>(max_count); }, #max_count, symbol##_struct_definition ); \
s_tag_field symbol##_struct_definition_fields[] =

// symbol, pretty_name, count, struct_name, persistent_identifier, [aligmnment_bits]
#define TAG_ARRAY(symbol, pretty_name, count, struct_name, runtime_flags, memory_attributes, persistent_identifier, ...) \
extern s_tag_field symbol##_struct_definition_fields[]; \
s_tag_struct_definition symbol##_struct_definition = s_tag_struct_definition(#symbol "_struct_definition", #symbol "_struct_definition", struct_name, __FILE__, __LINE__, runtime_flags, memory_attributes, persistent_identifier, symbol##_struct_definition_fields, __VA_ARGS__); \
s_tag_array_definition symbol = { #symbol, pretty_name, __FILE__, __LINE__, [](s_engine_platform_build engine_platform_build) { using namespace blofeld; return static_cast<unsigned long>(count); }, #count, symbol##_struct_definition }; \
s_tag_field symbol##_struct_definition_fields[] =

#define TAG_DATA(symbol, pretty_name, flags, alignment_bits, maximum_size, ...) \
s_tag_data_definition symbol = s_tag_data_definition(#symbol, pretty_name, flags, maximum_size, "", __FILE__, __LINE__, alignment_bits );

//// symbol, group_tag, parent_group, parent_group_tag, max_count, struct_name, persistent_identifier, [aligmnment_bits]
//#define TAG_GROUP(symbol, group_tag, parent_group, parent_group_tag, max_count, struct_name, persistent_identifier, ...) \
//extern s_tag_field symbol##_struct_definition_fields[]; \
//s_tag_struct_definition symbol##_struct_definition = s_tag_struct_definition(#symbol "_struct_definition", #symbol "_struct_definition", struct_name, __FILE__, __LINE__, persistent_identifier, symbol##_struct_definition_fields, __VA_ARGS__); \
//s_tag_block_definition symbol##_block = s_tag_block_definition(#symbol "_block", #symbol "_block", __FILE__, __LINE__, [](s_engine_platform_build engine_platform_build) { using namespace blofeld; return static_cast<unsigned long>(max_count); }, #max_count, symbol##_struct_definition ); \
//s_tag_group symbol = s_tag_group(#symbol, group_tag, parent_group_tag, symbol##_block, parent_group); \
//s_tag_field symbol##_struct_definition_fields[] =

#define TAG_GROUP_V2(name, symbol, group_tag, parent_group, parent_group_tag, block) \
s_tag_group symbol = s_tag_group(name, __FILE__, __LINE__, #group_tag, group_tag, parent_group_tag, block, parent_group);

// symbol, group_tag, parent_group, parent_group_tag, block
#define TAG_GROUP(symbol, group_tag, parent_group, parent_group_tag, block) \
s_tag_group symbol = s_tag_group(#symbol, __FILE__, __LINE__, #group_tag, group_tag, parent_group_tag, block, parent_group);

#define TAG_BLOCK_FROM_STRUCT(symbol, name, max_count, struct_definition) \
s_tag_block_definition symbol = s_tag_block_definition(name, name, #symbol, __FILE__, __LINE__, [](s_engine_platform_build engine_platform_build) { using namespace blofeld; return static_cast<unsigned long>(max_count); }, #max_count, struct_definition );

#define TAG_BLOCK_FROM_STRUCT_V2(symbol, display_name, name, max_count, struct_definition) \
s_tag_block_definition symbol = s_tag_block_definition(display_name, name, #symbol, __FILE__, __LINE__, [](s_engine_platform_build engine_platform_build) { using namespace blofeld; return static_cast<unsigned long>(max_count); }, #max_count, struct_definition );

#define TAG_ARRAY_FROM_STRUCT(symbol, pretty_name, count, struct_definition) \
s_tag_array_definition symbol = { #symbol, pretty_name, __FILE__, __LINE__, [](s_engine_platform_build engine_platform_build) { using namespace blofeld; return static_cast<unsigned long>(count); }, #count, struct_definition };



#define V5_TAG_STRUCT_V6(tag_struct_name) \
V5_TAG_STRUCT_FIELDS_FORWARD(CONCAT(tag_struct_name, _struct_definition)) \
s_tag_struct_definition CONCAT(tag_struct_name, _struct_definition) = { STRINGIFY(tag_struct_name), STRINGIFY(tag_struct_name), STRINGIFY(CONCAT(tag_struct_name, _struct_definition)), __FILE__, __LINE__, {0}, CONCAT(tag_struct_name, _struct_definition_fields) }; \
TAG_FIELDS(CONCAT(tag_struct_name, _struct_definition))

#define V5_TAG_BLOCK_STRUCT(tag_struct_name) \
V5_TAG_STRUCT_SUFFIX_FIELDS_FORWARD(CONCAT(tag_struct_name, _struct_definition)) \
s_tag_struct_definition CONCAT(tag_struct_name, _struct_definition) = { STRINGIFY(tag_struct_name)"_struct_definition", STRINGIFY(tag_struct_name)"_struct_definition", STRINGIFY(CONCAT(tag_struct_name, _struct_definition)), __FILE__, __LINE__, {0}, CONCAT(tag_struct_name, _struct_definition_fields) }; \
TAG_FIELDS(CONCAT(tag_struct_name, _struct_definition))

#define V5_TAG_BLOCK(tag_block_name, block_count) \
V5_TAG_STRUCT_FORWARD(tag_block_name) \
s_tag_block_definition tag_block_name = { STRINGIFY(tag_block_name), STRINGIFY(tag_block_name), STRINGIFY(tag_block_name), __FILE__, __LINE__, [](s_engine_platform_build engine_platform_build) { using namespace blofeld; return static_cast<unsigned long>(block_count); }, #block_count, CONCAT(tag_block_name, _struct_definition) }; \
V5_TAG_BLOCK_STRUCT(tag_block_name)

#define V5_TAG_GROUP(tag_group_name, group_tag) \
V5_TAG_BLOCK_FORWARD(CONCAT(tag_group_name, _block)) \
s_tag_group CONCAT(tag_group_name, _group) = { STRINGIFY(tag_group_name), __FILE__, __LINE__, STRINGIFY(group_tag), group_tag, INVALID_TAG, CONCAT(tag_group_name, _block), nullptr }; \
V5_TAG_BLOCK(CONCAT(tag_group_name, _block), 1)

#define V5_TAG_GROUP_INHERIT(tag_group_name, group_tag, parent_tag_group_name, parent_group_tag) \
V5_TAG_BLOCK_FORWARD(CONCAT(tag_group_name, _block)) \
s_tag_group CONCAT(tag_group_name, _group) = { STRINGIFY(tag_group_name), group_tag, parent_group_tag, CONCAT(tag_group_name, _block), &CONCAT(parent_tag_group_name, _group) }; \
V5_TAG_BLOCK(CONCAT(tag_group_name, _block), 1)

#define V5_TAG_BLOCK_FROM_STRUCT(block_name, block_count, struct_name) \
s_tag_block_definition block_name = { STRINGIFY(block_name), STRINGIFY(block_name), STRINGIFY(block_name), __FILE__, __LINE__, [](s_engine_platform_build engine_platform_build) { return static_cast<unsigned long>(block_count); }, #block_count, struct_name };

#define V5_TAG_GROUP_FROM_BLOCK(tag_group_name, group_tag, block_name) \
s_tag_group CONCAT(tag_group_name, _group) = { STRINGIFY(tag_group_name), __FILE__, __LINE__, STRINGIFY(group_tag), group_tag, blofeld::INVALID_TAG, block_name, nullptr };

#define V5_TAG_GROUP_INHERIT_FROM_BLOCK(tag_group_name, group_tag, parent_tag_group_name, parent_group_tag, block_name) \
s_tag_group CONCAT(tag_group_name, _group) = { STRINGIFY(tag_group_name), group_tag, parent_group_tag, block_name, &CONCAT(parent_tag_group_name, _group) };

#define TAG_REFERENCE(tag_reference_symbolname, ...) \
s_tag_reference_definition tag_reference_symbolname = s_tag_reference_definition(__VA_ARGS__)

#define TAG_REFERENCE_GROUP(tag_reference_symbolname, ...) \
extern unsigned long CONCAT(tag_reference_symbolname, _tag_groups)[]; \
s_tag_reference_definition tag_reference_symbolname = s_tag_reference_definition(INVALID_TAG, CONCAT(tag_reference_symbolname, _tag_groups), __VA_ARGS__); \
unsigned long CONCAT(tag_reference_symbolname, _tag_groups)[] =

#define STRINGS(name) \
blofeld::s_string_entry name##_strings[] = 

#define STRING_LIST(name, strings, count, ...) \
blofeld::s_string_list_definition name = { #name, __FILE__, __LINE__, strings, count, __VA_ARGS__ }


#define STRINGS_OLD(name) \
blofeld::t_string_list CONCAT(name, _strings) =

#define STRING_LIST_OLD(name, string_list, count) \
blofeld::s_string_list_definition name = { STRINGIFY(name), string_list, __FILE__, __LINE__ }

#define _TAG_ENUM(name, count) \
extern const char* CONCAT(name, _strings)[]; \
s_string_list_definition name = { STRINGIFY(name), count, CONCAT(name, _strings), __FILE__, __LINE__ }; \
const char* CONCAT(name, _strings)[] = 

#define _TAG_ENUM_EMPTY(name, count) \
extern const char* CONCAT(name, _strings)[]; \
s_string_list_definition name = { STRINGIFY(name), count, CONCAT(name, _strings), __FILE__, __LINE__ }; \
const char* CONCAT(name, _strings)[] = { "" }

#define V5_TAG_ARRAY(tag_array_name, array_count) \
V5_TAG_STRUCT_FORWARD(tag_array_name) \
s_tag_array_definition CONCAT(tag_array_name, _array) = { STRINGIFY(tag_array_name)"_array", STRINGIFY(tag_array_name)"_array", __FILE__, __LINE__, [](s_engine_platform_build engine_platform_build) { return static_cast<unsigned long>(array_count); }, #array_count, CONCAT(tag_array_name, _struct_definition) }; \
V5_TAG_STRUCT_V6(tag_array_name)

#define V5_TAG_ARRAY_FROM_STRUCT(tag_array_name, array_count, tag_array_struct) \
s_tag_array_definition CONCAT(tag_array_name, _array) = { STRINGIFY(tag_array_name)"_array", STRINGIFY(tag_array_name)"_array", __FILE__, __LINE__, [](s_engine_platform_build engine_platform_build) { return static_cast<unsigned long>(array_count); }, #array_count, tag_array_struct }

#define TAG_INTEROP_V6(tag_interop_name, tag_interop_structure) \
s_tag_interop_definition tag_interop_name = { STRINGIFY(tag_interop_name), __FILE__, __LINE__, tag_interop_structure, PERSISTENT_ID_UNKNOWN }

#define TAG_INTEROP(symbol, tag_interop_name, tag_interop_structure, persistent_identifier) \
s_tag_interop_definition symbol = { #symbol, tag_interop_name, __FILE__, __LINE__, tag_interop_structure, persistent_identifier }

#define TAG_RESOURCE(symbol, tag_resource_name, tag_resource_structure) \
s_tag_resource_definition symbol = { #symbol, tag_resource_name, __FILE__, __LINE__, tag_resource_structure }


}
