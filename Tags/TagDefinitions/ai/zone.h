#pragma once

namespace blofeld
{

	extern s_tag_struct_definition NavMeshAttachmentBlock_block_struct;
	extern s_tag_block_definition NavMeshAttachmentBlock_block;
	extern s_tag_struct_definition flight_reference_block_block_struct;
	extern s_tag_block_definition flight_reference_block_block;
	extern s_tag_struct_definition area_sector_point_block_block_struct;
	extern s_tag_block_definition area_sector_point_block_block;
	extern s_tag_struct_definition areas_block_block_struct;
	extern s_tag_block_definition areas_block_block;
	extern s_tag_struct_definition zone_block_block_struct;
	extern s_tag_block_definition zone_block_block;

	extern s_tag_struct_definition area_cluster_occupancy_bitvector_array_struct_definition;
	extern s_tag_array_definition area_cluster_occupancy_bitvector_array_array;
	extern s_tag_struct_definition NavMeshAttachmentsStruct_struct_definition;

	extern const char* area_flags_strings[];
	extern s_string_list_definition area_flags;
	extern const char* generate_flags_strings[];
	extern s_string_list_definition generate_flags;
	extern const char* generate_preset_enum_strings[];
	extern s_string_list_definition generate_preset_enum;
	extern const char* zone_flags_strings[];
	extern s_string_list_definition zone_flags;

} // namespace blofeld

