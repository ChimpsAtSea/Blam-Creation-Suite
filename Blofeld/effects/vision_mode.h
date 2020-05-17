#pragma once

namespace blofeld
{

	extern const char* visionModeBipedTeamTypes_strings[];
	extern s_string_list_definition visionModeBipedTeamTypes;
	extern const char* visionModeBipedPassFlags_strings[];
	extern s_string_list_definition visionModeBipedPassFlags;
	extern const char* visionModeBipedPassesFlags_strings[];
	extern s_string_list_definition visionModeBipedPassesFlags;
	extern const char* visionModeFlags_strings[];
	extern s_string_list_definition visionModeFlags;

	constexpr unsigned long VISION_MODE_TAG = 'vmdx';

	extern s_tag_group vision_mode_group;

	extern s_tag_block_definition vision_mode_block_block;
	extern s_tag_struct visionModeScreenPassBlock_block_struct;
	extern s_tag_block_definition visionModeScreenPassBlock_block;
	extern s_tag_struct visionModeEnvironmentPassBlock_block_struct;
	extern s_tag_block_definition visionModeEnvironmentPassBlock_block;
	extern s_tag_struct visionModeBipedPassesBlock_block_struct;
	extern s_tag_block_definition visionModeBipedPassesBlock_block;
	extern s_tag_struct visionModeBipedPassBlock_block_struct;
	extern s_tag_block_definition visionModeBipedPassBlock_block;
	extern s_tag_struct visionModeBipedThreatBlock_block_struct;
	extern s_tag_block_definition visionModeBipedThreatBlock_block;
	extern s_tag_struct visionModeOrdnanceVehiclePassBlock_block_struct;
	extern s_tag_block_definition visionModeOrdnanceVehiclePassBlock_block;
	extern s_tag_struct visionModeOrdnanceVehicleTypeBlock_block_struct;
	extern s_tag_block_definition visionModeOrdnanceVehicleTypeBlock_block;
	extern s_tag_struct visionModeOrdnanceCrosshairBlock_block_struct;
	extern s_tag_block_definition visionModeOrdnanceCrosshairBlock_block;

	extern s_tag_struct vision_mode_struct_definition_struct_definition; // tag group

} // namespace blofeld

