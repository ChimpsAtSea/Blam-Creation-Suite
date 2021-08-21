#pragma once

static constexpr ptr32 halo1_base_address = 0x400000;
static constexpr ptr32 halo1_tag_layout_table_address = 0x009B8D88;
static constexpr unsigned long halo1_num_tag_layouts = 83;

// #TODO: More sophistocated addressing using sections
#define h1_va_to_pa(address) (ptr32(address).value() - halo1_base_address.value())
#define h1_va_to_pointer(data, address) (ptr32(address).value() ? ((const char*)(data + h1_va_to_pa(address))) : 0)

#include "h1_field_type.h"
#include "h1_pseudo_field_type.h"

#include "h1_pseudo_array_definition.h"
#include "h1_pseudo_struct_definition.h"
#include "h1_pseudo_field_definition.h"

#include "h1_tag_string_list_definition.h"
#include "h1_tag_block_index_definition.h"
#include "h1_tag_data_definition.h"
#include "h1_tag_reference_definition.h"
#include "h1_tag_field.h"
#include "h1_tag_group_definition.h"
#include "h1_tag_block_definition.h"

void h1_export_code(std::vector<c_h1_tag_group_definition*>& tag_layouts);
std::string h1_convert_to_code_name(std::string name);