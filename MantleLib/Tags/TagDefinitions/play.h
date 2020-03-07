#pragma once

struct nicename("Play") group('play') s_play_definition
{
	struct nicename("Compression Codecs") s_compression_codec_block_definition;
	struct nicename("External Cache References") s_external_cache_reference_block_definition;
	struct nicename("Raw Pages") s_raw_page_block_definition;
	struct nicename("Sizes") s_size_block_definition;
	struct s_unknown_block_definition;
	struct nicename("Segments") s_segment_block_definition;

	s_tag_block_definition<s_compression_codec_block_definition> nicename("Compression Codecs") compression_codecs_block; 
	s_tag_block_definition<s_external_cache_reference_block_definition> nicename("External Cache References") external_cache_references_block; 
	s_tag_block_definition<s_raw_page_block_definition> nicename("Raw Pages") raw_pages_block; 
	s_tag_block_definition<s_size_block_definition> nicename("Sizes") sizes_block; 
	s_tag_block_definition<s_unknown_block_definition> __unknown_block; 
	s_tag_block_definition<s_segment_block_definition> nicename("Segments") segments_block; 

	struct nicename("compression_codec") s_compression_codec_block_definition
	{
		uint8_t nicename("Guid") guid[16];
	};

	struct nicename("external_cache_reference") s_external_cache_reference_block_definition
	{
		char nicename("Map Path") map_path[256];
		int16_t __unknown; 
		int16_t __unknown2; 
		Undefined32 __unknown3; 
	};

	struct nicename("raw_page") s_raw_page_block_definition
	{
		int16_t nicename("Salt") salt; 
		int8_t nicename("Flags") flags; 
		int8_t nicename("Compression Codec Index") compression_codec_index; 
		int16_t nicename("Shared Cache Index") shared_cache_index; 
		int16_t __unknown; 
		// comment
		uint32_t nicename("Block Offset") block_offset; 
		uint32_t nicename("Compressed Block Size") compressed_block_size; 
		uint32_t nicename("Uncompressed Block Size") uncompressed_block_size; 
		int32_t nicename("CRC Checksum") crc_checksum; 
		uint8_t nicename("Entire Buffer Hash") entire_buffer_hash[20];
		uint8_t nicename("First Chunk Hash") first_chunk_hash[20];
		uint8_t nicename("Last Chunk Hash") last_chunk_hash[20];
		int16_t nicename("Block Asset Count") block_asset_count; 
		int16_t __unknown2; 
	};

	struct nicename("size") s_size_block_definition
	{
		struct nicename("Parts") s_part_block_definition;

		int32_t nicename("Overall Size") overall_size; 
		s_tag_block_definition<s_part_block_definition> nicename("Parts") parts_block; 

		struct nicename("part") s_part_block_definition
		{
			int32_t __unknown; 
			int32_t nicename("Size") size; 
		};
	};

	struct s_unknown_block_definition
	{
		int32_t __unknown; 
		int32_t __unknown2; 
		int32_t __unknown3; 
	};

	struct nicename("segment") s_segment_block_definition
	{
		uint16_t nicename("Primary Page Index") primary_page_index; 
		uint16_t nicename("Secondary Page Index") secondary_page_index; 
		int32_t nicename("Primary Segment Offset") primary_segment_offset; 
		int32_t nicename("Secondary Segment Offset") secondary_segment_offset; 
		int16_t nicename("Primary Size Index") primary_size_index; 
		int16_t nicename("Secondary Size Index") secondary_size_index; 
	};
};
