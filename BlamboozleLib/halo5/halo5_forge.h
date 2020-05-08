#pragma once

static constexpr uint64_t h5_base_address = 0x0000000140000000;
//static constexpr uint64_t h5_tag_layout_table_address = 0x000000014477A2D0; // _build_halo5_forge_1_114_4592_2
// static constexpr uint32_t h5_num_tag_layouts = 284; // _build_halo5_forge_1_114_4592_2
static constexpr uint64_t h5_tag_layout_table_address = 0x0000000144756580; // _build_halo5_forge_1_194_6192_2
static constexpr uint32_t h5_num_tag_layouts = 285; // _build_halo5_forge_1_194_6192_2

// #TODO: More sophisticated addressing using sections
#define h5_va_to_pa(data, address) static_cast<DWORD>(address - h5_base_address)
#define h5_va_to_pointer(data, address) (address ? ((const char*)(data + h5_va_to_pa(data, address))) : 0)
#define h5_aa_to_pointer(data, address) ((char*)(address))
#define h5_pointer_to_va(data, pointer) (h5_base_address + static_cast<uintptr_t>((((char*)pointer) - ((char*)data))))


