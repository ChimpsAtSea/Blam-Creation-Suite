#pragma once

namespace blofeld
{

	extern const char* modelDissolveFlags_strings[];
	extern s_string_list_definition modelDissolveFlags;
	extern const char* modelDissolveParticleSpawnPosition_strings[];
	extern s_string_list_definition modelDissolveParticleSpawnPosition;

	constexpr unsigned long MODEL_DISSOLVE_DEFINITION_TAG = 'mdsv';

	extern s_tag_group model_dissolve_definition_group;

	extern s_tag_block_definition model_dissolve_definition_block_block;
	extern s_tag_struct modelDissolveDataBlock_block_struct;
	extern s_tag_block_definition modelDissolveDataBlock_block;
	extern s_tag_struct modelDissolvePerRegionTimeOffsetBlock_block_struct;
	extern s_tag_block_definition modelDissolvePerRegionTimeOffsetBlock_block;

	extern s_tag_struct model_dissolve_definition_struct_definition_struct_definition; // tag group

} // namespace blofeld

