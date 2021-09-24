#pragma once

namespace blofeld
{



	extern s_tag_block_definition areas_block;
	extern s_tag_struct_definition areas_block_struct_definition; // areas_block
	extern s_tag_block_definition NavMeshAttachmentBlock_block;
	extern s_tag_struct_definition NavMeshAttachmentBlock_block_struct_definition; // NavMeshAttachmentBlock_block
	extern s_tag_block_definition flight_reference_block;
	extern s_tag_struct_definition flight_reference_block_struct_definition; // flight_reference_block
	extern s_tag_block_definition area_sector_point_block;
	extern s_tag_struct_definition area_sector_point_block_struct_definition; // area_sector_point_block
	extern s_tag_block_definition zone_block;
	extern s_tag_struct_definition zone_block_struct_definition; // zone_block

	extern s_tag_struct_definition area_cluster_occupancy_bitvector_array_struct_definition;
	extern s_tag_array_definition area_cluster_occupancy_bitvector_array;
	extern s_tag_struct_definition NavMeshAttachmentsStruct;

	extern s_string_list_definition area_flags;
	extern s_string_list_definition generate_flags;
	extern s_string_list_definition generate_preset_enum;
	extern s_string_list_definition zone_flags;



} // namespace blofeld

