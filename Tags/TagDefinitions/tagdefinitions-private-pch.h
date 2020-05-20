#pragma once

#define BLOFELD_INCLUDE_GROUPS

#include <Platform\platform-public-pch.h>
#include <Shared/Blam/blamlib-public-pch.h>

#include "tagdefinitions-public-pch.h"
#include "blofeld/halo4_validation_data.h"

namespace blofeld
{
#define _countof_safe(value) (sizeof(value) / sizeof(value[0]))

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

#define TAG_STRUCT_FIELDS_FORWARD(tag_fields_name) \
extern s_tag_field CONCAT(tag_fields_name, _fields)[];

#define TAG_STRUCT_SUFFIX_FIELDS_FORWARD(tag_fields_name) \
extern s_tag_field CONCAT(tag_fields_name, _fields)[];

#define TAG_BLOCK_STRUCT_FORWARD(tag_struct_name) \
extern s_tag_struct_definition CONCAT(tag_struct_name, _struct);

#define TAG_STRUCT_FORWARD(tag_struct_name) \
extern s_tag_struct_definition CONCAT(tag_struct_name, _struct_definition);

#define TAG_BLOCK_FORWARD(tag_block_name) \
extern s_tag_block_definition CONCAT(tag_block_name, _block);

#define TAG_GROUP_FORWARD(tag_group_name) \
extern s_tag_group CONCAT(tag_group_name, _group);


#define TAG_FIELDS(tag_fields_name) \
s_tag_field CONCAT(tag_fields_name, _fields)[] =

#define TAG_STRUCT(tag_struct_name) \
TAG_STRUCT_FIELDS_FORWARD(CONCAT(tag_struct_name, _struct_definition)) \
s_tag_struct_definition CONCAT(tag_struct_name, _struct_definition) = { STRINGIFY(tag_struct_name), STRINGIFY(tag_struct_name), __FILE__, __LINE__, {0}, CONCAT(tag_struct_name, _struct_definition_fields) }; \
TAG_FIELDS(CONCAT(tag_struct_name, _struct_definition))

#define TAG_BLOCK_STRUCT(tag_struct_name) \
TAG_STRUCT_SUFFIX_FIELDS_FORWARD(CONCAT(tag_struct_name, _struct)) \
s_tag_struct_definition CONCAT(tag_struct_name, _struct) = { STRINGIFY(tag_struct_name)"_struct", STRINGIFY(tag_struct_name)"_struct", __FILE__, __LINE__, {0}, CONCAT(tag_struct_name, _struct_fields) }; \
TAG_FIELDS(CONCAT(tag_struct_name, _struct))

#define TAG_BLOCK(tag_block_name, block_count) \
TAG_BLOCK_STRUCT_FORWARD(CONCAT(tag_block_name, _block)) \
s_tag_block_definition CONCAT(tag_block_name, _block) = { STRINGIFY(tag_block_name)"_block", STRINGIFY(tag_block_name)"_block", __FILE__, __LINE__, block_count, #block_count, CONCAT(tag_block_name, _block_struct) }; \
TAG_BLOCK_STRUCT(CONCAT(tag_block_name, _block))

#define TAG_GROUP(tag_group_name, group_tag) \
TAG_BLOCK_FORWARD(tag_group_name) \
s_tag_group CONCAT(tag_group_name, _group) = { STRINGIFY(tag_group_name), group_tag, INVALID_TAG, CONCAT(tag_group_name, _block), nullptr }; \
TAG_BLOCK(tag_group_name, 1)

#define TAG_GROUP_INHERIT(tag_group_name, group_tag, parent_tag_group_name, parent_group_tag) \
TAG_BLOCK_FORWARD(tag_group_name) \
s_tag_group CONCAT(tag_group_name, _group) = { STRINGIFY(tag_group_name), group_tag, parent_group_tag, CONCAT(tag_group_name, _block), &CONCAT(parent_tag_group_name, _group) }; \
TAG_BLOCK(tag_group_name, 1)

#define TAG_BLOCK_FROM_STRUCT(tag_block_name, block_count, block_name) \
s_tag_block_definition CONCAT(tag_block_name, _block) = { STRINGIFY(tag_block_name)"_block", STRINGIFY(tag_block_name)"_block", __FILE__, __LINE__, block_count, #block_count, block_name };

#define TAG_GROUP_FROM_BLOCK(tag_group_name, group_tag, block_name) \
s_tag_group CONCAT(tag_group_name, _group) = { STRINGIFY(tag_group_name), group_tag, INVALID_TAG, block_name, nullptr };

#define TAG_GROUP_INHERIT_FROM_BLOCK(tag_group_name, group_tag, parent_tag_group_name, parent_group_tag, block_name) \
s_tag_group CONCAT(tag_group_name, _group) = { STRINGIFY(tag_group_name), group_tag, parent_group_tag, block_name, &CONCAT(parent_tag_group_name, _group) };

#define TAG_REFERENCE(tag_reference_symbolname, ...) \
s_tag_reference_definition tag_reference_symbolname = s_tag_reference_definition(__VA_ARGS__)

#define TAG_REFERENCE_GROUP(tag_reference_symbolname, ...) \
extern unsigned long CONCAT(tag_reference_symbolname, _reference)[]; \
s_tag_reference_definition tag_reference_symbolname = s_tag_reference_definition(__VA_ARGS__); \
unsigned long CONCAT(tag_reference_symbolname, _reference)[] =

#define STRINGS(name) \
extern const char* CONCAT(name, _strings)[] =

#define STRING_LIST(name, string_list, count) \
s_string_list_definition name = { STRINGIFY(name), count, static_cast<const char**>(string_list), __FILE__, __LINE__ }

#define _TAG_ENUM(name, count) \
extern const char* CONCAT(name, _strings)[]; \
s_string_list_definition name = { STRINGIFY(name), count, CONCAT(name, _strings), __FILE__, __LINE__ }; \
const char* CONCAT(name, _strings)[] = 

#define _TAG_ENUM_EMPTY(name, count) \
extern const char* CONCAT(name, _strings)[]; \
s_string_list_definition name = { STRINGIFY(name), count, CONCAT(name, _strings), __FILE__, __LINE__ }; \
const char* CONCAT(name, _strings)[] = { "" }

#define TAG_ARRAY(tag_array_name, array_count) \
TAG_STRUCT_FORWARD(tag_array_name) \
s_tag_array_definition CONCAT(tag_array_name, _array) = { STRINGIFY(tag_array_name)"_array", STRINGIFY(tag_array_name)"_array", __FILE__, __LINE__, array_count, #array_count, CONCAT(tag_array_name, _struct_definition) }; \
TAG_STRUCT(tag_array_name)

}
