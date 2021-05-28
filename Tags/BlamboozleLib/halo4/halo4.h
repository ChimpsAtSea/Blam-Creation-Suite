#pragma once

static constexpr uint64_t h4_base_address = 0x82000600;
static constexpr unsigned long h4_tag_layout_table_address = 0x859D8350;
static constexpr unsigned long h4_num_tag_layouts = 262;


const IMAGE_SECTION_HEADER* relative_virtual_address_to_section(DWORD relative_virtual_address, const char* raw_image_data);
DWORD relative_virtual_address_to_relative_raw_address(DWORD relative_virtual_address, const char* raw_image_data);

//// #TODO: More sophisticated addressing using sections
//#define __h4_va_to_pa(data, address) static_cast<DWORD>(address - h4_base_address)
//#define __h4_va_to_pointer(data, address) (address ? ((const char*)(data + h4_va_to_pa(data, address))) : 0)
//#define __h4_aa_to_pointer(data, address) ((char*)(address))
//#define __h4_pointer_to_va(data, pointer) (h4_base_address + static_cast<uintptr_t>((((char*)pointer) - ((char*)data))))
//
////#define h4_va_to_pa(data, address) static_cast<unsigned long>(address) - h4_base_address
////#define h4_va_to_pointer(data, address) (data + h4_va_to_pa(data, address))
//
//
//inline unsigned long h4_va_to_pa(const char* data, unsigned long address)
//{
//	DWORD result = relative_virtual_address_to_relative_raw_address(address - h4_base_address, data, true);
//	return result;
//}

const char* h4_va_to_pointer2(const char* data, unsigned long address);
inline const char* h4_va_to_pointer(const char* data, unsigned long address)
{
	if (address == 0) return 0;
	unsigned long new_address = address;
	const char* result = h4_va_to_pointer2(data, new_address);
	ASSERT(result);
	return result;
}
inline const char* h4_va_to_pointer_safe(const char* data, unsigned long address)
{
	if (address == 0) return 0;
	unsigned long new_address = address;
	const char* result = h4_va_to_pointer2(data, new_address);
	return result;
}
template<typename T>
inline const T* h4_va_to_pointer(const char* data, unsigned long address)
{
	return reinterpret_cast<const T*>(h4_va_to_pointer(data, address));
}
template<typename T>
inline const T* h4_va_to_pointer_safe(const char* data, unsigned long address)
{
	return reinterpret_cast<const T*>(h4_va_to_pointer_safe(data, address));
}
//inline const char* h4_va_to_pointer(const char* data, unsigned long address)
//{
//	if (address == 0) return nullptr;
//	unsigned long pa = h4_va_to_pa(data, address);
//	ASSERT(pa != ~DWORD());
//	return data + pa;
//}

//inline const char* h4_va_to_pointer_safe(const char* data, unsigned long address)
//{
//	if (address == 0) return nullptr;
//	unsigned long pa = h4_va_to_pa(data, address);
//	if (pa != ~DWORD())
//	{
//		return data + pa;
//	}
//	return nullptr;
//}



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
