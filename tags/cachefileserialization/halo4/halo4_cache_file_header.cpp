#include "cachefileserialization-private-pch.h"

#ifdef BCS_BUILD_HIGH_LEVEL_HALO_4

template<> void byteswap_inplace(halo4::xbox360::s_cache_file_header& header)
{
	byteswap_inplace(header.header_signature);
	byteswap_inplace(header.file_version);
	byteswap_inplace(header.file_length);
	byteswap_inplace(header.file_compressed_length);
	byteswap_inplace(header.tags_header_address);
	byteswap_inplace(header.tag_buffer_offset);
	byteswap_inplace(header.total_tags_size);
	byteswap_inplace(header.source_file);
	byteswap_inplace(header.build);
	byteswap_inplace(header.scenario_type);
	byteswap_inplace(header.scenario_load_type);
	byteswap_inplace(header.unknown140);
	byteswap_inplace(header.tracked_build);
	byteswap_inplace(header.unknown142);
	byteswap_inplace(header.header_flags);
	byteswap_inplace(header.unknown144);
	byteswap_inplace(header.unknown148);
	byteswap_inplace(header.unknown14C);
	byteswap_inplace(header.unknown150);
	byteswap_inplace(header.unknown154);
	byteswap_inplace(header.string_id_index_buffer_count);
	byteswap_inplace(header.string_id_string_storage_size);
	byteswap_inplace(header.string_id_index_buffer_offset);
	byteswap_inplace(header.string_id_string_storage_offset);
	byteswap_inplace(header.shared_file_type_flags);
	byteswap_inplace(header.timestamp);
	byteswap_inplace(header.scenario_type_timestamps);
	byteswap_inplace(header.name);
	byteswap_inplace(header.unknown1AC);
	byteswap_inplace(header.relative_path);
	byteswap_inplace(header.minor_version);
	byteswap_inplace(header.file_count);
	byteswap_inplace(header.file_table_offset);
	byteswap_inplace(header.file_table_length);
	byteswap_inplace(header.file_table_indices_offset);
	byteswap_inplace(header.tag_remap_count);
	byteswap_inplace(header.tag_remap_address);
	byteswap_inplace(header.dlc_tag_remap_count);
	byteswap_inplace(header.dlc_tag_remap_address);
	byteswap_inplace(header.unknown2D4);
	byteswap_inplace(header.unknown2D8);
	byteswap_inplace(header.expected_base_address);
	byteswap_inplace(header.xdk_version);
	byteswap_inplace(header.tag_post_link_buffer);
	byteswap_inplace(header.tag_language_dependent_read_only_buffer);
	byteswap_inplace(header.tag_language_dependent_read_write_buffer);
	byteswap_inplace(header.tag_language_neutral_read_write_buffer);
	byteswap_inplace(header.tag_language_neutral_write_combined_buffer);
	byteswap_inplace(header.tag_language_neutral_read_only_buffer);
	byteswap_inplace(header.unknown330);
	byteswap_inplace(header.unknown334);
	byteswap_inplace(header.unknown338);
	byteswap_inplace(header.unknown33C);
	byteswap_inplace(header.hash);
	byteswap_inplace(header.rsa);
	byteswap_inplace(header.offset_masks);
	byteswap_inplace(header.section_file_bounds);
	byteswap_inplace(header.unknown4AC);
	byteswap_inplace(header.unknown4B0);
	byteswap_inplace(header.unknown4B4);
	byteswap_inplace(header.unknown4B8);
	//byteswap_inplace(header.gap4BC);
	byteswap_inplace(header.unknown18E94);
	byteswap_inplace(header.unknown18E95);
	byteswap_inplace(header.unknown18E96);
	byteswap_inplace(header.unknown18E97);
	byteswap_inplace(header.insertion_point_resource_usage);
	byteswap_inplace(header.gap1D728);
	byteswap_inplace(header.late_binding_tag_reference_fixup_info_count);
	byteswap_inplace(header.late_binding_tag_reference_fixup_info_address);
	byteswap_inplace(header.cache_file_fixups_count);
	byteswap_inplace(header.cache_file_fixups_address);
	byteswap_inplace(header.gap1D748);
	byteswap_inplace(header.footer_signature);
}

template<> void byteswap_inplace<halo4::xbox360::s_section>(halo4::xbox360::s_section& section)
{
	byteswap_inplace(section.count);
	byteswap_inplace(section.address);
}

template<> void byteswap_inplace<halo4::xbox360::s_cache_file_tag_group>(halo4::xbox360::s_cache_file_tag_group& tag_group)
{
	byteswap_inplace(tag_group.group_tags);
	byteswap_inplace(tag_group.name);
}

template<> void byteswap_inplace<halo4::xbox360::s_cache_file_tag_instance>(halo4::xbox360::s_cache_file_tag_instance& tag_instance)
{
	byteswap_inplace(tag_instance.group_index);
	byteswap_inplace(tag_instance.identifier);
	byteswap_inplace(tag_instance.address);
}

template<> void byteswap_inplace<halo4::xbox360::s_cache_file_tag_global_instance>(halo4::xbox360::s_cache_file_tag_global_instance& tag_global_instance)
{
	byteswap_inplace(tag_global_instance.group_tag);
	byteswap_inplace(tag_global_instance.datum_index);
}

template<> void byteswap_inplace<halo4::xbox360::s_cache_file_tag_interop>(halo4::xbox360::s_cache_file_tag_interop& tag_interop)
{
	byteswap_inplace(tag_interop.page_address);
	byteswap_inplace(tag_interop.type_index);
}

template<> void byteswap_inplace<halo4::xbox360::s_cache_file_tags_header>(halo4::xbox360::s_cache_file_tags_header& tags_header)
{
	byteswap_inplace(tags_header.tag_groups);
	byteswap_inplace(tags_header.tag_instances);
	byteswap_inplace(tags_header.global_tag_instances);
	byteswap_inplace(tags_header.tag_interop_table);
	byteswap_inplace(tags_header.unknown20);
	byteswap_inplace(tags_header.checksum);
	byteswap_inplace(tags_header.tags_signature);
}

uint32_t cache_file_get_absolute_maximum_size()
{
	return 0x7FFFFFFF;
}

bool shell_build_string_is_compatible(const char* build_string)
{
	return true; // #todo
}

bool halo4::xbox360::cache_file_header_verify(halo4::xbox360::s_cache_file_header& header)
{
	constexpr uint32_t k_tag_cache_minimum_address = 0xA0000000;
	constexpr uint32_t k_tag_cache_maximum_address = 0xBFC00000;

	if (header.header_signature != k_cache_header_signature)
	{
		console_write_line("does not have a valid header signature (is %08x, should be %08x)", header.header_signature, k_cache_header_signature);
		return false;
	}

	if (header.file_version != 12)
	{
		console_write_line("does not have a valid header signature (is %08x, should be %08x)", header.file_version, 12);
		return false;
	}

	if (header.footer_signature != k_cache_footer_signature)
	{
		console_write_line("does not have a valid footer signature (is %08x, should be %08x)", header.footer_signature, k_cache_footer_signature);
		return false;
	}

	if (header.xdk_version != 21119)
	{
		console_write_line("mismatch in xdk versions (cache file is %d, code is %d)", header.xdk_version, 21119);
		return false;
	}

	if (!shell_build_string_is_compatible(header.build.get_string()))
	{
		console_write_line("the cache file '%s' belongs to an incompatible build (%s)", header.name, header.build);
		return false;
	}

	return true;
}


#endif
