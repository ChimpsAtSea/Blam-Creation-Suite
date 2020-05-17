#pragma once

namespace blofeld
{

	constexpr unsigned long EMBLEM_LIBRARY_TAG = 'mlib';

	extern s_tag_group emblem_library_group;

	extern s_tag_struct_definition emblem_bitmap_list_block_struct;
	extern s_tag_block_definition emblem_bitmap_list_block;
	extern s_tag_struct_definition emblem_shape_list_block_struct;
	extern s_tag_block_definition emblem_shape_list_block;
	extern s_tag_struct_definition emblem_front_list_block_struct;
	extern s_tag_block_definition emblem_front_list_block;
	extern s_tag_struct_definition emblem_back_list_block_struct;
	extern s_tag_block_definition emblem_back_list_block;
	extern s_tag_struct_definition emblem_runtime_front_list_block_struct;
	extern s_tag_block_definition emblem_runtime_front_list_block;
	extern s_tag_struct_definition emblem_runtime_back_list_block_struct;
	extern s_tag_block_definition emblem_runtime_back_list_block;
	extern s_tag_block_definition emblem_library_block_block;


	extern s_tag_struct_definition emblem_library_struct_definition_struct_definition; // tag group
	extern s_tag_struct_definition emblem_transform_struct_definition;
	extern s_tag_struct_definition emblem_layer_struct_definition;

	extern const char* front_emblem_primary_layer_strings[];
	extern s_string_list_definition front_emblem_primary_layer;

} // namespace blofeld

