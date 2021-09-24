#pragma once

namespace blofeld
{



	constexpr unsigned long MODEL_DISSOLVE_DEFINITION_TAG = 'mdsv';
	extern s_tag_group model_dissolve_definition_group; // model_dissolve_definition_block


	extern s_tag_block_definition model_dissolve_definition_block;
	extern s_tag_block_definition modelDissolveDataBlock_block;
	extern s_tag_struct_definition modelDissolveDataBlock_block_struct_definition; // modelDissolveDataBlock_block
	extern s_tag_block_definition modelDissolvePerRegionTimeOffsetBlock_block;
	extern s_tag_struct_definition modelDissolvePerRegionTimeOffsetBlock_block_struct_definition; // modelDissolvePerRegionTimeOffsetBlock_block

	extern s_tag_struct_definition model_dissolve_definition_struct_definition; // tag group

	extern s_string_list_definition modelDissolveFlags;
	extern s_string_list_definition modelDissolveParticleSpawnPosition;




} // namespace blofeld

