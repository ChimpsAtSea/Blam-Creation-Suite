#pragma once

namespace blofeld
{

	extern const char* area_flags_strings[];
	extern s_string_list_definition area_flags;
	extern const char* generate_flags_strings[];
	extern s_string_list_definition generate_flags;
	extern const char* generate_preset_enum_strings[];
	extern s_string_list_definition generate_preset_enum;
	extern const char* zone_flags_strings[];
	extern s_string_list_definition zone_flags;


	extern s_tag_struct zone_block_block_struct;
	extern s_tag_block_definition zone_block_block;
	extern s_tag_struct areas_block_block_struct;
	extern s_tag_block_definition areas_block_block;
	extern s_tag_struct NavMeshAttachmentBlock_block_struct;
	extern s_tag_block_definition NavMeshAttachmentBlock_block;
	extern s_tag_struct flight_reference_block_block_struct;
	extern s_tag_block_definition flight_reference_block_block;
	extern s_tag_struct area_sector_point_block_block_struct;
	extern s_tag_block_definition area_sector_point_block_block;

	extern s_tag_struct NavMeshAttachmentsStruct_struct_definition;

} // namespace blofeld

