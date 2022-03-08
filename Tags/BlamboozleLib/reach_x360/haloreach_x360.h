#pragma once

static constexpr ptr32 haloreach_base_address = 0x82000000;

extern ptr32 haloreach_dump_base_address;
extern ptr32 haloreach_tag_layout_table_address;
extern unsigned long haloreach_num_tag_layouts;

#define reach_x360_va_to_pa(address) ptr32(ptr32(address).value() - haloreach_base_address.value())
#define reach_x360_va_to_rva(address) ptr32(haloreach_dump_base_address.value() + (ptr32(address).value() - haloreach_base_address.value()))
const char* reach_x360_va_to_pointer(const char* data, ptr32 address);
const char* reach_x360_pa_to_pointer(const char* data, ptr32 address);

struct s_reach_x360_find_result
{
	const char* data;
	ptr32 address;
	unsigned long dump_rva;
};
bool reach_x360_find_string(const char* data, const char* str, std::vector<s_reach_x360_find_result>& results);
bool reach_x360_find_address(const char* data, ptr32 address, std::vector<s_reach_x360_find_result>& results);

#include "reach_field_type.h"

#include "reach_tag_string_list_definition.h"
#include "reach_tag_block_index_definition.h"
#include "reach_tag_data_definition.h"
#include "reach_tag_reference_definition.h"
#include "reach_tag_field.h"
#include "reach_tag_group_definition.h"
#include "reach_tag_block_definition.h"
#include "reach_tag_array_definition.h"
#include "reach_tag_data_definition.h"
#include "reach_tag_api_interop_definition.h"
#include "reach_tag_struct_definition.h"
#include "reach_tag_resource_definition.h"

void reach_x360_export_code(
	std::vector<c_reach_x360_tag_group_definition*>& group_definitions,
	std::vector<c_reach_x360_tag_block_definition*>& block_definitions,
	std::vector<c_reach_x360_tag_array_definition*>& array_definitions,
	std::vector<c_reach_x360_tag_struct_definition*>& struct_definitions,
	std::vector<c_reach_x360_tag_data_definition*>& data_definitions,
	std::vector<c_reach_x360_tag_resource_definition*>& resource_definitions,
	std::vector<c_reach_x360_tag_api_interop_definition*>& api_interop_definitions);
std::string reach_x360_convert_to_code_name(std::string name);