#pragma once

namespace blofeld
{



	constexpr unsigned long EMBLEM_LIBRARY_TAG = 'mlib';
	extern s_tag_group emblem_library_group; // emblem_library_block


	extern s_tag_block_definition emblem_library_block;
	extern s_tag_block_definition emblem_bitmap_list_block;
	extern s_tag_struct_definition emblem_bitmap_list_block_struct_definition; // emblem_bitmap_list_block
	extern s_tag_block_definition emblem_shape_list_block;
	extern s_tag_struct_definition emblem_shape_list_block_struct_definition; // emblem_shape_list_block
	extern s_tag_block_definition emblem_front_list_block;
	extern s_tag_struct_definition emblem_front_list_block_struct_definition; // emblem_front_list_block
	extern s_tag_block_definition emblem_back_list_block;
	extern s_tag_struct_definition emblem_back_list_block_struct_definition; // emblem_back_list_block
	extern s_tag_block_definition emblem_runtime_front_list_block;
	extern s_tag_struct_definition emblem_runtime_front_list_block_struct_definition; // emblem_runtime_front_list_block
	extern s_tag_block_definition emblem_runtime_back_list_block;
	extern s_tag_struct_definition emblem_runtime_back_list_block_struct_definition; // emblem_runtime_back_list_block

	extern s_tag_struct_definition emblem_library_struct_definition; // tag group
	extern s_tag_struct_definition emblem_transform;
	extern s_tag_struct_definition emblem_layer;

	extern c_versioned_string_list front_emblem_primary_layer_strings;
	extern s_string_list_definition front_emblem_primary_layer;

	extern s_tag_reference_definition global_emblem_library_parameters_reference;



} // namespace blofeld

