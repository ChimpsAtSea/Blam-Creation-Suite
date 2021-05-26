#pragma once

namespace blofeld
{



	constexpr unsigned long LIGHT_RIG_TAG = 'lrig';
	extern s_tag_group light_rig_group; // light_rig_block


	extern s_tag_block_definition light_rig_block;
	extern s_tag_block_definition directionalLightRigBlock_block;
	extern s_tag_struct_definition directionalLightRigBlock_block_struct_definition; // directionalLightRigBlock_block
	extern s_tag_block_definition scriptableLightRigBlock_block;
	extern s_tag_struct_definition scriptableLightRigBlock_block_struct_definition; // scriptableLightRigBlock_block

	extern s_tag_struct_definition light_rig_struct_definition; // tag group

	extern c_versioned_string_list lightRigLocation_strings;
	extern s_string_list_definition lightRigLocation;

	extern s_tag_reference_definition global_midnight_light_definition_reference;
	extern s_tag_reference_definition global_lightRig_reference;



} // namespace blofeld

