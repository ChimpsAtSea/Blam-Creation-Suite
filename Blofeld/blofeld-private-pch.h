#pragma once

#include <Shared/shared-public-pch.h>
#include <SymbolsLib/symbolslib-public-pch.h>
#include <OpusFramework/opusframework-public-pch.h>
#include <blamlib/source/cseries/cseries.h>

#include "blofeld-public-pch.h"
#include "halo4_validation_data.h"

#define VERSION_RANGE(minimum_version, maximum_version) minimum_version, maximum_version
#define VERSION_MAX(maximum_version) _build_not_set, maximum_version
#define VERSION_MIN(minimum_version) minimum_version, _build_not_set

#define FIELD(type, ...) { type, __FILE__, __LINE__ , ##__VA_ARGS__ }

#define TAG_GROUP(tag_group_name, group_tag) \
s_tag_field CONCAT(tag_group_name, _fields)[]; \
s_tag_struct CONCAT(tag_group_name, _field_set) = { #tag_group_name"_block_struct", #tag_group_name"_block_struct", {0}, CONCAT(tag_group_name, _fields) }; \
s_tag_block CONCAT(tag_group_name, _block) = { #tag_group_name"_block", #tag_group_name"_block", __FILE__, __LINE__, 1, "1", CONCAT(tag_group_name, _field_set) }; \
s_tag_group CONCAT(tag_group_name, _group) = { #tag_group_name, group_tag, INVALID_TAG, CONCAT(tag_group_name, _block), nullptr }; \
s_tag_field CONCAT(tag_group_name, _fields)[] =

#define TAG_GROUP_FROM_BLOCK(tag_group_name, group_tag, block_name) \
s_tag_group CONCAT(tag_group_name, _group) = { #tag_group_name, group_tag, INVALID_TAG, block_name, nullptr }; \

#define TAG_GROUP_INHERIT(tag_group_name, group_tag, parent_tag_group_name, parent_group_tag) \
s_tag_field CONCAT(tag_group_name, _fields)[]; \
s_tag_struct CONCAT(tag_group_name, _field_set) = { #tag_group_name"_block_struct", #tag_group_name"_block_struct", {0}, CONCAT(tag_group_name, _fields) }; \
s_tag_block CONCAT(tag_group_name, _block) = { #tag_group_name"_block", #tag_group_name"_block", __FILE__, __LINE__, 1, "1", CONCAT(tag_group_name, _field_set) }; \
s_tag_group CONCAT(tag_group_name, _group) = { #tag_group_name, group_tag, parent_group_tag, CONCAT(tag_group_name, _block), &CONCAT(parent_tag_group_name, _group) }; \
s_tag_field CONCAT(tag_group_name, _fields)[] =

#define TAG_BLOCK(tag_block_name, block_count) \
s_tag_field CONCAT(tag_block_name, _fields)[]; \
s_tag_struct CONCAT(tag_block_name, _field_set) = { #tag_block_name"_block_struct", #tag_block_name"_block_struct", {0}, CONCAT(tag_block_name, _fields) }; \
s_tag_block CONCAT(tag_block_name, _block) = { #tag_block_name"_block", #tag_block_name"_block", __FILE__, __LINE__, block_count, #block_count, CONCAT(tag_block_name, _field_set) }; \
s_tag_field CONCAT(tag_block_name, _fields)[] =

#define TAG_REFERENCE_DEFINITION(name, tag_group) \
s_tag_reference name = { 0, tag_group, 0 };

#define TAG_REFERENCE_DEFINITION_EX(name, tag_group) \
extern unsigned long CONCAT(name, _tag_groups)[]; \
s_tag_reference name = { 0, INVALID_TAG, CONCAT(name, _tag_groups) }; \
unsigned long CONCAT(name, _tag_groups)[] =
