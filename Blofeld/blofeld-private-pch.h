#pragma once

#define BLOFELD_INCLUDE_GROUPS

#include <Shared/shared-public-pch.h>
#include <SymbolsLib/symbolslib-public-pch.h>
#include <OpusFramework/opusframework-public-pch.h>
#include <blamlib/cseries/cseries.h>

#include "blofeld-public-pch.h"
#include "halo4_validation_data.h"

namespace blofeld
{
#define VERSION_RANGE(minimum_version, maximum_version) minimum_version, maximum_version
#define VERSION_MAX(maximum_version) _build_not_set, maximum_version
#define VERSION_MIN(minimum_version) minimum_version, _build_not_set

#define FIELD(type, ...) { type, __FILE__, __LINE__ , ##__VA_ARGS__ }

	struct s_tag_field;
	struct s_tag_struct;
	struct s_tag_block_definition;
	struct s_tag_group;

#define TAG_STRUCT_FIELDS_FORWARD(tag_fields_name) \
extern s_tag_field CONCAT(tag_fields_name, _fields)[];

#define TAG_STRUCT_SUFFIX_FIELDS_FORWARD(tag_fields_name) \
extern s_tag_field CONCAT(tag_fields_name, _fields)[];

#define TAG_BLOCK_STRUCT_FORWARD(tag_struct_name) \
extern s_tag_struct CONCAT(tag_struct_name, _struct);

#define TAG_BLOCK_FORWARD(tag_block_name) \
extern s_tag_block_definition CONCAT(tag_block_name, _block);

#define TAG_GROUP_FORWARD(tag_group_name) \
extern s_tag_group CONCAT(tag_group_name, _group);


#define TAG_FIELDS(tag_fields_name) \
s_tag_field CONCAT(tag_fields_name, _fields)[] =

#define TAG_STRUCT(tag_struct_name) \
TAG_STRUCT_FIELDS_FORWARD(CONCAT(tag_struct_name, _struct_definition)) \
s_tag_struct CONCAT(tag_struct_name, _struct_definition) = { #tag_struct_name, #tag_struct_name, {0}, CONCAT(tag_struct_name, _struct_definition_fields) }; \
TAG_FIELDS(CONCAT(tag_struct_name, _struct_definition))

#define TAG_STRUCT_SUFFIX(tag_struct_name) \
TAG_STRUCT_SUFFIX_FIELDS_FORWARD(CONCAT(tag_struct_name, _struct)) \
s_tag_struct CONCAT(tag_struct_name, _struct) = { #tag_struct_name"_struct", #tag_struct_name"_struct", {0}, CONCAT(tag_struct_name, _struct_fields) }; \
TAG_FIELDS(CONCAT(tag_struct_name, _struct))

#define TAG_BLOCK(tag_block_name, block_count) \
TAG_BLOCK_STRUCT_FORWARD(CONCAT(tag_block_name, _block)) \
s_tag_block_definition CONCAT(tag_block_name, _block) = { #tag_block_name"_block", #tag_block_name"_block", __FILE__, __LINE__, block_count, #block_count, CONCAT(tag_block_name, _block_struct) }; \
TAG_STRUCT_SUFFIX(CONCAT(tag_block_name, _block))

#define TAG_GROUP(tag_group_name, group_tag) \
TAG_BLOCK_FORWARD(tag_group_name) \
s_tag_group CONCAT(tag_group_name, _group) = { #tag_group_name, group_tag, INVALID_TAG, CONCAT(tag_group_name, _block), nullptr }; \
TAG_BLOCK(tag_group_name, 1)

#define TAG_GROUP_INHERIT(tag_group_name, group_tag, parent_tag_group_name, parent_group_tag) \
TAG_BLOCK_FORWARD(tag_group_name) \
s_tag_group CONCAT(tag_group_name, _group) = { #tag_group_name, group_tag, parent_group_tag, CONCAT(tag_group_name, _block), &CONCAT(parent_tag_group_name, _group) }; \
TAG_BLOCK(tag_group_name, 1)

#define TAG_BLOCK_FROM_STRUCT(tag_block_name, block_count, block_name) \
s_tag_block_definition CONCAT(tag_block_name, _block) = { #tag_block_name"_block", #tag_block_name"_block", __FILE__, __LINE__, block_count, #block_count, block_name };

#define TAG_GROUP_FROM_BLOCK(tag_group_name, group_tag, block_name) \
s_tag_group CONCAT(tag_group_name, _group) = { #tag_group_name, group_tag, INVALID_TAG, block_name, nullptr };

	//#define TAG_GROUP_INHERIT(tag_group_name, group_tag, parent_tag_group_name, parent_group_tag) \
	//s_tag_field CONCAT(tag_group_name, _fields)[]; \
	//s_tag_struct CONCAT(tag_group_name, _struct) = { #tag_group_name"_block_struct", #tag_group_name"_block_struct", {0}, CONCAT(tag_group_name, _fields) }; \
	//s_tag_block CONCAT(tag_group_name, _block) = { #tag_group_name"_block", #tag_group_name"_block", __FILE__, __LINE__, 1, "1", CONCAT(tag_group_name, _struct) }; \
	//s_tag_group CONCAT(tag_group_name, _group) = { #tag_group_name, group_tag, parent_group_tag, CONCAT(tag_group_name, _block), &CONCAT(parent_tag_group_name, _group) }; \
	//s_tag_field CONCAT(tag_group_name, _fields)[] =



#define TAG_REFERENCE_DEFINITION(name, tag_group) \
s_tag_reference name = { 0, tag_group, 0 };

#define TAG_REFERENCE_DEFINITION_EX(name, tag_group) \
extern unsigned long CONCAT(name, _tag_groups)[]; \
s_tag_reference name = { 0, INVALID_TAG, CONCAT(name, _tag_groups) }; \
unsigned long CONCAT(name, _tag_groups)[] =

}
