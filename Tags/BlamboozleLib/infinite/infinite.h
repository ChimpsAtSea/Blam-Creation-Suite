#pragma once

static constexpr ptr64 infinite_base_address = 0x140000000;

extern ptr64 infinite_dump_base_address;
extern ptr64 infinite_tag_layout_table_address;
extern unsigned long infinite_num_tag_layouts;

#define inf_va_to_pa(address) ptr64(ptr64(address).value() - infinite_base_address.value())
#define inf_va_to_rva(address) ptr64(infinite_dump_base_address.value() + (ptr64(address).value() - infinite_base_address.value()))
const char* inf_va_to_pointer(const char* data, ptr64 address);
const char* inf_pa_to_pointer(const char* data, ptr64 address);

struct s_find_result
{
	const char* data;
	ptr64 address;
	unsigned long dump_rva;
};
bool inf_find_string(const char* data, const char* str, std::vector<s_find_result>& results);
bool inf_find_address(const char* data, ptr64 address, std::vector<s_find_result>& results);

#include "inf_field_type.h"

#include "inf_tag_string_list_definition.h"
#include "inf_tag_block_index_definition.h"
#include "inf_tag_data_definition.h"
#include "inf_tag_reference_definition.h"
#include "inf_tag_field.h"
#include "inf_tag_group_definition.h"
#include "inf_tag_block_definition.h"
#include "inf_tag_array_definition.h"
#include "inf_tag_struct_definition.h"
#include "inf_tag_resource_definition.h"

void inf_export_code(
	std::vector<c_inf_tag_group_definition*>& group_definitions,
	std::vector<c_inf_tag_block_definition*>& block_definitions,
	std::vector<c_inf_tag_array_definition*>& array_definitions,
	std::vector<c_inf_tag_resource_definition*>& resource_definitions,
	std::vector<c_inf_tag_struct_definition*>& struct_definitions);
std::string inf_convert_to_code_name(std::string name);