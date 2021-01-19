#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long POLYART_ASSET_TAG = 'paas';
	extern s_tag_group polyart_asset_group; // polyart_asset_block
	extern s_tag_block_definition polyart_asset_block;
	extern s_tag_struct_definition polyart_asset; // polyart_asset_block


	extern s_tag_block_definition polyartCameraBlock_block;
	extern s_tag_struct_definition polyartCameraBlock_block_struct_definition; // polyartCameraBlock_block

	extern s_tag_struct_definition polyartVertexBufferDescriptorStruct;
	extern s_tag_struct_definition polyartIndexBufferDescriptorStruct;

} // namespace macaque

} // namespace blofeld

