#pragma once

namespace blofeld
{

	extern const char* lightRigLocation_strings[];
	extern s_string_list_definition lightRigLocation;

	constexpr unsigned long LIGHT_RIG_TAG = 'lrig';

	extern s_tag_group light_rig_group;

	extern s_tag_block_definition light_rig_block_block;
	extern s_tag_struct directionalLightRigBlock_block_struct;
	extern s_tag_block_definition directionalLightRigBlock_block;
	extern s_tag_struct scriptableLightRigBlock_block_struct;
	extern s_tag_block_definition scriptableLightRigBlock_block;

	extern s_tag_struct light_rig_struct_definition_struct_definition; // tag group

} // namespace blofeld

