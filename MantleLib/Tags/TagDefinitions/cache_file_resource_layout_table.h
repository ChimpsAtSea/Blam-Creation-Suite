#pragma once

struct nicename("cache_file_resource_layout_table") tag_group('play') s_cache_file_resource_layout_table_definition
{
	struct nicename("Compression Codecs") s_compression_codecs_definition
	{
		signed char nicename("Guid") guid[16];
	};

	struct nicename("External Cache References") s_external_cache_references_definition
	{
		char nicename("Map Path") map_path[256];
		int16_t __unknown0;
		int16_t __unknown1;
		Undefined32 __unknown2;
	};

	struct nicename("Raw Pages") s_raw_pages_definition
	{
		int16_t nicename("Salt") salt;
		int8_t nicename("Flags") flags;
		int8_t nicename("Compression Codec Index") compression_codec_index;
		int16_t nicename("Shared Cache Index") shared_cache_index;
		int16_t __unknown0;
		// Blocks : Blocks are stored in the raw table, at the beginning of the map, and compressed using deflate.
		uint32_t nicename("Block Offset") block_offset;
		uint32_t nicename("Compressed Block Size") compressed_block_size;
		uint32_t nicename("Uncompressed Block Size") uncompressed_block_size;
		int32_t nicename("CRC Checksum") crc_checksum;
		signed char nicename("Entire Buffer Hash") entire_buffer_hash[20];
		signed char nicename("First Chunk Hash") first_chunk_hash[20];
		signed char nicename("Last Chunk Hash") last_chunk_hash[20];
		int16_t nicename("Block Asset Count") block_asset_count;
		int16_t __unknown1;
	};

	struct nicename("Sizes") s_sizes_definition
	{
		struct nicename("Parts") s_parts_definition
		{
			int32_t __unknown0;
			int32_t nicename("Size") size;
		};

		int32_t nicename("Overall Size") overall_size;
		s_tag_block_definition<s_parts_definition> nicename("Parts") parts_block;
	};

	struct nicename("Unknown") s_unknown_definition
	{
		int32_t __unknown0;
		int32_t __unknown1;
		int32_t __unknown2;
	};

	struct nicename("Segments") s_segments_definition
	{
		int16_t nicename("Primary Page Index") primary_page_index;
		int16_t nicename("Secondary Page Index") secondary_page_index;
		int32_t nicename("Primary Segment Offset") primary_segment_offset;
		int32_t nicename("Secondary Segment Offset") secondary_segment_offset;
		int16_t nicename("Primary Size Index") primary_size_index;
		int16_t nicename("Secondary Size Index") secondary_size_index;
	};

	s_tag_block_definition<s_compression_codecs_definition> nicename("Compression Codecs") compression_codecs_block;
	s_tag_block_definition<s_external_cache_references_definition> nicename("External Cache References") external_cache_references_block;
	s_tag_block_definition<s_raw_pages_definition> nicename("Raw Pages") raw_pages_block;
	s_tag_block_definition<s_sizes_definition> nicename("Sizes") sizes_block;
	s_tag_block_definition<s_unknown_definition> __unknown0;
	s_tag_block_definition<s_segments_definition> nicename("Segments") segments_block;
};

