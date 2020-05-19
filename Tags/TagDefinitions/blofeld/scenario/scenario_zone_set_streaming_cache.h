#pragma once

namespace blofeld
{

	constexpr unsigned long STREAMINGZONESET_TAG = 'SDzs';

	extern s_tag_group streamingzoneset_group;

	extern s_tag_struct_definition StreamingZoneSetResourceIdBlock_block_struct;
	extern s_tag_block_definition StreamingZoneSetResourceIdBlock_block;
	extern s_tag_struct_definition StreamingZoneSetResourceLevelsBlock_block_struct;
	extern s_tag_block_definition StreamingZoneSetResourceLevelsBlock_block;
	extern s_tag_struct_definition StreamingZoneSetResourceSubregionDataBlock_block_struct;
	extern s_tag_block_definition StreamingZoneSetResourceSubregionDataBlock_block;
	extern s_tag_block_definition streamingzoneset_block_block;

	extern s_tag_struct_definition streamingzoneset_struct_definition_struct_definition; // tag group

} // namespace blofeld

