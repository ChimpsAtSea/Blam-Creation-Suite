#pragma once

#define k_number_of_tag_resource_fixup_types_bits_v0 1

class c_tag_resource_fixup_v0
{
public:
	c_long_designator<k_number_of_tag_resource_fixup_types_bits_v0, 0> m_designator;
};

struct s_monolithic_resource_xsync_state_v0
{
	int32_t cache_location_offset;
	int32_t cache_location_size;
	int32_t control_data_size;
	int32_t control_fixup_count;
	int32_t unknown20; // type or interop_usage_count?
	c_tag_resource_fixup_v0 root_address;
};
static constexpr size_t k_monolithic_resource_xsync_state_v0_size = sizeof(s_monolithic_resource_xsync_state_v0);
static_assert(k_monolithic_resource_xsync_state_v0_size == 0x18);

struct s_monolithic_resource_xsync_state_v1
{
	int32_t cache_location_offset;
	int32_t cache_location_size;
	int32_t optional_location_offset;
	int32_t optional_location_size;
	int32_t control_data_size;
	int32_t control_fixup_count;
	int32_t unknown18; // unknown
	int32_t unknown1C; // unknown
	int32_t interop_usage_count;
	c_tag_resource_fixup root_address;
};
static constexpr size_t k_monolithic_resource_xsync_state_v1_size = sizeof(s_monolithic_resource_xsync_state_v1);
static_assert(k_monolithic_resource_xsync_state_v1_size == 0x28);

struct s_monolithic_resource_xsync_state_v2
{
	int32_t cache_location_offset;
	int32_t cache_location_size;
	int32_t optional_location_offset;
	int32_t optional_location_size;
	int32_t control_align_bits;
	int32_t control_data_size;
	int32_t control_fixup_count;
	int32_t interop_usage_count;
	c_tag_resource_fixup root_address;
};
static constexpr size_t k_monolithic_resource_xsync_state_v2_size = sizeof(s_monolithic_resource_xsync_state_v2);
static_assert(k_monolithic_resource_xsync_state_v2_size == 0x24);

class c_tag_resource_xsynced_chunk : public c_typed_chunk<'tgxc', false>
{
public:
	s_monolithic_resource_xsync_state_v2 resource_xsync_state_v2;
	
	BCS_SHARED c_tag_resource_xsynced_chunk(c_chunk& parent);
	BCS_SHARED ~c_tag_resource_xsynced_chunk();
	BCS_SHARED BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children) override final;
	BCS_SHARED virtual void log_impl(c_tag_file_string_debugger* string_debugger) const override;

	static void convert_paged_v0_to_monolithic_xsync_state_v2(const s_monolithic_resource_xsync_state_v0& v0, s_monolithic_resource_xsync_state_v2& v2);
	static void convert_streaming_v0_to_monolithic_xsync_state_v2(const s_monolithic_resource_xsync_state_v0& v0, s_monolithic_resource_xsync_state_v2& v2);
	static void convert_paged_v1_to_current_monolithic_xsync_state(const s_monolithic_resource_xsync_state_v1& v1, s_monolithic_resource_xsync_state_v2& v2);
};
