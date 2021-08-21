#pragma once

static constexpr uint64_t h4_base_address = 0x82000600;
static constexpr unsigned long h4_tag_layout_table_address = 0x859D8350;
static constexpr unsigned long h4_num_tag_layouts = 262;


const IMAGE_SECTION_HEADER* relative_virtual_address_to_section(DWORD relative_virtual_address, const char* raw_image_data);
DWORD relative_virtual_address_to_relative_raw_address(DWORD relative_virtual_address, const char* raw_image_data);

const char* h4_va_to_pointer2(const char* data, unsigned long address);
const char* h4_va_to_pointer(const char* data, bptr32 address);

template<typename T>
inline const T* h4_va_to_pointer(const char* data, bptr32 address)
{
	return reinterpret_cast<const T*>(h4_va_to_pointer(data, address));
}

#include "halo4/h4_field_type.h"
#include "halo4/source_tree.h"
#include "halo4/h4_tag_enum.h"
#include "halo4/h4_tag_reference.h"
#include "halo4/h4_tag_struct.h"
#include "halo4/h4_tag_field.h"
#include "halo4/h4_tag_block.h"
#include "halo4/h4_tag_group.h"
#include "halo4/h4_tag_interop.h"
#include "halo4/h4_tag_resource.h"
#include "halo4/h4_generator_preprocessor.h"
#include "halo4/h4_source_generator.h"
