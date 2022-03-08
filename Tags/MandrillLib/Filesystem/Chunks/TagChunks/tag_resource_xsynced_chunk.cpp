#include "mandrilllib-private-pch.h"

c_tag_resource_xsynced_chunk::c_tag_resource_xsynced_chunk(c_chunk& parent) :
	c_typed_chunk(&parent),
	resource_xsync_state_v2()
{
	debug_point;
}

c_tag_resource_xsynced_chunk::~c_tag_resource_xsynced_chunk()
{
}

BCS_RESULT c_tag_resource_xsynced_chunk::read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children)
{
	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = c_typed_chunk::read_chunk(userdata, data, use_read_only, parse_children)))
	{
		return rs;
	}

	unsigned long xsync_version = metadata;
	switch (xsync_version)
	{
	case 0:
	{
		throw; // #TODO: check for streaming using the resource definition, check flag (flag & 2)
		s_monolithic_resource_xsync_state_v0 resource_xsync_state_v0 = chunk_byteswap(*reinterpret_cast<const s_monolithic_resource_xsync_state_v0*>(get_chunk_data_start()));
		convert_paged_v0_to_monolithic_xsync_state_v2(resource_xsync_state_v0, resource_xsync_state_v2);
		break;
	}
	case 1:
	{
		s_monolithic_resource_xsync_state_v1 resource_xsync_state_v1 = chunk_byteswap(*reinterpret_cast<const s_monolithic_resource_xsync_state_v1*>(get_chunk_data_start()));
		convert_paged_v1_to_current_monolithic_xsync_state(resource_xsync_state_v1, resource_xsync_state_v2);
		break;
	}
	case 2:
	{
		resource_xsync_state_v2 = chunk_byteswap(*reinterpret_cast<const s_monolithic_resource_xsync_state_v2*>(get_chunk_data_start()));
		break;
	}
	default: FATAL_ERROR("Unsupported xsync version %lu", xsync_version);
	}

	return rs;
}

void c_tag_resource_xsynced_chunk::log_impl(c_tag_file_string_debugger* string_debugger) const
{
	e_tag_resource_fixup_type root_address_type = resource_xsync_state_v2.root_address.get_type();
	dword root_address_fixup_value = resource_xsync_state_v2.root_address.get_fixup_value();

	log_signature();
	log_pad(); console_write_line_verbose("\txsync_version:0x%08X", metadata);
	log_pad(); console_write_line_verbose("\tcache_location_offset:0x%08X", resource_xsync_state_v2.cache_location_offset);
	log_pad(); console_write_line_verbose("\toptional_location_offset:0x%08X", resource_xsync_state_v2.optional_location_offset);
	log_pad(); console_write_line_verbose("\toptional_location_offset:0x%08X", resource_xsync_state_v2.optional_location_offset);
	log_pad(); console_write_line_verbose("\toptional_location_size:0x%08X", resource_xsync_state_v2.optional_location_size);
	log_pad(); console_write_line_verbose("\tcontrol_align_bits:0x%08X", resource_xsync_state_v2.control_align_bits);
	log_pad(); console_write_line_verbose("\tcontrol_data_size:0x%08X", resource_xsync_state_v2.control_data_size);
	log_pad(); console_write_line_verbose("\tcontrol_fixup_count:0x%08X", resource_xsync_state_v2.control_fixup_count);
	log_pad(); console_write_line_verbose("\tinterop_usage_count:0x%08X", resource_xsync_state_v2.interop_usage_count);
	log_pad(); console_write_line_verbose("\troot_address:0x%08X 0x%08X", static_cast<dword>(root_address_type), root_address_fixup_value);

	if (root_address_type != _tag_resource_fixup_type_unknown1)
	{
		debug_point;
	}

	debug_point;
}

static c_tag_resource_fixup convert_v0_to_v2_fixup(const c_tag_resource_fixup_v0& v0)
{
	c_tag_resource_fixup v2;

	long v0_primary_index = v0.m_designator.get_primary_index();
	if (v0_primary_index)
	{
		long v0_secondary_index = v0.m_designator.get_secondary_index();
		e_tag_resource_fixup_type fixup_type = v0_secondary_index ? _tag_resource_fixup_type_unknown1 : _tag_resource_fixup_type_unknown2;
		v2.set_type(fixup_type);
		v2.set_fixup_value(v0_primary_index - 1);
	}

	return v2;
}

void c_tag_resource_xsynced_chunk::convert_paged_v0_to_monolithic_xsync_state_v2(const s_monolithic_resource_xsync_state_v0& v0, s_monolithic_resource_xsync_state_v2& v2)
{
	v2.cache_location_offset = v0.cache_location_offset;
	v2.cache_location_size = v0.cache_location_size;
	v2.optional_location_offset = 0;
	v2.optional_location_size = 0;
	v2.control_align_bits = 2;
	v2.control_data_size = v0.control_data_size;
	v2.control_fixup_count = v0.control_fixup_count;
	v2.root_address = convert_v0_to_v2_fixup(v0.root_address);
}

void c_tag_resource_xsynced_chunk::convert_streaming_v0_to_monolithic_xsync_state_v2(const s_monolithic_resource_xsync_state_v0& v0, s_monolithic_resource_xsync_state_v2& v2)
{
	v2.cache_location_offset = v0.cache_location_offset;
	v2.cache_location_size = v0.cache_location_size;
	v2.optional_location_offset = 0;
	v2.optional_location_size = 0;
	v2.control_align_bits = 2;
	v2.control_data_size = 0;
	v2.control_fixup_count = 0;
	v2.root_address = {};
}

void c_tag_resource_xsynced_chunk::convert_paged_v1_to_current_monolithic_xsync_state(const s_monolithic_resource_xsync_state_v1& v1, s_monolithic_resource_xsync_state_v2& v2)
{
	v2.cache_location_offset = v1.cache_location_offset;
	v2.cache_location_size = v1.cache_location_size;
	v2.optional_location_offset = v1.optional_location_offset;
	v2.optional_location_size = v1.optional_location_size;
	v2.control_align_bits = 2;
	v2.control_data_size = v1.control_data_size;
	v2.control_fixup_count = v1.control_fixup_count;
	v2.interop_usage_count = v1.interop_usage_count;
	v2.root_address = v1.root_address;
}

template<> void byteswap_inplace<c_tag_resource_fixup_v0>(c_tag_resource_fixup_v0& value)
{
	static_assert(sizeof(c_tag_resource_fixup_v0) == sizeof(unsigned long));
	byteswap_inplace(*reinterpret_cast<unsigned long*>(&value));
}

template<> void byteswap_inplace(s_monolithic_resource_xsync_state_v0& value)
{
	byteswap_inplace(value.cache_location_offset);
	byteswap_inplace(value.cache_location_size);
	byteswap_inplace(value.control_data_size);
	byteswap_inplace(value.control_fixup_count);
	byteswap_inplace(value.unknown20);
	byteswap_inplace(value.root_address);
}

template<> void byteswap_inplace(s_monolithic_resource_xsync_state_v1& value)
{
	byteswap_inplace(value.cache_location_offset);
	byteswap_inplace(value.cache_location_size);
	byteswap_inplace(value.optional_location_offset);
	byteswap_inplace(value.optional_location_size);
	byteswap_inplace(value.control_data_size);
	byteswap_inplace(value.control_fixup_count);
	byteswap_inplace(value.unknown18);
	byteswap_inplace(value.unknown1C);
	byteswap_inplace(value.interop_usage_count);
	byteswap_inplace(value.root_address);
}

template<> void byteswap_inplace(s_monolithic_resource_xsync_state_v2& value)
{
	byteswap_inplace(value.cache_location_offset);
	byteswap_inplace(value.cache_location_size);
	byteswap_inplace(value.optional_location_offset);
	byteswap_inplace(value.optional_location_size);
	byteswap_inplace(value.control_align_bits);
	byteswap_inplace(value.control_data_size);
	byteswap_inplace(value.control_fixup_count);
	byteswap_inplace(value.interop_usage_count);
	byteswap_inplace(value.root_address);
}
