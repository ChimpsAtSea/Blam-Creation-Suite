#pragma once

static constexpr ptr64 halo3_base_address = 0x140000000;

extern ptr64 halo3_dump_base_address;
extern ptr64 halo3_tag_layout_table_address;
extern unsigned long halo3_num_tag_layouts;

#define h3_va_to_pa(address) ptr64(ptr64(address).value() - halo3_base_address.value())
#define h3_va_to_rva(address) ptr64(halo3_dump_base_address.value() + (ptr64(address).value() - halo3_base_address.value()))
const char* h3_va_to_pointer(const char* data, ptr64 address);
const char* h3_pa_to_pointer(const char* data, ptr64 address);

struct s_h3_find_result
{
	const char* data;
	ptr64 address;
	unsigned long dump_rva;
};
bool h3_find_string(const char* data, const char* str, std::vector<s_h3_find_result>& results);
bool h3_find_address(const char* data, ptr64 address, std::vector<s_h3_find_result>& results);

#include "h3_field_type.h"

#include "h3_tag_string_list_definition.h"
#include "h3_tag_block_index_definition.h"
#include "h3_tag_data_definition.h"
#include "h3_tag_reference_definition.h"
#include "h3_tag_field.h"
#include "h3_tag_group_definition.h"
#include "h3_tag_block_definition.h"
#include "h3_tag_array_definition.h"
#include "h3_tag_data_definition.h"
#include "h3_tag_api_interop_definition.h"
#include "h3_tag_struct_definition.h"
#include "h3_tag_pageable_resource_definition.h"

void h3_export_code(
	std::vector<c_h3_tag_group_definition*>& group_definitions,
	std::vector<c_h3_tag_block_definition*>& block_definitions,
	std::vector<c_h3_tag_array_definition*>& array_definitions,
	std::vector<c_h3_tag_struct_definition*>& struct_definitions,
	std::vector<c_h3_tag_data_definition*>& data_definitions,
	std::vector<c_h3_tag_api_interop_definition*>& api_interop_definitions);
std::string h3_convert_to_code_name(std::string name);