#pragma once

static constexpr ptr32 halo2_base_address = 0x400000;
static constexpr ptr32 halo2_dump_base_address = 0x400000; // #TODO: get this dynamically?
static constexpr ptr32 halo2_tag_layout_table_address = 0x00901B90;
static constexpr unsigned long halo2_num_tag_layouts = 120;

#define h2_va_to_pa(address) (ptr32(address).value() - halo2_base_address.value())
#define h2_va_to_rva(address) ptr32(halo2_dump_base_address.value() + h2_va_to_pa(address))
const char* h2_va_to_pointer_with_external_string(const char* data, ptr32 address);
const char* h2_va_to_pointer(const char* data, ptr32 address);
const char* h2_pa_to_pointer(const char* data, ptr32 address);

#include "h2_field_type.h"
#include "h2_pseudo_field_type.h"

#include "h2_pseudo_array_definition.h"
#include "h2_pseudo_struct_definition.h"
#include "h2_pseudo_field_definition.h"

#include "h2_tag_string_list_definition.h"
#include "h2_tag_block_index_definition.h"
#include "h2_tag_data_definition.h"
#include "h2_tag_reference_definition.h"
#include "h2_tag_group_definition.h"
#include "h2_tag_block_definition.h"

void h2_export_code(
	std::vector<c_h2_tag_group_definition*>& group_definitions,
	std::vector<c_h2_tag_block_definition*>& block_definitions,
	std::vector<c_h2_pseudo_struct_definition*>& struct_definitions);
std::string h2_convert_to_code_name(std::string name);