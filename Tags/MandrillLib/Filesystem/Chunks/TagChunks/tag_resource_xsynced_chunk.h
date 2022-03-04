#pragma once

#define k_number_of_tag_resource_fixup_types_bits_v0 1

class c_tag_resource_fixup_v0
{
public:
	c_long_designator<k_number_of_tag_resource_fixup_types_bits_v0, 0> m_designator;
};

struct s_monolithic_resource_xsync_state_v0
{
	long cache_location_offset;
	long cache_location_size;
	long control_data_size;
	long control_fixup_count;
	long unknown20; // type or interop_usage_count?
	c_tag_resource_fixup_v0 root_address;
};
static constexpr size_t k_monolithic_resource_xsync_state_v0_size = sizeof(s_monolithic_resource_xsync_state_v0);
static_assert(k_monolithic_resource_xsync_state_v0_size == 0x18);

struct s_monolithic_resource_xsync_state_v1
{
	long cache_location_offset;
	long cache_location_size;
	long optional_location_offset;
	long optional_location_size;
	long control_data_size;
	long control_fixup_count;
	long unknown18; // unknown
	long unknown1C; // unknown
	long interop_usage_count;
	c_tag_resource_fixup root_address;
};
static constexpr size_t k_monolithic_resource_xsync_state_v1_size = sizeof(s_monolithic_resource_xsync_state_v1);
static_assert(k_monolithic_resource_xsync_state_v1_size == 0x28);

struct s_monolithic_resource_xsync_state_v2
{
	long cache_location_offset;
	long cache_location_size;
	long optional_location_offset;
	long optional_location_size;
	long control_align_bits;
	long control_data_size;
	long control_fixup_count;
	long interop_usage_count;
	c_tag_resource_fixup root_address;
};
static constexpr size_t k_monolithic_resource_xsync_state_v2_size = sizeof(s_monolithic_resource_xsync_state_v2);
static_assert(k_monolithic_resource_xsync_state_v2_size == 0x24);

class c_tag_resource_xsynced_chunk : public c_typed_single_tag_file_reader_chunk<'tgxc'>
{
public:
	s_monolithic_resource_xsync_state_v2 resource_xsync_state_v2;
	
	c_tag_resource_xsynced_chunk(const void* chunk_data, c_chunk& parent, c_single_tag_file_reader& reader);
	~c_tag_resource_xsynced_chunk();
	virtual void log_impl(c_single_tag_file_layout_reader* layout_reader) const;

	static void convert_paged_v0_to_monolithic_xsync_state_v2(const s_monolithic_resource_xsync_state_v0& v0, s_monolithic_resource_xsync_state_v2& v2);
	static void convert_streaming_v0_to_monolithic_xsync_state_v2(const s_monolithic_resource_xsync_state_v0& v0, s_monolithic_resource_xsync_state_v2& v2);
	static void convert_paged_v1_to_current_monolithic_xsync_state(const s_monolithic_resource_xsync_state_v1& v1, s_monolithic_resource_xsync_state_v2& v2);
};
