#include "mandrilllib-private-pch.h"

template<> void byteswap<halo4::xbox360::s_cache_file_header>(halo4::xbox360::s_cache_file_header& header)
{
	byteswap<::s_cache_file_header>(header);

	byteswap(header.header_signature);
	byteswap(header.file_version);
	byteswap(header.file_length);
	byteswap(header.file_compressed_length);
	byteswap(header.tags_header_address);
	byteswap(header.tag_buffer_offset);
	byteswap(header.total_tags_size);
	byteswap(header.source_file);
	byteswap(header.build);
	byteswap(header.scenario_type);
	byteswap(header.scenario_load_type);
	byteswap(header.unknown140);
	byteswap(header.tracked_build);
	byteswap(header.unknown142);
	byteswap(header.header_flags);
	byteswap(header.unknown144);
	byteswap(header.unknown148);
	byteswap(header.unknown14C);
	byteswap(header.unknown150);
	byteswap(header.unknown154);
	byteswap(header.string_id_index_buffer_count);
	byteswap(header.string_id_string_storage_size);
	byteswap(header.string_id_index_buffer_offset);
	byteswap(header.string_id_string_storage_offset);
	byteswap(header.shared_file_type_flags);
	byteswap(header.timestamp);
	byteswap(header.scenario_type_timestamps);
	byteswap(header.name);
	byteswap(header.unknown1AC);
	byteswap(header.relative_path);
	byteswap(header.minor_version);
	byteswap(header.file_count);
	byteswap(header.file_table_offset);
	byteswap(header.file_table_length);
	byteswap(header.file_table_indices_offset);
	byteswap(header.tag_remap_count);
	byteswap(header.tag_remap_address);
	byteswap(header.dlc_tag_remap_count);
	byteswap(header.dlc_tag_remap_address);
	byteswap(header.unknown2D4);
	byteswap(header.unknown2D8);
	byteswap(header.expected_base_address);
	byteswap(header.xdk_version);
	byteswap(header.tag_post_link_buffer);
	byteswap(header.tag_language_dependent_read_only_buffer);
	byteswap(header.tag_language_dependent_read_write_buffer);
	byteswap(header.tag_language_neutral_read_write_buffer);
	byteswap(header.tag_language_neutral_write_combined_buffer);
	byteswap(header.tag_language_neutral_read_only_buffer);
	byteswap(header.unknown330);
	byteswap(header.unknown334);
	byteswap(header.unknown338);
	byteswap(header.unknown33C);
	byteswap(header.hash);
	byteswap(header.rsa);
	byteswap(header.offset_masks);
	byteswap(header.section_file_bounds);
	byteswap(header.unknown4AC);
	byteswap(header.unknown4B0);
	byteswap(header.unknown4B4);
	byteswap(header.unknown4B8);
	//byteswap(header.gap4BC);
	byteswap(header.unknown18E94);
	byteswap(header.unknown18E95);
	byteswap(header.unknown18E96);
	byteswap(header.unknown18E97);
	byteswap(header.insertion_point_resource_usage);
	byteswap(header.gap1D728);
	byteswap(header.late_binding_tag_reference_fixup_info_count);
	byteswap(header.late_binding_tag_reference_fixup_info_address);
	byteswap(header.cache_file_fixups_count);
	byteswap(header.cache_file_fixups_address);
	byteswap(header.gap1D748);
	byteswap(header.footer_signature);
}

template<> void byteswap<halo4::xbox360::s_section>(halo4::xbox360::s_section& section)
{
	byteswap(section.count);
	byteswap(section.address);
}

template<> void byteswap<halo4::xbox360::s_cache_file_tag_group>(halo4::xbox360::s_cache_file_tag_group& tag_group)
{
	byteswap(tag_group.group_tags);
	byteswap(tag_group.name);
}

template<> void byteswap<halo4::xbox360::s_cache_file_tag_instance>(halo4::xbox360::s_cache_file_tag_instance& tag_instance)
{
	byteswap(tag_instance.group_index);
	byteswap(tag_instance.identifier);
	byteswap(tag_instance.address);
}

template<> void byteswap<halo4::xbox360::s_cache_file_tag_global_instance>(halo4::xbox360::s_cache_file_tag_global_instance& tag_global_instance)
{
	byteswap(tag_global_instance.group_tag);
	byteswap(tag_global_instance.datum_index);
}

template<> void byteswap<halo4::xbox360::s_cache_file_tag_interop>(halo4::xbox360::s_cache_file_tag_interop& tag_interop)
{
	byteswap(tag_interop.page_address);
	byteswap(tag_interop.type_index);
}

template<> void byteswap<halo4::xbox360::s_cache_file_tags_header>(halo4::xbox360::s_cache_file_tags_header& tags_header)
{
	byteswap(tags_header.tag_groups);
	byteswap(tags_header.tag_instances);
	byteswap(tags_header.global_tag_instances);
	byteswap(tags_header.tag_interop_table);
	byteswap(tags_header.unknown20);
	byteswap(tags_header.checksum);
	byteswap(tags_header.tags_signature);
}

unsigned long cache_file_get_absolute_maximum_size()
{
	return 0x7FFFFFFF;
}

bool shell_build_string_is_compatible(const char* build_string)
{
	return true; // #todo
}

bool halo4::xbox360::cache_file_header_verify(halo4::xbox360::s_cache_file_header& header)
{
	constexpr unsigned long k_tag_cache_minimum_address = 0xA0000000;
	constexpr unsigned long k_tag_cache_maximum_address = 0xBFC00000;

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
